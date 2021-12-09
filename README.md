# G547
INA 219 current sensor connected with Raspberry pi using I2C interface to measure shunt current and voltage. In this project 100 ohms resistor is used as shunt and led is used as load.

KERNEL SPACE DRIVER BUILD PROCESS :

• Build the driver by using Makefile (sudo make)

• Load the driver using sudo insmod main.ko

• Check whether module is inserter in kernel space with lsmod.

• Unload the driver using sudo rmmod main

USER SPACE APPLICATION BUILD PROCESS :

• Compile user application code with gcc -o output user.c

• Run the application (sudo ./output) after inserting kernel driver module.
