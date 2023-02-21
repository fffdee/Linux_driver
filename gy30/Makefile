
#设置编译链路径及工具
CTOOL := riscv64-unknown-linux-gnu-
CCL := /home/bango/work
CC := ${CCL}/bin/${CTOOL}gcc

#设置编译规则
gy30.o:gy30.c
    /home/bango/tina-d1-h/prebuilt/gcc/linux-x86/riscv/toolchain-thead-glibc/riscv64-glibc-gcc-thead_20200702/bin/riscv64-unknown-linux-gnu-gcc -c gy30.c 

#清理规则
clean:
    rm gy30
    
