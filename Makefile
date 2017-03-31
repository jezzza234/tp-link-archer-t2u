
all:
	make -C UTIL/ osutil
	$(SHELL) cp_util.sh
	make -C MODULE/ build_tools
	make -C MODULE/ osdrv
	$(SHELL) cp_module.sh
	make -C NETIF/ osnet

clean:
	make -C UTIL/ clean
	make -C MODULE/ clean
	make -C NETIF/ clean

install:
	make -C UTIL/ install_util
	make -C MODULE/ install
	make -C NETIF/ install_netif

uninstall:
	make -C UTIL/ uninstall
	make -C MODULE/ uninstall
	make -C NETIF/ uninstall
