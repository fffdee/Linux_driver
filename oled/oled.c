#include <linux/ide.h>
#include <linux/module.h>
#include <linux/i2c.h>
#include "oledfont.h"

struct class *oled_class;    /* 类 		*/
int oled_major;              /* 主设备号 */
struct i2c_client *oled_client;

static char buf_dev[100]= "DataOfKernel";
unsigned char str_count = 0;	//The count of String, display for oled
unsigned char y_value = 0;	//The value of current y-page value
// 构造i2c_msg通过这个client调用i2c_tansfer来读写
static int oled_write_reg(unsigned char addr,unsigned char cmd)
{
    int ret = -1;
    unsigned char data[2]={0};
    if(cmd==1){
    	data[0]=0x00;
    }else{
    	data[0]=0x40;
    }
    data[1]=addr;
    struct i2c_msg msgs;
    

    //printk("oled_client -> addr=%d\n", oled_client->addr);
    //printk("data[0]=%d\n", data[0]);
    //printk("data[1]=%d\n", data[1]);
    msgs.addr = oled_client->addr; //   OLED_ADDR，直接封装于i2c_msg
    msgs.buf = data;
    msgs.len = 2;   //长度1 byte
    msgs.flags = 0; //表示写

    ret = i2c_transfer(oled_client->adapter, &msgs, 1); 
    //这里都封装好了，本来根据i2c协议写数据需要先写入器件写地址，然后才能读
    if (ret < 0)
    {
        printk("i2c_transfer write err\n");
        return -1;
    }
    return 0;
}

static int oled_init_reg(void)
{
	//The list of oled-reg for init display
	oled_write_reg(0xAE, 1);
	oled_write_reg(0x00, 1);
	oled_write_reg(0x10, 1);
	oled_write_reg(0x40, 1);
	oled_write_reg(0xB0, 1);
	oled_write_reg(0x81, 1);
	oled_write_reg(0xFF, 1);
	oled_write_reg(0xA1, 1);
	oled_write_reg(0xA6, 1);
	oled_write_reg(0xA8, 1);
	oled_write_reg(0x3F, 1);
	oled_write_reg(0xC8, 1);
	oled_write_reg(0xD3, 1);
	oled_write_reg(0x00, 1);
	oled_write_reg(0xD5, 1);
	oled_write_reg(0x80, 1);
	oled_write_reg(0xD8, 1);
	oled_write_reg(0x05, 1);
	oled_write_reg(0xD9, 1);
	oled_write_reg(0xF1, 1);
	oled_write_reg(0xDA, 1);
	oled_write_reg(0x12, 1);
	oled_write_reg(0xDB, 1);
	oled_write_reg(0x30, 1);
	oled_write_reg(0x8D, 1);
	oled_write_reg(0x14, 1);
	oled_write_reg(0xAF, 1);
	
	return 0;
	
}
/************************************************************funtion_of_oled************************************************/
//funtion for draw a point in the oled-screen
static void OLED_Set_Pos(unsigned char x, unsigned char y) 
{ 	oled_write_reg(0xb0+y, 1);
	oled_write_reg(((x&0xf0)>>4)|0x10, 1);
	oled_write_reg((x&0x0f), 1);
} 


/*static int oled_read_reg(unsigned char *buf)
{
    int ret = -1;
    struct i2c_msg msg;
    msg.addr = oled_client->addr; // OLED_ADDR
    msg.buf = buf;
    msg.len = 2;                                            //长度1 byte
    msg.flags = I2C_M_RD;                                   //表示读
    ret = i2c_transfer(oled_client->adapter, &msg, 1); //这里都封装好了，本来根据i2c协议读数据需要先写入读地址，然后才能读
    if (ret < 0)
    {
        printk("i2c_transfer write err\n");
        return -1;
    }
    return 0;
}*/
static void OLED_ShowChar(unsigned char x,unsigned char y,unsigned char chr,unsigned char Char_Size)
{      	
	unsigned char c=0,i=0;	
		c=chr-' ';//得到偏移后的值			
		if(x>128-1){x=0;y=y+2;}
		if(Char_Size ==16)
			{
			OLED_Set_Pos(x,y);	
			for(i=0;i<8;i++)
			 oled_write_reg(F8X16[c*16+i],0);
			OLED_Set_Pos(x,y+1);
			for(i=0;i<8;i++)
			 oled_write_reg(F8X16[c*16+i+8],0);
			}
			else {	
				OLED_Set_Pos(x,y);
				for(i=0;i<6;i++)
				 oled_write_reg(F6x8[c][i],0);
				
			}
}
				  
//m^n函数
static unsigned char oled_pow(unsigned char m,unsigned char n)
{
	unsigned char result=1;	 
	while(n--)result*=m;    
	return result;
}				  
//显示2个数字
//x,y :起点坐标	 
//len :数字的位数
//size:字体大小
//mode:模式	0,填充模式;1,叠加模式
//num:数值(0~4294967295);
	 		  
static void OLED_ShowNum(unsigned char x,unsigned char y,unsigned int num,unsigned char len,unsigned char size2)
{         	
	unsigned char t,temp;
	unsigned char enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/oled_pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				OLED_ShowChar(x+(size2/2)*t,y,' ',size2);
				continue;
			}else enshow=1; 
		 	 
		}
	 	OLED_ShowChar(x+(size2/2)*t,y,temp+'0',size2); 
	}
} 

static void OLED_ShowString(unsigned char x,unsigned char y,unsigned char *chr,unsigned char Char_Size)
{
	unsigned char j=0;
	while (chr[j]!='\0')
	{		OLED_ShowChar(x,y,chr[j],Char_Size);
			x+=8;
		if(x>120){x=0;y+=2;}
			j++;
	}
}

/********************************************
// Clean
********************************************/
static void fill_picture(unsigned char fill_Data)
{
	unsigned char m,n;
	for(m=0;m<8;m++)
	{
		oled_write_reg(0xb0+m,1);		//page0-page1
		oled_write_reg(0x00,1);		//low column start address
		oled_write_reg(0x10,1);		//high column start address
		for(n=0;n<128;n++)
		{
				oled_write_reg(fill_Data,0);
		}
	}
}	

static ssize_t oled_show_str(struct file *file, const char __user *buf, size_t count, loff_t *off)	
{
	unsigned char err;
	str_count++;
	y_value = (str_count-1)*2;
    	printk("write to oled_\n");
	err = copy_from_user(buf_dev, buf, count);
	if(err<0){
		printk("write fail?!\r\n");
	}
	OLED_ShowString(0, y_value, buf_dev, 16);
	if(str_count>4)
	{
		
		
		
		fill_picture(0x00);   //Clean the screen
		str_count = 0;
		OLED_ShowString(0, y_value, buf_dev, 16); 	//Set Display
	}
	
	return 1;
}
	
// 初始OLED
int oled_open(struct inode *inode, struct file *file)
{
    printk("open oled_\n");
    
    fill_picture(0x00);
    return 0;
}


/*******************************************************************************************************/
/* oled 操作函数 */
static const struct file_operations oled_fops = {
    .owner = THIS_MODULE,
    .open = oled_open, 
    .write = oled_show_str
};

/* 构造一个platform_driver，
其中的of_match_table字段需要与 light-sensor@23 节点的compatible属性值一致，
当匹配时则调用platform_driver的probe函数 */
static const struct of_device_id ids[] =
{
    {.compatible = "oled,SSD1306"},
    {  }
};

// 在i2c_driver的probe函数中得到在总线驱动程序中解析得到的i2c_client,
// 并为该oeld注册一个字符设备
static int oled_probe(struct i2c_client *client,
                           const struct i2c_device_id *id)
{
    oled_client = client;

    printk("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);
    oled_major = register_chrdev(0, "oled", &oled_fops);
    oled_class = class_create(THIS_MODULE, "oled");
    device_create(oled_class, NULL, MKDEV(oled_major, 0), NULL, "oled"); /* /dev/oled */
    oled_init_reg();
    fill_picture(0x00);
    OLED_ShowString(2,1,"OLED driver",16);
    OLED_ShowString(16,5,"power by BanGO",8);
    return 0;
}

// 在platform_driver的remove函数中，注销该字符设备
static int oled_remove(struct i2c_client *client)
{
    device_destroy(oled_class, MKDEV(oled_major, 0));
    class_destroy(oled_class);
    unregister_chrdev(oled_major, "oled");

    return 0;
}

/* 分配/设置i2c_driver */
static struct i2c_driver oled_driver = {
    .driver = {
        .name = "SSD1306",
        .owner = THIS_MODULE,
        .of_match_table = ids,
    },
    .probe = oled_probe,
    .remove = oled_remove,
};

/*
 * @description	: 驱动入口函数
 */
static int __init oled_init(void)
{
    int ret = 0;

    ret = i2c_add_driver(&oled_driver);
    return ret;
}

/*
 * @description	: 驱动出口函数
 */
static void __exit oled_exit(void)
{
    i2c_del_driver(&oled_driver);
}

/* module_i2c_driver(bh1750_driver) */
module_init(oled_init);
module_exit(oled_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("BanGO");

