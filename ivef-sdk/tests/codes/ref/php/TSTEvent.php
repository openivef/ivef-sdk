<?php

// 
//  Event
//
//  Event is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Event is distributed in the hope that it will be useful,
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


class Event { 

    var $m_areaName; // default value is uninitialized
    var $m_areaNamePresent;
    var $m_name; // default value is uninitialized
    var $m_namePresent;
    var $m_id; // default value is uninitialized
    var $m_idPresent;
    var $m_speed; // default value is uninitialized
    var $m_speedPresent;

    public function Event() {

        date_default_timezone_set('UTC');
        $this->m_areaNamePresent = false;
        $this->m_areaName = new String();
        $this->m_namePresent = false;
        $this->m_idPresent = false;
        $this->m_speedPresent = false;
    }

    public function setAreaName( $val ) {

        if (strlen ($val) < 1)
            return false;
        if (strlen ($val) > 36)
            return false;
        $this->m_areaNamePresent = true;
        $this->m_areaName = $val;
        return true;
    }

    public function getAreaName() {

        return $this->m_areaName;
    }

    public function hasAreaName() {

        return $this->m_areaNamePresent;
    }

    public function setName( $val ) {

        if (strlen ($val) < 1)
            return false;
        if (strlen ($val) > 36)
            return false;
        $this->m_namePresent = true;
        $this->m_name = $val;
        return true;
    }

    public function getName() {

        return $this->m_name;
    }

    public function hasName() {

        return $this->m_namePresent;
    }

    public function setId( $val ) {

        if ($val <= 0)
          return false;
        if ($val >= 10000)
          return false;
        $this->m_idPresent = true;
        $this->m_id = $val;
        return true;
    }

    public function getId() {

        return $this->m_id;
    }

    public function hasId() {

        return $this->m_idPresent;
    }

    public function setSpeed( $val ) {

        if ($val < 0)
          return false;
        if ($val > 1000.1)
          return false;
        $this->m_speedPresent = true;
        $this->m_speed = $val;
        return true;
    }

    public function getSpeed() {

        return $this->m_speed;
    }

    public function hasSpeed() {

        return $this->m_speedPresent;
    }

    public function toXML($outputNamespace = true) {

        if ($outputNamespace)
        {
            $rootNodeTag  = "<Event";
            $rootNodeTag .= " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"";
            $rootNodeTag .= " xmlns=\"http://www.mvi.org/XMLSchema/mvi/2.0\"";
            $rootNodeTag .= "></Event>";
        }
        else
            $rootNodeTag = "<Event></Event>";
        $xml = new SimpleXMLElement($rootNodeTag);

        if ( $this->hasName() ) {
            $xml->addAttribute('Name', $this->m_name);
        }
        if ( $this->hasId() ) {
            $xml->addAttribute('Id', $this->m_id);
        }
        if ( $this->hasSpeed() ) {
            $xml->addAttribute('Speed', number_format($this->m_speed, 2));
        }
        if ( $this->hasAreaName() ) {
            $xml->addChild('AreaName', $this->m_areaName);
        } 
        return $xml->asXML();
    }

    public function toString() {

    	return $this->toStringWithLead("");
    }

    public function toStringWithLead( $lead ) {

        $str = $lead . "Event\n";

        if ( $this->hasName() ) {
            $str .= $lead . "    Name = " . $this->m_name . "\n";
        }
        if ( $this->hasId() ) {
            $str .= $lead . "    Id = " . $this->m_id . "\n";
        }
        if ( $this->hasSpeed() ) {
            $str .= $lead . "    Speed = " . number_format($this->m_speed, 2) . "\n";
        }
        if ( $this->hasAreaName() ) {
            $str .= $lead . " " ;
            $str .= "AreaName = " ;
            $str .= $this->m_areaName ;
            $str .= "\n" );

        return $str;
    }
}
?>
