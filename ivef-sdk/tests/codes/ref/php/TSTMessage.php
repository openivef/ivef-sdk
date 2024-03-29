<?php

// 
//  Message
//
//  Message is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Message is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY ); without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//*********************************************************************************
//  WARNING: THIS CODE WAS GENERATED DO NOT MODIFY, CHANGE THE XSD INSTEAD
//  Generated by schema2code on Tue Jan 8 23:43:29 2013.
//*********************************************************************************
//  Copyright 2010
//


class Message { 

    var $m_argument; // default value is uninitialized
    var $m_argumentPresent;
    var $m_timeStamp; // default value is uninitialized
    var $m_timeStampPresent;
    var $m_code; // default value is uninitialized
    var $m_codePresent;
    var $m_version; // default value is uninitialized
    var $m_versionPresent;

    public function Message() {

        date_default_timezone_set('UTC');
        $this->m_argumentPresent = false;
        $this->m_arguments = array();
        $this->m_timeStampPresent = false;
        $this->m_codePresent = false;
        $this->m_version = "1.0.0";
        $this->m_versionPresent = true;
    }

    public function removeArgument(String $val ) {
        if ( count($this->m_arguments) <= 0) {
            return false; // scalar already at minOccurs
        }
        for($i=0; $i< count($this->m_arguments); $i++) {
            if($this->m_arguments[i] == $val) {
                unset($this->m_arguments[i]);
            }
        }
        return true;
    }

    public function addArgument(String $val ) {
        if ( count($this->m_arguments) >= 10) {
            return false; // scalar already at maxOccurs
        }

        if (strlen ($val) < 1)
            return false;
        if (strlen ($val) > 1024)
            return false;
        $this->m_arguments[] = $val;
        return true;
    }

    public function getArgumentAt($i) {

        return $this->m_arguments[$i];
    }

    public function countOfArguments() {

        return count($this->m_arguments);
    }

    public function setTimeStamp( $val ) {

        $this->m_timeStampPresent = true;
        $this->m_timeStamp = $val;
        return true;
    }

    public function getTimeStamp() {

        return $this->m_timeStamp;
    }

    public function setCode( $val ) {

        if ( ( $val != 1 ) &&
             ( $val != 2 ) &&
             ( $val != 3 ) )
            return false;
        $this->m_codePresent = true;
        $this->m_code = $val;
        return true;
    }

    public function getCode() {

        return $this->m_code;
    }

    public function setVersion( $val ) {

        $this->m_versionPresent = true;
        $this->m_version = $val;
        return true;
    }

    public function getVersion() {

        return $this->m_version;
    }

    public function toXML($outputNamespace = true) {

        if ($outputNamespace)
        {
            $rootNodeTag  = "<Message";
            $rootNodeTag .= " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"";
            $rootNodeTag .= " xmlns=\"http://www.mvi.org/XMLSchema/mvi/2.0\"";
            $rootNodeTag .= "></Message>";
        }
        else
            $rootNodeTag = "<Message></Message>";
        $xml = new SimpleXMLElement($rootNodeTag);

        if ( $this->m_timeStampPresent ) {
            $xml->addAttribute('TimeStamp', $this->m_timeStamp);
        } else { 
            return ""; // not all required attributes have been set 
        } 
        if ( $this->m_codePresent ) {
            $xml->addAttribute('Code', $this->m_code);
        } else { 
            return ""; // not all required attributes have been set 
        } 
        if ( $this->m_versionPresent ) {
            $xml->addAttribute('Version', $this->m_version);
        } else { 
            return ""; // not all required attributes have been set 
        } 
        if ( count($this->m_arguments) < 0) {
            return ""; // not enough values
        }
        if ( count($this->m_arguments) > 10) {
            return ""; // too much values
        }
        foreach($this->m_arguments as $attribute) {
            $xml->addChild('Argument', $this->m_argument);
        } 
        return $xml->asXML();
    }

    public function toString() {

    	return $this->toStringWithLead("");
    }

    public function toStringWithLead( $lead ) {

        $str = $lead . "Message\n";

        $str .= $lead . "    TimeStamp = " . $this->m_timeStamp . "\n";
        $str .= $lead . "    Code = " . $this->m_code . "\n";
        $str .= $lead . "    Version = " . $this->m_version . "\n";
        foreach($this->m_arguments as $attribute) {
           $str .= $attribute->toStringWithLead($lead . "    ");
        }

        return $str;
    }
}
?>
