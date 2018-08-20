这是制作共享库的方法：

1. vim myMath.c myMath.h mian.c         编辑相应的文件后
2. gcc -c -fPIC myMath.c                将此文件生成 myMath.o 的二进制文件( -fPIC 是生成与地址无关的库 )
3. gcc -shared myMath.o -o libdynamic_lib.so                                               将此二进制文件生成名为 dynamic_lib 这个的共享库（共享库在此生成）
4. gcc main.c -L. -ldynamic_lib         将源文件 mian.c 链接共享库文件 static_lib 生层 a.out 这个可执行文件
5. export LD_LIBRARY_PATH=./            添加环境变量, 将当前目录加入 LD_LIBRARY_PATH
6. ./a.out                              执行 a.out 验证
