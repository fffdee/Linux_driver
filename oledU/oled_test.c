#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
 
int main(int argc, char **argv)
{
	int fd;
	char val;
	unsigned char buf[]="1234567890";
	float flight;
	fd = open("/dev/oled", O_RDWR);
	printf("oled init fisih!\n");
	if (fd < 0)
	{
		printf("can't open /dev/gy_sensor\n");
		return -1;
	}
	//usleep(200000);
	switch (argc){
	case 2:
	if (write(fd,argv[1],sizeof(argv[1]))){
	        
	         printf("Oled wirte ok!\r\n");
	     }
	     else{
	         printf("read err!\r\n");
	     }
	 break;
	case 3:
	if (write(fd,argv[2],sizeof(argv[2]))){
	        
		 write(fd,argv[3],sizeof(argv[3]));	        
	         printf("Oled wirte ok!\r\n");
	     }
	     else{
	         printf("read err!\r\n");
	     }
	 case 4:
	if (write(fd,argv[3],sizeof(argv[3]))){
	        
		 write(fd,argv[1],sizeof(argv[1]));
		 write(fd,argv[2],sizeof(argv[2]));	        
	         printf("Oled wirte ok!\r\n");
	     }
	     else{
	         printf("read err!\r\n");
	     }
	 break;
	 case 5:
	 if (write(fd,argv[2],sizeof(argv[2]))){
	        
		 write(fd,argv[3],sizeof(argv[3]));
		 write(fd,argv[4],sizeof(argv[4]));
		 write(fd,argv[5],sizeof(argv[5]));	        
	         printf("Oled wirte ok!\r\n");
	     }
	     else{
	         printf("read err!\r\n");
	     }
	 	break; 
	 default:
	 	printf("input arg num not in 1~4!\r\n");
	 	break;
	 }
		
	return 0;
}

