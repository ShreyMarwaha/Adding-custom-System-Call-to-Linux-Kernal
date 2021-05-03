#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/file.h> 
#include <linux/fs.h>
#include <linux/fcntl.h> 
#include <asm/uaccess.h> 
#include <uapi/asm-generic/errno-base.h>


SYSCALL_DEFINE2(sh_task_info,int,pid,char*,filename) 
{
	struct task_struct *task; 
	struct file *file;
	loff_t pos;
	char buf[256];
	long copied;
	char data[1024];
  	int flag;
	
	if (pid >= 32768 || pid <= 0)
		return -EINVAL;
	
	pos = 0;
  	copied = strncpy_from_user(buf, filename, sizeof(buf));
  	
  	if (copied < 0 || copied == sizeof(buf))
    		return -EFAULT;
    	
	file = filp_open(buf, O_WRONLY|O_CREAT, 0644);

	
	flag = 0;
	for_each_process(task)
	{
		if ((int)task->pid == pid)
		{
			flag = 1;
			
			printk("\nPROCESS: %s\nPID_NUMBER: %ld\nPROCESS STATE: %ld\nPRIORITY: %ld\nRT_PRIORITY: %ld\nSTATIC PRIORITY: %ld\nNORMAL PRIORITY: %ld\n", task->comm, (long)task_pid_nr(task), (long)task->state, (long)task->prio, (long)task->rt_priority, (long)task->static_prio, (long)task->normal_prio);


			sprintf(data, "\nProcess: %s\nPID_NUMBER: %ld\nPROCESS STATE: %ld\nPRIORITY: %ld\nRT_PRIORITY: %ld\nSTATIC PRIORITY: %ld\nNORMAL PRIORIY: %ld\n", task->comm, (long)task_pid_nr(task), (long)task->state, (long)task->prio, (long)task->rt_priority, (long)task->static_prio, (long)task->normal_prio);
			
			
			kernel_write(file, data, strlen(data), &pos);
		}
		
	}
	
	if (flag==0)
	{
		return -ESRCH;
	}
	
	return 0;
}
