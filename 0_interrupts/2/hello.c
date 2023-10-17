#include <linux/module.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/irqflags.h>

void is_irq_disabled(void)
{
	if (irqs_disabled())
		pr_info("IRQ Disabled\n");
	else
		pr_info("IRQ Enabled\n");
}

static int __init my_init(void)
{
	pr_info("module is loaded on processor:%d\n", smp_processor_id());
	asm volatile("cli": : :"memory");
	is_irq_disabled();
	mdelay(10000L);;
	asm volatile("sti": : :"memory");
	is_irq_disabled();
	return 0;
}

static void __exit my_exit(void)
{
}

MODULE_LICENSE("GPL");
module_init(my_init);
module_exit(my_exit);
