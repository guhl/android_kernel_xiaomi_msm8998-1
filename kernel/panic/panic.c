#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int8_t* message = "Guhl caused a kernel panic!";

static int panic_init(void) {
  panic(message);
  return 0;
}

static void panic_exit(void) {
  printk("This will never happen\n");
}

module_init(panic_init);
module_exit(panic_exit);

