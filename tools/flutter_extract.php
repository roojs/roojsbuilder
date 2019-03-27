<?php

// in flutter - an event is actually a property..?

// we have 2 types of data - the overall summary, and the 'detail one we use for docs..
//

define( 'FDIR', '/home/alan/Downloads/flutterdocs/flutter/');


class Obj {
    
    static $out_props = array(
        'eClass' => array('props', 'events', 'methods'),
        'eMixin' =>  array('props', 'events', 'methods'),
        'eTypedef' => array('name', 'type', 'sig', 'static', 'desc','memberOf'),
        'eProperty' => array('name', 'type', 'desc','memberOf'),
        'eMethod' => array('name', 'type', 'sig', 'static', 'desc','memberOf', 'isConstructor'),
        'eConstructor' => array('name', 'type', 'sig', 'static', 'desc','memberOf', 'isConstructor'),
        'eEnum' =>  array('name', 'type', 'static', 'desc','memberOf'), // fixme .. .values.?
        'eFunction' =>  array('name', 'type', 'sig', 'static', 'desc','memberOf', 'isConstructor'),// fixme .. .memberof == package.
        'Prop' => array('name', 'type', 'desc','memberOf'),
    );
    
    var $href = '';
    var $desc = '';
    var $example = '';
    var $isDeprecated = false;
    function __construct($ar)
    {
        foreach($ar as $k=>$v) {
            $this->{$k} = $v;
        }
         
    }
    
    
    function parseHTML()
    {
        $dom = new DomDocument();
        libxml_use_internal_errors(true);
        //echo "Reading : {$this->href}\n";
        $dom->loadHTMLFile(FDIR . $this->href);
        libxml_clear_errors();
        $xp = new DomXPath($dom);
        $desc = $this->getElementsByClassName($dom, 'desc');
        if ($desc->length) {
            $this->desc = $this->innerHTML($desc->item(0));
        }
        $sc = $this->getElementsByClassName($dom, 'source-code');
        if ($sc->length) {
            $this->example = $this->innerHTML($sc->item(0));
        }
        return $dom;
    }
    
    function getElementsByClassName($dom, $class)
    {
        $xp = new DomXPath($dom);
        return $xp->query("//*[contains(concat(' ', @class, ' '), ' ".$class." ')]");
    }
    function innerHTML($node)
    {
        if (!$node) {
            print_r($this); 
        }
        $dom= $node->ownerDocument;
        $ret = '';
        foreach ($node->childNodes as $child) 
        { 
            $ret.= $dom->saveHTML($child);
        }
        return $ret;
        
    }
    function parseType($sp)
    {
        if (!$sp) {
            print_R($this);
            echo "parseType got invalid value";
         }
        $ar = $sp->getElementsByTagName('a');
        if (!$ar->length) {
            $this->type = $sp->textContent;
        }
        if ($ar->length == 1) {
            $this->type = eClass::$url_map[$ar->item(0)->getAttribute('href')]->name;
            return;
        } 
        $this->type = array();
        for($i =0;$i<$ar->length;$i++) {
            $this->type[] = eClass::$url_map[$ar->item($i)->getAttribute('href')]->name;
        }
         
    }
    function toSummaryArray()
    {
        $ret = array();
        if (!isset(self::$out_props[get_class($this)] )) {
            die("don't know how to handle class: " . get_class($this));
        }
        foreach(self::$out_props[get_class($this)] as $k) {
            $out = $this->{$k};
            if (is_array($out)) {
                $out = array();
                foreach($this->{$k} as $v) {
                    $out[] = $v->toSummaryArray();
                }
            }
            $ret[$k] = $out;
        }
        return $ret;
    }
    
}


class eClass extends Obj {
    
    static $all = array();
    static $url_map = array();
    var $name;
    var $extends;
    var $events = array();
    var $methods = array();
    var $props = array();
    var $isMixin = false;
    var $isEnum = false;
    var $isTypedef = false;
    var $isConstant = false;
    
    function __construct($ar)
    {
        parent::__construct($ar);
        self::$all[$this->name] = $this;
        self::$url_map[$this->href] = $this;
    }
    
    function parseHTML()
    {
        // do children first..
        
        
        
        $dom = parent::parseHTML();
        $dl = $dom->getElementsByTagName('dl')->item(0);
        if ($dl->getAttribute('class') != 'dl-horizontal') {
            $this->extends = '';
        } else {
            $dd = $dl->getElementsByTagName('a');
            if (!$dd->length) {
                if (strpos($this->innerHTML($dl), '@deprecated')) {
                    $this->isDeprecated = true;
                    return;
                }
                return;  // appears that the 'Annotation area' is used for things like @immutable etc..
            
                //echo "got dl-horizontal - but no 'a' tags";
                //print_R($this);exit;
            }
            if (!isset(self::$url_map[$dd->item($dd->length-1)->getAttribute('href')])) {
                die("could not find " . $dd->item($dd->length-1)->getAttribute('href') . " when parsing" . $this->href);
            }
            
            // 
            
            $this->extends = self::$url_map[$dd->item($dd->length-1)->getAttribute('href')]->name;
        }
        
    }
    
    function readDocs()
    {
        $this->parseHTML();
        foreach($this->events as $e) {
            $e->parseHTML();
        }
        foreach($this->methods as $e) {
            $e->parseHTML();
        }
        foreach($this->props as $e) {
            $e->parseHTML();
        }
        // loop through children.
        
    }
    
    
}
class eMixin extends eClass
{
    function parseHTML()
    {   
        $dom = Obj::parseHTML();
    }
}
class eConstant extends eClass
{
    function parseHTML()
    {   
        $dom = Obj::parseHTML();
    }
}
class eEnum extends eClass
{
    function parseHTML()
    {   
        $dom = Obj::parseHTML();
    }
}

class eProperty extends eClass
{
    function parseHTML()
    {   
        $dom = Obj::parseHTML();
    }
}

class  Prop extends Obj {
    var $name = '';
    var $type = '';
    var $desc = '';
    var $memberOf = '';
    var $isConstant = false;
}

class  eMethod extends Obj {  // doubles up for events? - normally 'on' is the name
    var $name = '';
    var $type = ''; // return...
    var $desc = '';
    var $static = false;
    var $memberOf = '';
    var $sig = '';
    var $params  = array();
    
      //"isStatic" : false,
    var $isConstructor = false;
    //"example" : "",
    //  "deprecated" : "",
    //  "since" : "",
     // "see" : "",
    // return_desc
    function parseHTML()
    {
        
        $dom = parent::parseHTML();
        $sp = $this->getElementsByClassName($dom,'returntype')->item(0);
        $this->parseType($sp);
            
        // params...
        $ar = $this->getElementsByClassName($dom,'parameter');
        for($i =0;$i<$ar->length;$i++) {
            $this->params[] = new Param( $ar->item($i) );
        }
        
        return $dom;
    }
    
}
class eConstructor extends eMethod {
    function parseHTML()
    {
        
        $dom = Obj::parseHTML();
        // doesnt have a 'type'    
        // params...
        $ar = $this->getElementsByClassName($dom,'parameter');
        for($i =0;$i<$ar->length;$i++) {
            $this->params[] = new Param( $ar->item($i) );
        }
        
        return $dom;
    }
}


class  eFunction extends eMethod
{
    function __construct($ar)
    {
        parent::__construct($ar);
        eClass::$all[$this->name] = $this;
        eClass::$url_map[$this->href] = $this;
    }
    function readDocs()
    {
        $this->parseHTML();
        // loop through children.
        
    }
    function parseHTML()
    {
        
        $dom = parent::parseHTML();
    }
}
class eTypedef extends eFunction
{
     
}
class Param extends Obj {
    var $name = '';
    var $type = '';
    var $desc = '';
    var $isOptional = true;
    function __construct($node)
    {
        
        $ar  = $node->getElementsByTagName('span');
        if (!$ar->length) {
            echo "mssing paramter info", $this->innerHTML($node); exit;
        }
        for($i = 0; $i < $ar->length; $i++) {
            
            switch($ar->item($i)->getAttribute('class')) {
                case 'parameter-name':
                    $this->name = $ar->item($i)->textContent;
                    break;
                case 'type-annotation':
                    $this->parseType($ar->item($i));
                    break;
                
            }
        }
        
        
        
    }
}



$js = json_decode(file_get_contents(FDIR.'index.json'));

foreach($js as $o) {
    switch($o->type) {
        case 'library':
            break;
            
        case 'class':
        case 'mixin':
        case 'enum':
        case 'typedef': // func sig?
        case 'top-level constant':
        case 'top-level property':
            $ctor = 'e'. ucfirst(str_replace('top-level ', '', $o->type));
            
            
            new $ctor(array(
                'name' => $o->qualifiedName,
                'href' => $o->href,
                'isMixin' => $o->type == 'mixin',
                'isEnum' => $o->type == 'enum',
                'isTypedef' => $o->type == 'typedef',
                'isConstant' => $o->type == 'top-level constant',
            ));
            break;
        
         
        
        case 'constructor':
        case 'method':
        case 'function':
            $ar = explode('.', $o->qualifiedName);
            array_pop($ar);
            $cls = implode('.', $ar);
            $ctor = 'e'. ucfirst($o->type);
            $add = new $ctor(array(
                'name' => $o->name,
                'href' => $o->href,
                'isConstructor' => $o->type == 'constructor',
            ));
            if ($o->type != 'function') {
                eClass::$all[$cls]->methods[] = $add;
            } else {
                eClass::$all[$o->qualifiedName] = $add;
            }
            break;
        
        case 'constant':
        case 'property':
        

            $ar = explode('.', $o->qualifiedName);
            array_pop($ar);
            $cls = implode('.', $ar);
            
            
            
            if (substr($o->name, 0,2) == 'on' && $o->type == 'property') {
                // presumtionus...
                eClass::$all[$cls]->events[] = new eMethod(array(
                    'name' => $o->name,
                    'href' => $o->href,
                    'isConstant' => $o->type == 'constant',
                    
                ));
                break;
            }
            $add =  new Prop(array(
                'name' => $o->name,
                'href' => $o->href,
            ));
            if ($o->type == 'top-level property') {
                eClass::$all[$o->qualifiedName] = $add;
            } else {
                eClass::$all[$cls]->props[] = $add;
            }
            break;  
        default:
            print_R($o);
            die("invalid type {$o->type}");
    }
    
    
    
}
$summary = array();
if (!file_exists(file_put_contents(FDIR .'json')) {
    mkdir(FDIR .'json', 0666);
}
foreach(eClass::$all as $c) {
    if (!method_exists($c, 'readDocs')) {
        echo "missing readDocs";
        print_R($c);exit;
    }
    $c->readDocs();
    $summary[$c->name] = $c->toSummaryArray();
    file_put_contents(FDIR .'json/index.json', json_encode($summary));
    file_put_contents(FDIR .'json/'.$c->name. '.json', json_encode(c));
}

print_r(eClass::$all);