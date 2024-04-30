# Makefile
# 使用make来编译

# lib下的所有文件
LIBS := -I./lib

# 主入口
main : main.c
	gcc $(LIBS) main.c -o ./build/selecter