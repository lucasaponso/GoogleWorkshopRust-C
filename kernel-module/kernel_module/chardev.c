#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "/dev/chardev"

static int major_number;
static char message[256] = "Hello from the kernel!\n";
static short size_of_message;

static int device_open(struct inode *inode, struct file *file) {
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) {
    int bytes_read = 0;

    // Copy message to user buffer
    if (*offset == 0) {
        bytes_read = simple_read_from_buffer(buffer, length, offset, message, size_of_message);
    }

    return bytes_read;
}

static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset) {
    // Clear the message buffer
    memset(message, 0, sizeof(message));

    // Copy data from user buffer to kernel message buffer
    if (copy_from_user(message, buffer, length) != 0) {
        return -EFAULT; // Return an error if copy fails
    }

    size_of_message = length;
    return length;
}

static struct file_operations fops = {
    .read = device_read,
    .write = device_write, // Add write function
    .open = device_open,
    .release = device_release,
};

static int __init chardev_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "Registered correctly with major number %d\n", major_number);
    size_of_message = strlen(message);
    return 0;
}

static void __exit chardev_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Goodbye, world!\n");
}

MODULE_LICENSE("GPL");
module_init(chardev_init);
module_exit(chardev_exit);
