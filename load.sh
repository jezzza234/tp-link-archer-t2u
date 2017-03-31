rm -rf /etc/Wireless/RT2870STA/
mkdir /etc/Wireless/RT2870STA/
cp ./MODULE/conf/RT2870STA.dat /etc/Wireless/RT2870STA/RT2870STA.dat
chmod 777 -R /etc/Wireless/RT2870STA
insmod ./UTIL/os/linux/mt7650u_sta_util.ko 
insmod ./MODULE/os/linux/mt7650u_sta.ko    
insmod ./NETIF/os/linux/mt7650u_sta_net.ko
lsmod | grep "mt7650"
ifconfig ra0 up
