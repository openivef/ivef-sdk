<?php

   // setup the search path
   $path = 'ivef-php';
   set_include_path(get_include_path() . PATH_SEPARATOR . $path);

   // include the library
   require "IVEFParser.php";

   // get the data
   echo "<html>\n<body>\n<h1>Ships in Port</h1>\n<p><table border=1>\n";
   $input = file_get_contents("logfile.xml");

   // parse it
   $parser = new Parser();  
   $msg = $parser->parseXMLMessage($input);
   $body = $msg->getBody();
	
	echo "<tr><th>Ship name</th><th>Callsign</th><th>MMSI</th><th>IMO</th><th>Destination</th></tr>\n";
	for ($i = 0; $i < $body->countOfVesselDatas(); $i++) {
		$vessel = $body->getVesselDataAt($i);
		if ( $vessel->countOfStaticDatas() > 0 ) {
			$static = $vessel->getStaticDataAt(0);
			echo "<tr><td>" . $static->getShipName();
			echo "</td><td>" . $static->getCallSign();
			echo "</td><td>" . $static->getMMSI();
			echo "</td><td>" . $static->getIMO();
			
			if ($vessel->countOfVoyages() > 0) {
				$voyage = $vessel->getVoyageAt(0);
				echo "</td><td>" . $voyage->getDestination();
			}
			
			echo "</td></tr>\n";
		}
	}
   
   echo "</table></p>\n</body>\n</html>\n";
?>
