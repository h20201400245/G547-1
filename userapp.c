#include "chardev.h"

#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ioctl.h>
#define DEVICE_FILE_NAME "/dev/imu_char"
/////////////////////////////////////////////////////////////////

/* ioctl call 1*/

int gyro_readXaxis(int file_desc)
{
int ret_val=0;
int message=0;

ret_val=ioctl(file_desc, IOCTL_GY_READ_Xaxis,message);

if(ret_val==0)
{
printf("gyro Xaxis failed: %i\n",ret_val);
exit(-1);
}
printf("Reading in X axis in gyrometer: %d\n",ret_val);
return 0;
}
/* ioctl call 2*/
int gyro_readYaxis(int file_desc)
{
int ret_val;
char message[100];

ret_val=ioctl(file_desc, IOCTL_GY_READ_Yaxis,message);

if(ret_val==0)
{
printf("gyro y axis failed: %i\n",ret_val);
exit(-1);
}

printf("Reading in y axis in gyrometer: %d\n",ret_val);
return 0;
}

/*ioctl call 3*/
int gyro_readZaxis(int file_desc)
{
int ret_val;
char message[100];

ret_val=ioctl(file_desc, IOCTL_GY_READ_Xaxis,message);

if(ret_val<0)
{
printf("gyro_readZaxis failed: %d\n",ret_val);
exit(-1);
}

printf("Reading in Z axis in gyrometer %d\n",ret_val);
return 0;
}


/*ioctl call 4*/
int accelero_readXaxis(int file_desc)
{
int ret_val;
char message[100];

ret_val=ioctl(file_desc, IOCTL_ACC_READ_Xaxis,message);

if(ret_val<0)
{
printf("ACCELERO_readXaxis failed: %d\n",ret_val);
exit(-1);
}

printf("Reading in X axis in accelerometer %d\n",ret_val);
return 0;
}

/*ioctl call 5*/
int accelero_readYaxis(int file_desc)
{
int ret_val;
char message[100];
ret_val=ioctl(file_desc, IOCTL_ACC_READ_Yaxis,message);

if(ret_val<0)
{
printf("ACCELERO_readYaxis failed: %d\n",ret_val);
exit(-1);
}
printf("Reading in y axis in accelerometer %d\n",ret_val);
return 0;
}


/*ioctl call 6*/
int accelero_readZaxis(int file_desc)
{
int ret_val;
char message[100];
ret_val=ioctl(file_desc, IOCTL_ACC_READ_Zaxis,message);
if(ret_val<0)
{
printf("ioctl_ACCELERO_readZaxis failed: %d\n",ret_val);
exit(-1);
}
printf("Reading in Z axis in accelerometer %d\n",ret_val);
return 0;
}

/*ioctl call 7*/
int magneto_readXaxis(int file_desc)
{
int ret_val;
char message[100];
ret_val=ioctl(file_desc, IOCTL_MAG_READ_Xaxis,message);
if(ret_val<0)
{
printf("ioctl_MAGNETO_readXaxis failed: %d\n",ret_val);
exit(-1);
}
printf("Reading in X axis in magnetometer %d\n",ret_val);
return 0;
}

/*ioctl call 8*/

int magneto_readYaxis(int file_desc)
{
 int ret_val;
char message[100];
ret_val=ioctl(file_desc, IOCTL_MAG_READ_Yaxis,message);
if(ret_val<0)
{
printf("ioctl_MAGNETO_readYaxis failed: %d\n",ret_val);
exit(-1);
}
printf("Reading in Y axis in magnetometer %d\n",ret_val);
return 0;
}

/*ioctl call 9*/
int magneto_readZaxis(int file_desc)
{
int ret_val;
char message[100];
ret_val=ioctl(file_desc, IOCTL_MAG_READ_Zaxis,message);
if(ret_val<0)
{
printf("ioctl_MAG_readZaxis failed: %d\n",ret_val);
exit(-1);
}
printf("Reading in Z axis in magnetometer %d\n",ret_val);
return 0;
}

/*ioctl call 10*/
int ioctl_barometer_readPressure(int file_desc,int req_val)
{
int ret_val;
char msg[100];
if (req_val==9)
ret_val=ioctl(file_desc, IOCTL_barometer_readPressure, msg);
if(ret_val<0)
{
printf("ioctl_barometer_readPressure failed with req val: %d %d\n",ret_val,req_val);
exit(-1);
}
//printf("call 10: %d\n",ret_val);
printf("Reading in barometer %d\n",ret_val);
return 0;
}
/////////////////////////////////////////////////////////////////
int main()
{
int file_desc, ret_val;
char *msg="This is user space main program\n";

file_desc=open(DEVICE_FILE_NAME,O_RDONLY);
printf("%s returns %d\n",DEVICE_FILE_NAME,file_desc);
if (file_desc<0)
{
printf("Can't open device file %s\n", DEVICE_FILE_NAME);
exit(-1);
}

gyro_readXaxis(file_desc);
gyro_readYaxis(file_desc);
gyro_readZaxis(file_desc);

accelero_readXaxis(file_desc);
accelero_readYaxis(file_desc);
accelero_readZaxis(file_desc);

magneto_readXaxis(file_desc);
magneto_readYaxis(file_desc);
magneto_readZaxis(file_desc);

ioctl_barometer_readPressure(file_desc,9);

close(file_desc);
return 0;
}
////////////////////////////////////////////////////////////////
