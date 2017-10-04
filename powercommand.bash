#!/bin/bash

while true
do

	echo - | awk "{printf \"%.1f\n\",	$(($(cat /sys/class/power_supply/BAT0/current_now) * $(cat /sys/class/power_supply/BAT0/voltage_now))) / 1000000000000 }" >>/tmp/powerfile_60.txt

        sleep 1
done

