<?php

// in flutter - an event is actually a property..?

// we have 2 types of data - the overall summary, and the 'detail one we use for docs..
//

class Obj {
    function __construct($ar)
    {
        foreach($ar as $k=>$v) {
            $this->{$k} = $v;
        }
    }
}

class  Prop extends Obj {
    var $name = '';
    var $type = '';
    var $desc = '';
    var $memberOf = '';
}

class  Method extends Obj {  // doubles up for events? - normally 'on' is the name
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
    
}

class Cls extends Obj {
    var $name;
    var $extends;
    var $events = array();
    var $methods = array();
    var $props = array();
}
class Param extends Obj {
    var $name = '';
    var $type = '';
    var $desc = '';
    var $isOptional = true;
}



$fdir = '/home/alan/Downloads/flutterdocs/flutter/';
$js = json_decode(file_get_contents($fdir.'index.json'));
foreach($js as $o) {
    switch($o->type) {
        case 'library':
            break;
            
        case 'class':
            $classes[$o->qualifiedName] = new Cls()
            
           
    }
    
    
    
}