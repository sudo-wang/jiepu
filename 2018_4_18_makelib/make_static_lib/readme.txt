这是制作静态库的方法：

1. vim myMath.c myMath.h mian.c        编辑相应的文件后
2. gcc -c myMath.c                     将此文件生成 myMath.o 的二进制文件
3. ar rc libstatic_lib.a myMath.o      将此二进制文件生成名为 static_lib 这个的静态库（静态库在此生生成）
4. gcc main.c -L. -lstatic_lib         将源文件 mian.c 链接静态库文件 static_lib 生层 a.out 这个可执行文件
5. ./a.out                             执行 a.out 验证
