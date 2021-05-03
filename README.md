# Adding-custom-System-Call-to-Linux-Kernal
Creating a custom system call in C, called sh_task_info(), which takes argument as PID. It search out the task_struct() corresponding to the PID and print out all the fields corresponding to it and also saves it in a file. The file name also needs to be supplied as an argument to the system call. <br/><br/>
Linux Kernel version: 5.9.1 <br/><br/>
Ubuntu : 20.04.1 LTS <br/><br/>
Detailed Explaination: writeup.pdf
