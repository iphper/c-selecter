#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
    
/* 导入自定义函数文件 */
#include "lib/string.c"

/* 全局宏 */
#define LIST_LEN 100

/* 函数声明 */
// win系统主函数
int win_main(int, char* []);
// 初始化函数
void initialize(int, char* []);
// 渲染列表
void render_list();
// todo 监听键盘事件
int win_get_kbhit();
// todo 获取输入项

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
 * win系统主函数
 */
int win_main(int argc, char* argv[])
{
    initialize(argc, argv);
    printf("windows key: %d\n", win_get_kbhit());
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
            // 标题
            if (strcmp(key, "label") == 0) 
            {
                strcpy(label, param[1]);
            }
            // 列表
            else if(strcmp(key, "list[]") == 0)
            {
                // 列表保存
                list[listLen] = malloc(strlen(param[1]) * sizeof(char*));
                strcpy(list[listLen], param[1]);
                ++listLen;
                list = realloc(list, sizeof(char*));
            }
            // 默认
            else if(strcmp(key, "def") == 0)
            {
                def = atoi(param[1]);
            }
            // 其它参数
            else
            {
                // printf("其它参数:%s=%s\n", key, param[1]);
            }
        }
    }
}

/**
 * 函数: win_get_kbhit
 * 描述: win获取键盘按下的按键
 * 参数:
 * 返回:
 *     int 键值编码
 */
int win_get_kbhit()
{
    while(1)
    {
        if (_kbhit())
        {
            return _getch();
        }
    }
}

