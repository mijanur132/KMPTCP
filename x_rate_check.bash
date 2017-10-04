#!/bin/bash

while true
do

	ifstat -n -i  wlan0 2 1 >  /home/lab123/Desktop/rate_primary.txt
	ifstat -n -i  wlan1 2 1 >  /home/lab123/Desktop/rate_secondary.txt
	
	dmesg |grep rtt1 > /home/lab123/Desktop/rtt.txt
	dmesg |grep lss1 > /home/lab123/Desktop/loss_rate_final.txt
	sleep 5
	/home/lab123/Desktop/main_file_lrf >> /home/lab123/Desktop/main_file_lrf.txt
	
        sleep 10
	
	
	   
done




