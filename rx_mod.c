     
	n++;
	printk(KERN_INFO "value of n....: %d\n", n);

        do_gettimeofday(&(g_last_packet_sdata->past_packet_times[g_last_packet_sdata->end]));

        if (ieee80211_has_retry(((struct ieee80211_hdr *)skb->data)->frame_control)) {

            g_last_packet_sdata->past_packet_delivered[g_last_packet_sdata->end] = 0;

        }

        else {

            g_last_packet_sdata->past_packet_delivered[g_last_packet_sdata->end] = 1;
		num_delivered++;

        }
         //palash

	if (n > 200)
	{
	 g_last_packet_sdata->loss_rate = 100 - (num_delivered * 100 / n);
	 printk(KERN_INFO "rx: num delivered packets on %s: %d\n", g_last_packet_sdata->dev->name, num_delivered);
         printk(KERN_INFO "rx: total packets on %s: %d\n", g_last_packet_sdata->dev->name, n);
         printk(KERN_INFO "rx: loss rate on %s: %d percent\n", g_last_packet_sdata->dev->name, g_last_packet_sdata->loss_rate);
	 n=0;
	}
