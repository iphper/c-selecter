#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 导入自定义函数文件 */
#include "lib/string.c"

/* 全局宏 */
#define LIST_LEN 100

/* 函数声明 */
// win系统主函数
int win_main(int, char* []);
// linux系统主函数
int linux_main(int, char* []);
// 初始化函数
void initialize(int, char* []);

/* 全局变量 */
// 参数列表
char* params[] = {};

// 选择列表
char** list;

// 提示信息
char* label = "请选择：";

// 默认选中项
int def = -1;

/**
 * 主函数
 * @param int argc
 * @param char*[] argv
 * @return int
 * @author gping
 */
int main(int argc, char* argv[])
{
    // 宏判断系统执行对应的系统主函数
    #ifdef _WIN32
        return win_main(argc, argv);
    #elif __linux__
        return linux_main(argc, argv);
    #endif
}

/**
 * win系统主函数
 */
int win_main(int argc, char* argv[])
{
    initialize(argc, argv);
    printf("windows\n");
    return 0;
}

/**
 * linux系统主函数
 */
int linux_main(int argc, char* argv[])
{
    initialize(argc, argv);
    printf("linux\n");
    return 0;
}

/**
 * initialize 初始化函数
 * 获取参数
 * 调用示例 xxx --list[]=a --list[]=b --tip=tip_text --
 */
void initialize(int argc, char* argv[])
{
    // 为list申请内存
    list = malloc(sizeof(char*));
    char **param;
    char *line;
    int listLen = 0;
    for(int i = 1; i < argc; ++i) 
    {
        param = str_split(argv[i], "=");
        if (2 <= str_count(param))
        {
            char key[strlen(param[0])];
            strcpy(key, param[0]);
            // 去除两个--
            memmove(key, key+2, strlen(key) + 1);

            // 对参数进行保存
            if (strcmp(key, "label") == 0) 
            {
                strcpy(label, param[1]);
            }
            else if(strcmp(key, "list[]") == 0)
            {
                // 列表保存
            }
            else
            {
                printf("其它参数:%s=%s\n", key, param[1]);
            }
        }
    }
}

