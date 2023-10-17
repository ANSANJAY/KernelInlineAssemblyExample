#include <linux/module.h>
#include <linux/kernel.h>

static int myinit(void)
{
	//we are trying to access invalid memory location
	*(int *)0x12 = 'a';

	return 0;
}

static void myexit(void)
{
	pr_info("myexit\n");
}

module_init(myinit)
module_exit(myexit)
MODULE_LICENSE("GPL");
