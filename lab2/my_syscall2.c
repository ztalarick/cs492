#include <linux/kernel.h>
#include <linux/sched.h> //task_pid_nr
#include <linux/module.h>
#include <linux/syscalls.h>

asmlinkage int sys_my_syscall2(char* str, int size){
	int i = 0;
	int result = 0;
	if(size > 128){
		return -1;
	}
	printk("my_syscall2: ");
	printk("Input: %s, ", str);

	while(str[i] != '\0'){
		if(str[i] == 'o'){
			str[i] = '0';
			result++;
		}
	i++;
	}
	printk("Number of changes: %d, ", result);
	printk("The input is now: %s, ", str);
	printk("PID: %d\n", (int) task_pid_nr(current));
	return result;
}
