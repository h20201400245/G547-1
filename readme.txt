Block Device driver 

Download the main.c and Makefile

make : to make the kernel object file

Go to the directory in which code is downloaded and give the command $ make all

Insert the Object file into the kernel using sudo insmod main.ko

Check if module is loaded using lsmod command

Check the partition details that we have created using cat /proc/partitions also check using ls -l /dev/dof* or sudo fdisk -l

Take root access using sudo -s command

To enter input into disk use cat > /dev/dof ,type something & press enter to read back from the disk on command line use command xxd /dev/dof | less

Remove the module from kernel using sudo rmmod main.ko