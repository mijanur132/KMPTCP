how does Energy paper works:
It has one component to detect banwidth shortage using mathis equaton:
This is implemented in TCP_OUTPUT.txt

BW shortage is achieved by first measuring RTT and loss rate from the kernel. And then we calculate prediction of bandwidth using mathis equation

BW=0.93*MSS/(sqrt(loss)*RTT)

then we calculate gap ration:

gap ratio= (predicted-achieved)/achieved*100

If gap ratio falls below +10, we assume bandwidth shortage. 


fromthis file we get RTT estimated at the receiver and number of retransmission per 500 ack which we take as a loss rate. 
we print this values using printk and in the command line can be retrieved using dmesg.

Next part is done by "x_main.bash" this file filter dmesg command to have loss rate, RTT and current ifstat bandwidth and save those in txt file in the same folder as this bash script. 
"main_file.c" open files written by "x_main.bash" and execute the logics to add or delete MPTCP
add, delete is done using "ip link" command

for RSSI condtion we use iwlist. Save the output in a text file and then filter to keep only RSSI information. We keep only the APs with enough bandwidth in the file. 



necessary files:
tcp_output.txt
search.c
main_file.c
x_main.bash
powercommand.bash



NB: keep all files in the same folder and run executables from that folder. 
only running x_main.bash while keeping all the files and executables in the same folder will keep the system running. 

For energy measurement run the script file ./powercommand


