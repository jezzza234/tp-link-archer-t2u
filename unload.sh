ifconfig ra0 down
rmmod mt7650u_sta_net.ko
rmmod mt7650u_sta.ko
rmmod mt7650u_sta_util.ko

lsmod | grep "mt7650"
