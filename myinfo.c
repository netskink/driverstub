#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/screen_info.h>
#include <asm/boot.h>
#include <asm/setup.h>



/* 
 * current cmd line
 * root=/dev/sda3 ro acpi_osi="Linux" initrd=../initramfs-linux.img BOOT_IMAGE=../vmlinuz-linux 
 *
 */

extern struct boot_params boot_params;

// get_range, get_option, get_options are global routines for accessing kernel
// command line parameters.


MODULE_LICENSE("Dual BSD/GPL");

static int myinfo_init(void) {
	__u16 screen_width;
	__u16 screen_height;
	

	printk(KERN_ALERT "[%s] myinfo_init\n",__this_module.name);

//	sprintf(buffer,"sprintf test  %s\n","test string");
//	printk( buffer);
//	printk("[%s] current jiffies: %lu.\n", __this_module.name, jiffies);

	screen_width=screen_info.lfb_width;
	screen_height=screen_info.lfb_height;
	printk("[%s] current screen width: %u.\n", __this_module.name, screen_width);
	printk("[%s] current screen height: %u.\n", __this_module.name, screen_height);




	return 0;

}

static void myinfo_exit(void) {

 printk(KERN_ALERT "[%s] myinfo_exit\n",__this_module.name);

}

module_init(myinfo_init);

module_exit(myinfo_exit);
