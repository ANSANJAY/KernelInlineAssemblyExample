#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static inline unsigned long read_control_reg0(void)
{
	unsigned long val;
	asm volatile ( "mov %%cr0, %0" : "=r"(val) );
	return val;
}

static int __init test_hello_init(void)
{
	unsigned long cr0 = read_control_reg0();
	pr_info("cr0:%02lx\n", cr0);

	if (cr0 & (1 << 0))
		pr_info("processor is running in protected mode\n");
	else
		pr_info("processor is running in real mode\n");

	//check whether floating point is enabled or not
	if (cr0 & (1 << 2))
		pr_info("no floating point present\n");
	else
		pr_info("floating point present\n");

	
	if (cr0 & (1 << 31))
		pr_info("paging enabled\n");
	else
		pr_info("paging disabled\n");

	return 0;
}

static void __exit test_hello_exit(void)
{
}

module_init(test_hello_init);
module_exit(test_hello_exit);
