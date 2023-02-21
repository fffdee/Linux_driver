#include "stdio.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"
#include "stdlib.h"
#include "string.h"

/* 定义按键值 */
#define KEY0VALUE	0XF0
#define INVAKEY		0X00

/*
 * @description		: main主程序
 * @param - argc 	: argv数组元素个数
 * @param - argv 	: 具体参数
 * @return 			: 0 成功;其他 失败
 */
int main(int argc, char *argv[])
{
	int fd, ret;

	int keyvalue;
	
	if(argc != 3){
		printf("Error Usage!\r\n");
		return -1;
	}


	/* 打开gpio驱动 */
	if(argv[1]==0){
	fd = open("/dev/output-gpio", O_RDWR);
		if(fd < 0){
			printf("file %s open failed!\r\n", argv[1]);
			return -1;
		}
		if(write(fd,argv[2],sizeof(argv[2])))
		{
		
			printf("file %s write ok!\r\n", argv[1]);
		}
		
	}else
	{
		fd = open("/dev/input-gpio", O_RDWR);
		if(fd < 0){
			printf("file %s open failed!\r\n", argv[1]);
			return -1;
		}
		while(1) {
		read(fd, &keyvalue, sizeof(keyvalue));
			if (keyvalue == KEY0VALUE) {	/* KEY0 */
			printf("KEY0 Press, value = %#X\r\n", keyvalue);	/* 按下 */
			}
		
		}		
	}
	ret= close(fd);
	return 0;
}

