#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/vmalloc.h>

void myfunc1(void)
{
        char *ptr;
        printk(">>>> IN FUNCTION1 <<<<\n");
        ptr = vmalloc(10);
}

void myfunc2(void)
{
        char *ptr1, *ptr2;
        printk(">>>> IN FUNCTION2 <<<<\n");
        ptr1 = vmalloc(20);
        ptr2 = vmalloc(30);
}

void myfunc3(void)
{
        char *ptr;
        printk(">>>> IN FUNCTION3 <<<<\n");
        ptr = vmalloc(40);
        vfree(ptr);
}   
void myfunc4(void)
{
        char *ptr1, *ptr2;
        printk(">>>> IN FUNCTION4 <<<<\n");
        ptr1 = vmalloc(50);
        ptr2 = vmalloc(60);
        vfree(ptr2);
}
int hello_init(void)
{
        printk(KERN_ALERT "Hello World\n");
        myfunc1();
        myfunc2();
        myfunc3();
        myfunc4();
        return 0;
}
static void hello_exit(void)
{
        printk(KERN_ALERT "Goodbye World\n");
}
module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("test@gmail.com");
