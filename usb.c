#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include <linux/hid.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Eudyptula Task 04 - USB Keyboard Autoloading Driver");
MODULE_VERSION("1.0");

static const struct usb_device_id usb_kbd_table[] = {
	{ USB_INTERFACE_INFO(
		USB_INTERFACE_CLASS_HID,
		USB_INTERFACE_SUBCLASS_BOOT,
		USB_INTERFACE_PROTOCOL_KEYBOARD) },
	{ }
};

MODULE_DEVICE_TABLE(usb, usb_kbd_table);

static struct usb_driver hello_keyboard_driver = {
    .name       = "hello_keyboard",
    .id_table = usb_kbd_table,
};

static int __init hello_init(void)
{
    pr_info("Eudyptula Task 04: USB Keyboard driver loaded!\n");
    return usb_register(&hello_keyboard_driver);
}

static void __exit hello_exit(void)
{
    pr_info("Eudyptula Task 04: USB Keyboard driver unloaded!\n");
    usb_deregister(&hello_keyboard_driver);
}

module_init(hello_init);
module_exit(hello_exit);

