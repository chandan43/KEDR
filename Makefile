EXTRA_CFLAGS=-g
obj-m := test-kernel.o
test-kernel-objs := test.o

KDIR=/lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	make -C $(KDIR) M=$(PWD) clean
