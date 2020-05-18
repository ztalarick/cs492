#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	printf("Zachary Talarick, PID: %ld\n", getpid());
	//my_syscall
	long int amma = syscall(548, 5, 6);
	printf("my_syscall(5, 6): %ld\n", amma);

	//my_syscall2
	char string[] = "hello world";
	long int amma2 = syscall(549, &string, sizeof(string));
	printf("my_syscall2(hello world, 11): %ld\n", amma2);
	printf("The string 'hello world' is now: %s\n", string);

	//my_syscall2 error over 128 bytes
	char big_string[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	long int amma3 = syscall(549, &big_string, sizeof(big_string));
	printf("my_syscall2(a large number of a's): %ld\n", amma3);
	return 0;
}
