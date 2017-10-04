#!/bin/bash

while true
do

#iw dev wlan0 scan | egrep "signal|SSID" | sed -e "s/\tsignal: //" -e "s/\tSSID: //" | awk '{ORS = (NR % 2 == 0)? "\n" : " "; print}' | grep OpenWrt1_5GhZ >> /tmp/rssi.txt 

#iwlist wlan0 scanning | egrep 'Quality|ESSID' | awk '{ORS = (NR % 2 == 0)? "\n" : " "; print}' | grep OpenWrt1_5GhZ
iwlist wlan0 scan

sleep 10

done


#netstat -s | egrep "send|retransmit" | sed -e "s/\tsignal: //" -e "s/\tSSID: //" | awk '{ORS = (NR % 2 == 0)? "\n" : " "; print}'



