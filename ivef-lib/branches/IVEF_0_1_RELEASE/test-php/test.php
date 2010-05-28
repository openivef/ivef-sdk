<?php

   // setup the search path
   $path = '../ivef-php';
   set_include_path(get_include_path() . PATH_SEPARATOR . $path);

   // include the library
   require "IVEFParser.php";

   // get the data
   echo "TestApp ready for input\n";
   $input = file_get_contents("php://stdin");

   // parse it
   $parser = new Parser();  
   $result = $parser->parseXMLMessage($input);

   // send out as text
   echo $result->toString();

   // send out as xml
   $dom = new DOMDocument('1.0');
   $dom->preserveWhiteSpace = false;
   $dom->formatOutput = true;
   $dom->loadXML($result->toXML());
   //echo $dom->saveXML();
   $xml = "";
   foreach($dom->childNodes as $node) {
       $xml .= $dom->saveXML($node)."\n";
   }
   echo $xml;
 
   echo "\nTestApp shutting down\n";
?>
