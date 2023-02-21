
#include "stdio.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"
#include "stdlib.h"
#include "string.h"

/* 定义按键值 */
#define KEY0VALUE		0XF0
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


	
	if(argc != 2){
		printf("Error Usage!\r\n");
		return -1;
	}
	fd = open("/dev/output-gpio", O_RDWR);
		if(fd < 0){
			printf("file %s open failed!\r\n", argv[1]);
			return -1;
		}
	write(fd,argv[2],sizeof(argv[2]));
	
		
		printf(" %s write ok!\r\n", argv[1]);
	

	
	ret= close(fd);
	return 0;
}

