#include <stdlib.h>
#include <string.h>

// 定义遍历回调
typedef void(* str_each_call_fun)(char*);

/**
 * 函数: str_find_count
 * 描述: 查询子串个数
 * 参数:
 *   str (char const *): 原字符串
 *   c (char const *): 子字符串
 * 返回:
 *   int 个数
 */
int str_find_count(char* const str, char* const c)
{
    int count = 0;
    const char *item;

    item = strtok(str, c);
    while(item != NULL) {
        ++count;
        item = strtok(NULL, c);
    }

    return count;
}

/**
 * 函数：str_split
 * 描述：字符串分割
 * 参数：
 *   str (char const *): 原字符串
 *   s (char const *): 分割串字符串
 * 返回:
 *   char** 字符串数组
 */
char** str_split(char* const str, char* const s)
{
    int srcLen = strlen(str);
    int deLen = strlen(s);

    char src[srcLen];
    char de[deLen];

    strcpy(src, str);
    strcpy(de, s);
    
    int i = 0;
    char **arr = malloc(sizeof(char*));
    char *item = strtok(src, de);

    while (item != NULL)
    {
        // 动态数组
        arr = realloc(arr, (i + 1) * sizeof(char *));
        // 每项申请字符串长度
        arr[i] = malloc(strlen(item) * sizeof(char));
        // 复制字符串
        strcpy(arr[i], item);
        // 下一项获取
        item = strtok(NULL, de);
        ++i;
    }
    return arr;
}

/**
 * 函数：str_each
 * 描述：字符串数组遍历
 * 参数：
 *     list (char ** const) 字符串列表
 *     call (str_each_call_fun) 回调指针函数
 * 返回：
 *  void
 */
void str_each(char** const list, str_each_call_fun call)
{
    char* item;
    for(int i = 0 ; (item = list[i]) != NULL; ++i) {
        call(item);
    }
}

/**
 * 函数: str_count
 * 描述：获取字符串数组长度
 * 参数：
 *    list(char** const) 列表
 * 返回:
 *    int 个数
*/
int str_count(char** const list)
{
    int count = 0;
    char* tmp;
    for(; (tmp = list[count]) != NULL; ++count);
    return count;
}
