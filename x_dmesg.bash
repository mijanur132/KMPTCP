#!/bin/bash

while true
do

	dmesg | grep loss >  /home/lab123/Desktop/loss.txt
	dmesg -c
       sleep 20
	
	   
done




