/**
 * 
 * Code to convert node tree to Javascript...
 * 
 * usage : x = (new JsRender.NodeToJs(node)).munge();
 * 
 *
 *  We are changing this to output as we go.
 *   However... since line-endings on properties have ',' (not ;) like vala.
 *           we have to be a bit smarter about how to output.
 *
 *   
 *
*/




public class JsRender.NodeToJs : Object {

	static uint indent = 1;
	static string indent_str = " ";
	
	
	
	Node node;
	Gee.ArrayList<string>  doubleStringProps;  // need to think if this is a good idea like this
	string pad;
	public JsRender renderer;
	  
	Gee.HashMap<string,string> 				out_props;
	Gee.HashMap<string,string> 				out_listeners;	
	Gee.HashMap<string,Node> 				out_nodeprops;
	Gee.ArrayList<Node> 					out_children;
	Gee.HashMap<string,Gee.ArrayList<Node>> out_props_array;
	Gee.HashMap<string,Gee.ArrayList<string>> out_props_array_plain;	
	
	NodeToJs top;
	public string ret;
	
	public int cur_line;

	
	public NodeToJs( Node node, Gee.ArrayList<string> doubleStringProps, string pad, NodeToJs? parent) 
	{
		this.node = node;
		this.doubleStringProps = doubleStringProps;
		this.pad = pad;
		
		//this.els = new Gee.ArrayList<string>(); 
		//this.ar_props = new Gee.HashMap<string,string>();
		
		
		
		// this is the bit that causes issues - we have to output as we go, otherwise we 
		// can not work out which line is which...
		
		this.out_props = new Gee.HashMap<string,string>();
		this.out_listeners = new Gee.HashMap<string,string>();	
		
		
		this.out_nodeprops = new Gee.HashMap<string,Node>() ;
		this.out_children = new Gee.ArrayList<Node> ();
		
		this.out_props_array = new Gee.HashMap<string,Gee.ArrayList<Node>>(); // filled in by 'checkChildren'
		this.out_props_array_plain = new Gee.HashMap<string,Gee.ArrayList<string>>() ;
	
		
		
		this.cur_line = parent == null ? 0 : parent.cur_line  ; //-1 as we usuall concat onto the existin gline?
		if (parent != null) {
			this.renderer = parent.renderer;
		}
		this.ret = "";
		this.top = parent == null ? this : parent.top;
		// reset the maps...
		if (parent == null) {
			node.node_lines = new Gee.ArrayList<int>();
			node.node_lines_map = new Gee.HashMap<int,Node>();
		 }
	}
	
	/**
	convert the node + children into Javascript
	This one does not output the top node's data -
	designed for the 'componentized output'
	
	*/
	
	
	public string mungeChildrenOnly ( )
	{
		//return this.mungeToString(this.node);

		
		this.checkChildren();
		this.readProps();
		//this.readArrayProps();
		this.readListeners();

		if (!this.node.props.has_key("* xinclude")) {
			// needed to extract children data..
			this.iterChildren();
		}
		

		//var suffix = "";
		this.mungeOutStart();
		 
	 	this.mungeOutChildren();
 		this.mungeOutEnd();
		this.node.sortLines();		 
		return this.ret;
	 
		 
	} 
	
	
	
	public string munge ( )
	{
		//return this.mungeToString(this.node);

		
		this.checkChildren();
		this.readProps();
		//this.readArrayProps();
		this.readListeners();

		if (!this.node.props.has_key("* xinclude")) {
			// needed to extract children data..
			this.iterChildren();
		}
		

		this.mungeOut();
		return this.ret;
		 
	} 
		/**
	
	This currently works by creating a key/value array of this.els, which is just an array of properties..
	this is so that join() works...
	
	how this could work:
	a) output header
	b) output plan properties.
	c) output listeners..
	c) output *prop
	g) output prop_arrays..
	d) output children
	e) 
	
	
	
	*/
	
	public Gee.ArrayList<string> orderedPropKeys() {
	
		var ret = new Gee.ArrayList<string> ();
		var niter = this.out_props.map_iterator();
		while(niter.next()) {
			ret.add(niter.get_key());
		}
		
		ret.sort((  a,  b) => {
			return ((string)a).collate((string)b);
			//if (a == b) return 0;
			//return a < b ? -1 : 1;
		});
		return ret;
	}
	public Gee.ArrayList<string> orderedListenerKeys() {
	
		var ret = new Gee.ArrayList<string> ();
		var niter = this.out_listeners.map_iterator();
		while(niter.next()) {
			ret.add(niter.get_key());
		}
		
		ret.sort((  a,  b) => {
			return ((string)a).collate((string)b);
			//if (a == b) return 0;
			//return a < b ? -1 : 1;
		});
		return ret;
	}
	
 
	

	public void mungeOutProps()
	{
		// plain properties.
		var iter = this.orderedPropKeys().list_iterator();
		while(iter.next()) {
 
			 
			var k = iter.get();
			if (k == "xns" || k == "xtype") {
				continue;
			}

			var v = this.out_props.get(k);
			this.node.setLine(this.cur_line, "p",k); 
			this.addLine(this.pad + k + " : " + v /* +  suffix */, ',');
			 
			this.node.setLine(this.cur_line, "e", "");
			
		}
	
	}
	public void mungeOutListeners()
	{
		if (this.out_listeners.size > 0 ) { 
			 
			this.addLine(this.pad + "listeners : {", 0);
			var iter = this.orderedListenerKeys().list_iterator();
			 
			while(iter.next()) {
				
				var k = iter.get();
				var v = this.out_listeners.get(k);
				this.node.setLine(this.cur_line, "l",k); //listener
				this.addLine(this.pad + indent_str + k + " : " + v , ',');
				this.node.setLine(this.cur_line, "e", "");
			}
			
			this.closeLine();
			this.addLine(this.pad + "}" ,',');
			
		}
	
	}
	
	public void mungeOutPropObjects()
	{
	// * prop

		var niter = this.out_nodeprops.map_iterator();

		while(niter.next()) {
			var addstr = this.mungeChild(this.pad + indent_str, niter.get_value());
			//print("add str: %s\n", addstr);
			this.node.setLine(this.cur_line, "p",niter.get_key());
			this.addLine(this.pad + niter.get_key() + " : " + addstr, ',');
			
			this.node.setLine(this.cur_line, "e", "");
		}		
	}
	
	public void mungeOutPropArrays()
	{
	
		var piter = this.out_props_array.map_iterator();

		while(piter.next()) {
			this.node.setLine(this.cur_line, "p",piter.get_key());
			this.addLine(this.pad + piter.get_key() + " : [", 0);
			
			var pliter = piter.get_value().list_iterator();
			while (pliter.next()) {
				var addstr = this.mungeChild(this.pad + indent_str  + indent_str, pliter.get());
				this.addLine(this.pad + indent_str + addstr, ',');
				this.node.setLine(this.cur_line, "e", "");
			}
			this.closeLine();
			this.addLine(this.pad + "]" , ',');			
		}	
	}
	
	public void mungeOutChildrenArray()
	{
		// children..
		if (this.out_children.size <  1) {
			this.addLine("[]" , 0);
			return;
		}
		
		this.addLine("[" , 0);
		var cniter = this.out_children.list_iterator();
		while (cniter.next()) {
			//suffix = cniter.has_next()  ? "," : "";
			var addstr = this.mungeChild(this.pad + indent_str  + indent_str, cniter.get());
			this.addLine(this.pad + indent_str + addstr, ',');
			this.node.setLine(this.cur_line, "e", "");
			
		}
		this.closeLine();
		this.addLine(this.pad +   "]",0);
		
	
	}
	
	
	public void mungeOutChildren()
	{
		// children..
		if (this.out_children.size > 0) {
			this.addLine(this.pad + "items  : [" , 0);
			var cniter = this.out_children.list_iterator();
			while (cniter.next()) {
				//suffix = cniter.has_next()  ? "," : "";
				var addstr = this.mungeChild(this.pad + indent_str  + indent_str, cniter.get());
				this.addLine(this.pad + indent_str + addstr, ',');
				this.node.setLine(this.cur_line, "e", "");
				
			}
			this.closeLine();
			this.addLine(this.pad +   "]",',');
		}
	
	}
	
	public void mungeOutXtype()
	{
		if (this.out_props.has_key("xtype")) {
			var v = this.out_props.get("xtype");
			this.node.setLine(this.cur_line, "p","xtype"); 
			this.addLine(this.pad + "xtype" + " : " + v /* + suffix */, ',');
		}

	}
	public void mungeOutXNS()
	{
		if (this.out_props.has_key("xns")) {
			var v = this.out_props.get("xns");
			this.node.setLine(this.cur_line, "p","xns"); 
			this.addLine(this.pad + "xns" + " : " + v /*+ suffix*/, ',');
			this.node.setLine(this.cur_line, "p","| xns"); 
			this.addLine(this.pad + "'|xns' : '" + v + "'", ',');
			this.node.setLine(this.cur_line, "e", "");
		}
		
	}
	public void mungeOutStart()
	{
		this.node.line_start = this.cur_line;
		this.top.node.setNodeLine(this.cur_line, this.node);

		
		if (this.node.props.has_key("* xinclude")) {
			this.addLine("Roo.apply(" + this.node.props.get("* xinclude") + "._tree(), {",0 );	 
		} else {
			this.addLine("{", 0);
		}
		
	}
	public void mungeOutEnd()
	{
		
		var spad = this.pad.substring(0, this.pad.length-indent);
		this.node.setLine(this.cur_line, "e", "");
		this.closeLine();
		if (this.node.props.has_key("* xinclude")) {
			this.addLine(spad + "})",0);
	 
		} else {
			this.addLine( spad + "}", 0);
		}
	}
	
	public string mungeOut()
	{
		//var suffix = "";
		this.mungeOutStart();
		this.mungeOutXtype();	
		this.mungeOutProps();
		this.mungeOutListeners();
		this.mungeOutXNS();			 
		this.node.line_end = this.cur_line;
	 	this.mungeOutPropObjects();
	 	this.mungeOutPropArrays();	
	 	this.mungeOutChildren();
 		this.mungeOutEnd();
		this.node.sortLines();		 
		return this.ret;
	}
	
	/**
	* Line endings
	*     if we end with a ','
	*
	*/

	char last_line_end = '!'; 
	
	/**
	* add a line - note we will end up with an extra line break 
	*     at beginning of nodes doing this..
	*
	* @param str = text to add..
	* @param line_end = 0  (just add a line break)
	*        line_end = ','  and ","
	*  
	*/
	public void addLine(string str, char line_end)
	{
		if (this.last_line_end != '!') {
			this.ret += (this.last_line_end == 0 ? "" : this.last_line_end.to_string()) + "\n"; 
		}
		this.last_line_end = line_end;
		this.cur_line += str.split("\n").length;
		this.ret += str;
		
		
		//this.ret +=  "/*%d(%d-%d)*/ ".printf(this.cur_line -1, this.node.line_start,this.node.line_end) + str + "\n";
		
		
	}
	public void closeLine() // send this before '}' or ']' to block output of ',' ...
	{
		this.last_line_end = 0;
	}
	
/*	public void addMultiLine(str= "")
	{
		
		//this.ret +=   "/ * %d(%d-%d) * / ".printf(this.cur_line, this.node.line_start,this.node.line_end)+ str + "\n";
		this.ret +=   str + "\n";
		this.cur_line += str.split("\n").length;
	}
 */
	public string mungeChild(string pad ,  Node cnode )
	{
		var x = new  NodeToJs(cnode, this.doubleStringProps, pad, this);
	 
		x.munge();
		return x.ret;
	}
	
	/**
	* loop through items[] array see if any of the children have '* prop'
	* -- which means they are a property of this node.
	* -- ADD TO : this.opt_props_array  
	*
	*/
	
	public void checkChildren () 
	{
		
		 
		// look throught he chilren == looking for * prop.. -- fixme might not work..
		
		
		if (!this.node.hasChildren()) {
			return;
		}
		// look for '*props'
	   
		for (var ii =0; ii< this.node.items.size; ii++) {
			var pl = this.node.items.get(ii);
			if (!pl.props.has_key("* prop")) {
				//newitems.add(pl);
				continue;
			}
			
			//print(JSON.stringify(pl,null,4));
			// we have a prop...
			//var prop = pl['*prop'] + '';
			//delete pl['*prop'];
			var prop = pl.get("* prop");
			//print("got prop "+ prop + "\n");
			
			// name ends in [];
			if (! Regex.match_simple("\\[\\]$", prop)) {
				// it's a standard prop..
				
				// munge property..??
				
				this.out_nodeprops.set(prop, pl);
				 
				continue;
			}



			
			var sprop  = prop.replace("[]", "");
			//print("sprop is : " + sprop + "\n");
			
			// it's an array type..
			//var old = "";
			if (!this.out_props_array.has_key(sprop)) {
				this.out_props_array.set(sprop, new Gee.ArrayList<Node>());
			}
			
			 
			this.out_props_array.get(sprop).add( pl);
	  		//this.ar_props.set(sprop, nstr);
			 
			
		}
		 
	}
	/*
 * Standardize this crap...
 * 
 * standard properties (use to set)
 *          If they are long values show the dialog..
 *
 * someprop : ....
 * bool is_xxx  :: can show a pulldown.. (true/false)
 * string html  
 * $ string html  = string with value interpolated eg. baseURL + ".." 
 *  Clutter.ActorAlign x_align  (typed)  -- shows pulldowns if type is ENUM? 
 * $ untypedvalue = javascript untyped value...  
 * _ string html ... = translatable..

 * 
 * object properties (not part of the GOjbect being wrapped?
 * # Gee.ArrayList<Xcls_fileitem> fileitems
 * 
 * signals
 * @ void open 
 * 
 * methods -- always text editor..
 * | void clearFiles
 * | someJSmethod
 * 
 * specials
 * * prop -- string
 * * args  -- string
 * * ctor -- string
 * * init -- big string?
 * 
 * event handlers (listeners)
 *   just shown 
 * 
 * -----------------
 * special ID values
 *  +XXXX -- indicates it's a instance property / not glob...
 *  *XXXX -- skip writing glob property (used as classes that can be created...)
 * 
 * 
 */
	public void readProps()
	{
		string left;
		Regex func_regex ;
 
		try {
			func_regex = new Regex("^\\s+|\\s+$");
		} catch (RegexError e) {
			print("failed to build regex");
			return;
		}
		// sort the key's so they always get rendered in the same order..
		
		var keys = new Gee.ArrayList<string>();
		var piter = this.node.props.map_iterator();
		while (piter.next() ) {
			string k;
			string ktype;
			string kflag;
			this.node.normalize_key(piter.get_key(), out k, out kflag, out ktype);
			
			keys.add(k);
		}
		
		keys.sort((  a,  b) => {
			return ((string)a).collate((string)b);
			//if (a == b) return 0;
			//return a < b ? -1 : 1;
		});
		
		var has_cms = this.node.has("cms-id");
		
		for (var i = 0; i< keys.size; i++) {
			var key = this.node.get_key(keys.get(i));
			//("ADD KEY %s\n", key);
			string k;
			string ktype;
			string kflag;
			
			this.node.normalize_key(key, out k, out kflag, out ktype);
			
			
			var v = this.node.get(key);
			 
			
			//if (this.skip.contains(k) ) {
			//	continue;
			//}
			if (  Regex.match_simple("\\[\\]$", k)) {
				// array .. not supported... here?
				

			}
			
			string leftv = k;
			// skip builder stuff. prefixed with  '.' .. just like unix fs..
			if (kflag == ".") { // |. or . -- do not output..
				continue;
			}
			if (kflag == "*") {
				// ignore '* prop'; ??? 
				continue;
			}
			
			// handle cms-id // html
			if (has_cms && k == "cms-id") {
				continue; // ignore it...
			}
			// html must not be a dynamic property...
			// note - we do not translate this either...
			if (has_cms && k == "html" && kflag != "$") {
				 

				this.out_props.set("html", "Pman.Cms.content(" + 
					this.node.quoteString(this.renderer.name + "::" + this.node.get("cms-id")) +
					 ", " +
					this.node.quoteString(v) +
					 ")");
					 
				continue;	 
			}
			
			
				
			
			if (Lang.isKeyword(leftv) || Lang.isBuiltin(leftv)) {
				left = "'" + leftv + "'";
			} else if (Regex.match_simple("[^A-Za-z_]+",leftv)) { // not plain a-z... - quoted.
				var val = this.node.quoteString(leftv);
				
				left = "'" + val.substring(1, val.length-2).replace("'", "\\'") + "'";
			} else {
				left = leftv;
			}
			 
			 
			// next.. is it a function.. or a raw string..
			if (
				kflag == "|" 
				|| 
				kflag == "$" 
				|| 
				ktype == "function"
	   		       
				// ??? any others that are raw output..
				) {
				// does not hapepnd with arrays.. 
				if (v.length < 1) {  //if (typeof(el) == 'string' && !obj[i].length) { //skip empty.
					continue;
				}
				/*
				print(v);
				string str = "";
				try {
					str = func_regex.replace(v,v.length, 0, "");
				} catch(Error e) {
					print("regex failed");
					return "";
				}
				*/
				var str = v.strip();
				  
				var lines = str.split("\n");
				var nstr = "" + str;
				if (lines.length > 0) {
					nstr =  string.joinv("\n" + this.pad, lines);
					//nstr =  string.joinv("\n", lines);
				}
				this.out_props.set(left, nstr);
				
				

				
				
				//print("==> " +  str + "\n");
				//this.els.add(left + " : "+  nstr);
				continue;
			}
			// standard..
			
			
			if (
				Lang.isNumber(v) 
				|| 
				Lang.isBoolean(v)
				||
				ktype.down() == "boolean"
    	   		        || 
				ktype.down() == "bool"
				|| 
				ktype.down() == "number"
				|| 
				ktype.down() == "int"
			    ) { // boolean or number...?
			    this.out_props.set(left, v.down());
				//this.els.add(left + " : " + v.down() );
				continue;
			}
			
			// is it a translated string?
			
			
			
			
			// strings..
		 	// doubleStringProps is a list of keys like 'name' 'title' etc.. that we know can be translated..
		   
			if ((this.doubleStringProps.index_of(k) > -1) || 
				(ktype.down() == "string" && k[0] == '_')
			
			) {
				// then use the translated version...
				
				var com = " /* " + 
					(v.split("\n").length > 1 ?
						("\n" + this.pad +  string.joinv(this.pad +  "\n", v.split("\n")).replace("*/", "* - /") + "\n" + this.pad + "*/ ") :
 						(v.replace("*/", "* - /") + " */")
					);
				
				//this.els.add(left + " : _this._strings['" + 
				//	GLib.Checksum.compute_for_string (ChecksumType.MD5, v) +
				//	"']"
				//);
				
				// string is stored in Roo.vala
				var  kname = GLib.Checksum.compute_for_string (ChecksumType.MD5, v.strip());

				this.out_props.set(left, "_this._strings['" + kname + "']" + com);
				continue;
			}
		 
			// otherwise it needs to be encapsulated.. as single quotes..
			
			var vv = this.node.quoteString(v);
			// single quote.. v.substring(1, v.length-1).replace("'", "\\'") + "'";
			//this.els.add(left + " : " +  "'" + vv.substring(1, vv.length-2).replace("'", "\\'") + "'");
			this.out_props.set(left,  "'" + vv.substring(1, vv.length-2).replace("'", "\\'") + "'");

		   
		   
		   
		}
	}
	 
	public void readListeners()
	{
		
		if (this.node.listeners.size < 1) {
			return;
		}
		// munge the listeners.
		//print("ADDING listeners?");
	
 
	
	
		var keys = new Gee.ArrayList<string>();
		var piter = this.node.listeners.map_iterator();
		while (piter.next() ) {
			keys.add(piter.get_key());
		}
		keys.sort((  a,  b) => {
			return ((string)a).collate((string)b);
		});
	
		 
		for (var i = 0; i< keys.size; i++) {
			var key = keys.get(i);
			var val = this.node.listeners.get(key);
		
			var str = val.strip();
			var lines = str.split("\n");
			if (lines.length > 0) {
				str = string.joinv("\n" + this.pad + indent_str + indent_str , lines);
			}
			this.out_listeners.set(key.replace("|", "") ,str);
		}
		 
		 

	}

	public void iterChildren()
	{
		
		
		// finally munge the children...
		if (this.node.items.size < 1) {
			return;
		}
		var itms = "items : [\n";
		//var n = 0;
		for(var i = 0; i < this.node.items.size;i++) {
			var ele = this.node.items.get(i);
			if (ele.props.has_key("* prop")) {
				continue;
			}
			 
			this.out_children.add(ele);
			
		}
		itms +=  "\n"+  this.pad + "]"  + "\n";
		//this.els.add(itms);
	}

		// finally output listeners...
		
	public void xIncludeToString()
	{
		

	}

}
	
	 
	
	
