
obj-m := assmt.o

KDIR= /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
	gcc -o ioctlusr assmt_ioctl.c
