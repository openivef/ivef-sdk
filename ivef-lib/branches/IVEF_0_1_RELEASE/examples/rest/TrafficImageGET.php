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

   // get the credentials
   $name = $_GET['user'];
   $password = $_GET['password'];

   // check the credentials
   if (($name != "chris") || ($password != "lukassen")) {
	   // send the login response
	   $body = $msg->getBody();
	   $login = $body->getLoginRequest();
	   $loginid = $msg->getHeader()->getMsgRefId();
	   $msg = new MSG_LoginResponse();
	   $header = new Header();
	   $header->setMsgRefId(uuid());
	   $msg->setHeader($header);
	   $body = new Body();
	   $response = new LoginResponse();
	   $response->setMsgId("unknown, http login used");
	   $response->setReason("authentication failed");
	   $response->setResult("2");
	   $body->setLoginResponse($response);
	   $msg->setBody($body);
	   echo $msg->toXML();
   } else {
   	   // send the vesseldata
	   $input = file_get_contents("logfile.xml");
	   echo $input;
   }
?>
