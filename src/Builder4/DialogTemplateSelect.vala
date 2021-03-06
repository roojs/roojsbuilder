static DialogTemplateSelect  _DialogTemplateSelect;

public class DialogTemplateSelect : Object
{
    public Gtk.Dialog el;
    private DialogTemplateSelect  _this;

    public static DialogTemplateSelect singleton()
    {
        if (_DialogTemplateSelect == null) {
            _DialogTemplateSelect= new DialogTemplateSelect();
        }
        return _DialogTemplateSelect;
    }
    public Xcls_combo combo;
    public Xcls_cellrenderer cellrenderer;
    public Xcls_model model;
    public Xcls_dbcombo dbcombo;
    public Xcls_dbcellrenderer dbcellrenderer;
    public Xcls_dbmodel dbmodel;

        // my vars (def)

    // ctor
    public DialogTemplateSelect()
    {
        _this = this;
        this.el = new Gtk.Dialog();

        // my vars (dec)

        // set gobject values
        this.el.title = "Add an Object";
        this.el.default_height = 200;
        this.el.default_width = 400;
        this.el.modal = true;
        var child_0 = new Xcls_Box2( _this );
        child_0.ref();
        this.el.get_content_area().add (  child_0.el  );
        var child_1 = new Xcls_Button13( _this );
        child_1.ref();
        this.el.add_action_widget (  child_1.el , 0 );
        var child_2 = new Xcls_Button14( _this );
        child_2.ref();
        this.el.add_action_widget (  child_2.el , 1 );
        var child_3 = new Xcls_Button15( _this );
        child_3.ref();
        this.el.add_action_widget (  child_3.el , 2 );

        //listeners
        this.el.delete_event.connect( (self, event)  =>{
            this.el.hide();
            return true;
        });
    }

    // user defined functions
    public JsRender.Node? show (Xcls_MainWindow mwindow, Palete.Palete pal, JsRender.Node node, Project.Project project) {
        
        this.el.show_all();
        var opts = pal.listTemplates(node);
        if (opts.length() < 1) {
            this.el.hide();
            return node;
        }
        this.el.set_attached_to( mwindow.el);
        this.el.set_transient_for( mwindow.el);
        
        //opts.unshift({ path: '' , name :'Just add Element' });
         _this.model.loadData(opts);
         _this.combo.el.set_active(-1);
         
         
         var db =  new Palete.RooDatabase.from_project(project);
         _this.dbmodel.loadData(db.readTablesGee());
         
         var plug = mwindow.windowstate.webkit_plugin;
         
         _this.dbcombo.el.set_active(-1);
         
         
       
        var res = this.el.run();
        this.el.hide();    
        //var ix = _this.combo.el.get_active();
        if (res < 1 ) {
            return null; // 0 = cancel.
        }
        if (res < 2 ) {
            return node; // 1 = just add it..
        }
        
        // have they selected a table??
        
       Gtk.TreeIter iter; 
        Value vfname;   
        if (_this.dbcombo.el.get_active_iter (out iter)) {    
             this.dbmodel.el.get_value (iter, 0, out vfname);
             if (((string)vfname).length > 0 && plug.has_plugin(node.fqn())) {
                var json_str = plug.show(mwindow.el, project, node.fqn(), (string)vfname);
                print("json_str = %s\n", json_str);
                if (json_str.length < 1) {
    
                    return node;
                }
                var pa = new Json.Parser();
                try {
    
    	        pa.load_from_data(json_str);
    	    } catch(Error e) {
    	        return node;
    	    }
    	    var new_node = pa.get_root();
        
    	    if (new_node.get_node_type () != Json.NodeType.OBJECT) {
    		    return node;
    	    }
    	    var obj = new_node.get_object ();
    
    	    var ret = new JsRender.Node();
    
    	    ret.loadFromJson(obj, 1);
    	    return ret;
             }
            
        }
    
        if (!_this.combo.el.get_active_iter (out iter)) {
    
            return node; // nothing selected...
        }
       
        this.model.el.get_value (iter, 0, out vfname);
        
        
        return pal.loadTemplate((string)vfname);
    
    }
    public class Xcls_Box2 : Object
    {
        public Gtk.Box el;
        private DialogTemplateSelect  _this;


            // my vars (def)

        // ctor
        public Xcls_Box2(DialogTemplateSelect _owner )
        {
            _this = _owner;
            this.el = new Gtk.Box( Gtk.Orientation.VERTICAL, 0 );

            // my vars (dec)

            // set gobject values
            var child_0 = new Xcls_Box3( _this );
            child_0.ref();
            this.el.pack_start (  child_0.el , false,false,0 );
            var child_1 = new Xcls_Box8( _this );
            child_1.ref();
            this.el.pack_start (  child_1.el , false,false,0 );
        }

        // user defined functions
    }
    public class Xcls_Box3 : Object
    {
        public Gtk.Box el;
        private DialogTemplateSelect  _this;


            // my vars (def)

        // ctor
        public Xcls_Box3(DialogTemplateSelect _owner )
        {
            _this = _owner;
            this.el = new Gtk.Box( Gtk.Orientation.HORIZONTAL, 0 );

            // my vars (dec)

            // set gobject values
            this.el.margin = 3;
            var child_0 = new Xcls_Label4( _this );
            child_0.ref();
            this.el.pack_start (  child_0.el , false,false );
            var child_1 = new Xcls_combo( _this );
            child_1.ref();
            this.el.add (  child_1.el  );
        }

        // user defined functions
    }
    public class Xcls_Label4 : Object
    {
        public Gtk.Label el;
        private DialogTemplateSelect  _this;


            // my vars (def)

        // ctor
        public Xcls_Label4(DialogTemplateSelect _owner )
        {
            _this = _owner;
            this.el = new Gtk.Label( "Select Template : " );

            // my vars (dec)

            // set gobject values
        }

        // user defined functions
    }

    public class Xcls_combo : Object
    {
        public Gtk.ComboBox el;
        private DialogTemplateSelect  _this;


            // my vars (def)

        // ctor
        public Xcls_combo(DialogTemplateSelect _owner )
        {
            _this = _owner;
            _this.combo = this;
            this.el = new Gtk.ComboBox();

            // my vars (dec)

            // set gobject values
            var child_0 = new Xcls_cellrenderer( _this );
            child_0.ref();
            this.el.pack_start (  child_0.el , true );
            var child_1 = new Xcls_model( _this );
            child_1.ref();
            this.el.set_model (  child_1.el  );

            // init method

            this.el.add_attribute(_this.cellrenderer.el , "markup", 1 );
        }

        // user defined functions
    }
    public class Xcls_cellrenderer : Object
    {
        public Gtk.CellRendererText el;
        private DialogTemplateSelect  _this;


            // my vars (def)

        // ctor
        public Xcls_cellrenderer(DialogTemplateSelect _owner )
        {
            _this = _owner;
            _this.cellrenderer = this;
            this.el = new Gtk.CellRendererText();

            // my vars (dec)

            // set gobject values
        }

        // user defined functions
    }

    public class Xcls_model : Object
    {
        public Gtk.ListStore el;
        private DialogTemplateSelect  _this;


            // my vars (def)

        // ctor
        public Xcls_model(DialogTemplateSelect _owner )
        {
            _this = _owner;
            _this.model = this;
            this.el = new Gtk.ListStore( 2, typeof(string),typeof(string) );

            // my vars (dec)

            // set gobject values
        }

        // user defined functions
        public void loadData (GLib.List<string> data) {
            this.el.clear();                                    
            Gtk.TreeIter iter;
            var el = this.el;
            
           /// el.append(out iter);
            
             
           // el.set_value(iter, 0, "");
           // el.set_value(iter, 1, "aaa  - Just add Element - aaa");
            
            for (var i = 0; i < data.length();i++) {
            
        
                el.append(out iter);
                var str = data.nth_data(i);
                var fn = Path.get_basename (str);
                fn.replace(".json", "");
                
                el.set_value(iter, 0, str);
                el.set_value(iter, 1, fn);
                
            }
            this.el.set_sort_column_id(1, Gtk.SortType.ASCENDING);          
                                             
        }
    }



    public class Xcls_Box8 : Object
    {
        public Gtk.Box el;
        private DialogTemplateSelect  _this;


            // my vars (def)

        // ctor
        public Xcls_Box8(DialogTemplateSelect _owner )
        {
            _this = _owner;
            this.el = new Gtk.Box( Gtk.Orientation.HORIZONTAL, 0 );

            // my vars (dec)

            // set gobject values
            this.el.margin = 3;
            var child_0 = new Xcls_Label9( _this );
            child_0.ref();
            this.el.pack_start (  child_0.el , false,false );
            var child_1 = new Xcls_dbcombo( _this );
            child_1.ref();
            this.el.add (  child_1.el  );
        }

        // user defined functions
    }
    public class Xcls_Label9 : Object
    {
        public Gtk.Label el;
        private DialogTemplateSelect  _this;


            // my vars (def)

        // ctor
        public Xcls_Label9(DialogTemplateSelect _owner )
        {
            _this = _owner;
            this.el = new Gtk.Label( "Select Database Table : " );

            // my vars (dec)

            // set gobject values
        }

        // user defined functions
    }

    public class Xcls_dbcombo : Object
    {
        public Gtk.ComboBox el;
        private DialogTemplateSelect  _this;


            // my vars (def)

        // ctor
        public Xcls_dbcombo(DialogTemplateSelect _owner )
        {
            _this = _owner;
            _this.dbcombo = this;
            this.el = new Gtk.ComboBox();

            // my vars (dec)

            // set gobject values
            var child_0 = new Xcls_dbcellrenderer( _this );
            child_0.ref();
            this.el.pack_start (  child_0.el , true );
            var child_1 = new Xcls_dbmodel( _this );
            child_1.ref();
            this.el.set_model (  child_1.el  );

            // init method

            this.el.add_attribute(_this.dbcellrenderer.el , "markup", 1 );
        }

        // user defined functions
    }
    public class Xcls_dbcellrenderer : Object
    {
        public Gtk.CellRendererText el;
        private DialogTemplateSelect  _this;


            // my vars (def)

        // ctor
        public Xcls_dbcellrenderer(DialogTemplateSelect _owner )
        {
            _this = _owner;
            _this.dbcellrenderer = this;
            this.el = new Gtk.CellRendererText();

            // my vars (dec)

            // set gobject values
        }

        // user defined functions
    }

    public class Xcls_dbmodel : Object
    {
        public Gtk.ListStore el;
        private DialogTemplateSelect  _this;


            // my vars (def)

        // ctor
        public Xcls_dbmodel(DialogTemplateSelect _owner )
        {
            _this = _owner;
            _this.dbmodel = this;
            this.el = new Gtk.ListStore( 2, typeof(string),typeof(string) );

            // my vars (dec)

            // set gobject values
        }

        // user defined functions
        public void loadData (Gee.ArrayList<string> data) {
            this.el.clear();                                    
            Gtk.TreeIter iter;
            var el = this.el;
            
           /// el.append(out iter);
            
             
           // el.set_value(iter, 0, "");
           // el.set_value(iter, 1, "aaa  - Just add Element - aaa");
        
            el.append(out iter);
        
            
            el.set_value(iter, 0, "");
            el.set_value(iter, 1, "-- select a table --");
            
            
            for (var i = 0; i < data.size;i++) {
            
        
                el.append(out iter);
                
                el.set_value(iter, 0, data.get(i));
                el.set_value(iter, 1, data.get(i));
                
            }
             this.el.set_sort_column_id(0, Gtk.SortType.ASCENDING);          
                                             
        }
    }




    public class Xcls_Button13 : Object
    {
        public Gtk.Button el;
        private DialogTemplateSelect  _this;


            // my vars (def)

        // ctor
        public Xcls_Button13(DialogTemplateSelect _owner )
        {
            _this = _owner;
            this.el = new Gtk.Button();

            // my vars (dec)

            // set gobject values
            this.el.label = "Cancel";
        }

        // user defined functions
    }

    public class Xcls_Button14 : Object
    {
        public Gtk.Button el;
        private DialogTemplateSelect  _this;


            // my vars (def)

        // ctor
        public Xcls_Button14(DialogTemplateSelect _owner )
        {
            _this = _owner;
            this.el = new Gtk.Button();

            // my vars (dec)

            // set gobject values
            this.el.label = "Just add it";
        }

        // user defined functions
    }

    public class Xcls_Button15 : Object
    {
        public Gtk.Button el;
        private DialogTemplateSelect  _this;


            // my vars (def)

        // ctor
        public Xcls_Button15(DialogTemplateSelect _owner )
        {
            _this = _owner;
            this.el = new Gtk.Button();

            // my vars (dec)

            // set gobject values
            this.el.label = "OK";
        }

        // user defined functions
    }

}
