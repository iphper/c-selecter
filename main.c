#ifdef _WIN32
    #include "windows.c"
#elif __linux__
    #include "linux.c"
#endif

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

