#设置编译链路径及工具
CTOOL := riscv64-unknown-linux-gnu-
CCL := /home/bango/work
CC := ${CCL}/bin/${CTOOL}gcc

#设置编译规则
hello_word:hello_word.c
    ${CC} -o hello_word hello_word.c

#清理规则
clean:
    rm hello_word
    
