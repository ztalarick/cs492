#include <linux/kernel.h>
#include <linux/sched.h> //task_pid_nr
#include <linux/module.h>
#include <linux/syscalls.h>

asmlinkage int sys_my_syscall(int a, int b){
	int pid = task_pid_nr(current);
	printk("My Syscall: ");
	printk("%d + %d = %d, ", a, b, a + b);
	printk("PID: %d\n", pid);
	return a + b;
}
