cmake_minimum_required (VERSION 2.8)

project (GPIO)
#在CMakeLists.txt一開始加入相關設定：
#告知當前使用的是交叉編譯方式，必須配置
SET(CMAKE_SYSTEM_NAME Linux)
 
#指定C交叉編譯器,必須配置
#或交叉編譯器使用絕對地址
SET(CMAKE_C_COMPILER "/home/bango/tina-d1-h/prebuilt/gcc/linux-x86/riscv/toolchain-thead-glibc/riscv64-glibc-gcc-thead_20200702/bin/riscv64-unknown-linux-gnu-gcc")

add_executable(gpio_test gpio_test.c)
add_executable(gpio_write gpio_write.c)
add_executable(gpio_read gpio_read.c)

