<?php

// 
//  Schema
//
//  Schema is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Schema is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY ); without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//*********************************************************************************
//  WARNING: THIS CODE WAS GENERATED DO NOT MODIFY, CHANGE THE XSD INSTEAD
//  Generated by schema2code on Tue Jan 8 23:30:39 2013.
//*********************************************************************************
//  Copyright 2010
//


class Schema { 


    public function Schema() {

        date_default_timezone_set('UTC');
    }

    public function getElementFormDefault() {

        return "qualified";
    }

    public function getTargetNamespace() {

        return "http://www.mvi.org/XMLSchema/mvi/2.0";
    }

    public function toXML($outputNamespace = true) {

        if ($outputNamespace)
        {
            $rootNodeTag  = "<Schema";
            $rootNodeTag .= " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"";
            $rootNodeTag .= " xmlns=\"http://www.mvi.org/XMLSchema/mvi/2.0\"";
            $rootNodeTag .= "></Schema>";
        }
        else
            $rootNodeTag = "<Schema></Schema>";
        $xml = new SimpleXMLElement($rootNodeTag);

        return $xml->asXML();
    }

    public function toString() {

    	return $this->toStringWithLead("");
    }

    public function toStringWithLead( $lead ) {

        $str = $lead . "Schema\n";


        return $str;
    }
}
?>
