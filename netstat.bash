


#!/bin/bash

while true
do

netstat -s | egrep "DSACKs sent for" | sed -e "s/\tsignal: //" -e "s/\tSSID: //" | awk '{ORS = (NR % 2 == 0)? "\n" : " "; print}'>>/tmp/dack.txt

sleep 10

done

