#include <stdlib.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int main(int argc, char *argv[])
{

    int pid;
    char name[256];
    printf("\nEnter the pid: ");
    scanf("%d",&pid);
    printf("Enter the file name: ");
    scanf("%s",name);
    
    long activity;
    activity = syscall(440, pid, name);

    if(activity < 0)
    {
        perror("Sorry,system call appears to have failed.");
    }

    else
    {
        printf("\nCongratulations! Your system call is functional.\nRun the command dmesg in the terminal and find out!\n\n");
    }

    return 0;
}

