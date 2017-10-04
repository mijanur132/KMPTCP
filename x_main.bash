#!/bin/bash

echo "::starting transmission with multipath off::"

#ip link set dev wlan1 multipath off
nmcli dev  disconnect iface wlan1

sleep 5

while true
do

iwlist wlan0 scan > /home/lab123/Desktop/list

sleep 10
	
/home/lab123/Desktop/srch list Qua 1_5GhZ > /home/lab123/Desktop/list1.txt
/home/lab123/Desktop/srch list Qua 1_5GhZ >> /home/lab123/Desktop/list2.txt

dmesg |grep rtt1 > /home/lab123/Desktop/rtt.txt
dmesg |grep lss1 > /home/lab123/Desktop/loss_rate_final.txt
sleep 5

/home/lab123/Desktop/main_file_lte loss.txt loss
      
sleep 5

  
done




