<?php

// 
//  MSG_Notification
//
//  MSG_Notification is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  MSG_Notification is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY ); without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//*********************************************************************************
//  WARNING: THIS CODE WAS GENERATED DO NOT MODIFY, CHANGE THE XSD INSTEAD
//  Generated by schema2code on Tue Jan 8 23:42:58 2013.
//*********************************************************************************
//  Copyright 2010
//

require_once "TSTEvent.php";
require_once "TSTMessage.php";

class MSG_Notification { 

    var $m_event; // default value is uninitialized
    var $m_eventPresent;
    var $m_message; // default value is uninitialized
    var $m_messagePresent;

    public function MSG_Notification() {

        date_default_timezone_set('UTC');
        $this->m_eventPresent = false;
        $this->m_events = array();
        $this->m_messagePresent = false;
        $this->m_messages = array();
    }

    public function removeEvent(Event $val ) {
        if ( count($this->m_events) <= 0) {
            return false; // scalar already at minOccurs
        }
        for($i=0; $i< count($this->m_events); $i++) {
            if($this->m_events[i] == $val) {
                unset($this->m_events[i]);
            }
        }
        return true;
    }

    public function addEvent(Event $val ) {

        $this->m_events[] = $val;
        return true;
    }

    public function getEventAt($i) {

        return $this->m_events[$i];
    }

    public function countOfEvents() {

        return count($this->m_events);
    }

    public function removeMessage(Message $val ) {
        if ( count($this->m_messages) <= 0) {
            return false; // scalar already at minOccurs
        }
        for($i=0; $i< count($this->m_messages); $i++) {
            if($this->m_messages[i] == $val) {
                unset($this->m_messages[i]);
            }
        }
        return true;
    }

    public function addMessage(Message $val ) {

        $this->m_messages[] = $val;
        return true;
    }

    public function getMessageAt($i) {

        return $this->m_messages[$i];
    }

    public function countOfMessages() {

        return count($this->m_messages);
    }

    public function toXML($outputNamespace = true) {

        if ($outputNamespace)
        {
            $rootNodeTag  = "<MSG_Notification";
            $rootNodeTag .= " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"";
            $rootNodeTag .= " xmlns=\"http://www.mvi.org/XMLSchema/mvi/2.0\"";
            $rootNodeTag .= "></MSG_Notification>";
        }
        else
            $rootNodeTag = "<MSG_Notification></MSG_Notification>";
        $xml = new SimpleXMLElement($rootNodeTag);

        if ( count($this->m_events) < 0) {
            return ""; // not enough values
        }
        foreach($this->m_events as $attribute) {
        $dom = dom_import_simplexml($xml);
        $child_as_xml = $attribute->toXML(false);
        $child_as_simplexml = new SimpleXMLElement($child_as_xml);
        $child_as_dom = dom_import_simplexml($child_as_simplexml);
        $child_as_leaf = $dom->ownerDocument->importNode($child_as_dom, true);
        $dom->appendChild($child_as_leaf);
        $xml = simplexml_import_dom($dom);
        } 
        if ( count($this->m_messages) < 0) {
            return ""; // not enough values
        }
        foreach($this->m_messages as $attribute) {
        $dom = dom_import_simplexml($xml);
        $child_as_xml = $attribute->toXML(false);
        $child_as_simplexml = new SimpleXMLElement($child_as_xml);
        $child_as_dom = dom_import_simplexml($child_as_simplexml);
        $child_as_leaf = $dom->ownerDocument->importNode($child_as_dom, true);
        $dom->appendChild($child_as_leaf);
        $xml = simplexml_import_dom($dom);
        } 
        return $xml->asXML();
    }

    public function toString() {

    	return $this->toStringWithLead("");
    }

    public function toStringWithLead( $lead ) {

        $str = $lead . "MSG_Notification\n";

        foreach($this->m_events as $attribute) {
           $str .= $attribute->toStringWithLead($lead . "    ");
        }
        foreach($this->m_messages as $attribute) {
           $str .= $attribute->toStringWithLead($lead . "    ");
        }

        return $str;
    }
}
?>
