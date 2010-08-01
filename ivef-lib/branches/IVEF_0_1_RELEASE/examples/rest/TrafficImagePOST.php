<?php

function uuid()  {
    $chars = md5(uniqid(rand()));
    $uuid  = substr($chars,0,8) . '-';
    $uuid .= substr($chars,8,4) . '-';
    $uuid .= substr($chars,12,4) . '-';
    $uuid .= substr($chars,16,4) . '-';
    $uuid .= substr($chars,20,12);

    return $uuid;
 }

   // setup the search path
   $path = 'ivef-php';
   set_include_path(get_include_path() . PATH_SEPARATOR . $path);

   // include the library
   require "IVEFParser.php";

   // get the data
   $raw = file_get_contents('php://input');
   
     // parse it
   $parser = new Parser();  
   $msg = $parser->parseXMLMessage($raw);
    
	// send the login response
   $body = $msg->getBody();
   $login = $body->getLoginRequest();
   $loginid = $msg->getHeader()->getMsgRefId();
   $result = false;
   if (($login->getName() == "John Doe") && ($login->getPassword() == "Very Secret")) {
	   $result = true;
   } 
   $msg = new MSG_LoginResponse();
   $header = new Header();
   $header->setMsgRefId(uuid());
   $msg->setHeader($header);
   $body = new Body();
   $response = new LoginResponse();
   $response->setMsgId($loginid);
   if ($result) {
		$response->setReason("authentication succeded");
		$response->setResult("1");
   } else {
		$response->setReason("authentication failed");
		$response->setResult("2");
   }	
   $body->setLoginResponse($response);
   $msg->setBody($body);
   
   echo $msg->toXML();

   // send the vesseldata
   if ($result) {
		$input = file_get_contents("logfile.xml");
		echo $input;
   }
?>
