#!/bin/bash

while true
do

		nmcli dev  disconnect iface wlan1
  echo "delte"
	sleep 30
	

	 
	#nmcli connection up id OpenWrt1_5GhZ iface wlan1

	nmcli dev wifi connect OpenWrt1_5GhZ password ascp2016 iface wlan1

  echo "connect"
   	sleep 10

done


