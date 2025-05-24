#include "basis.h"
void secgetpasseord(std::string& password)
{

    char passwordarray[20];
    char ch;
    int i = 0;
    cout<<"enter your password "<<endl;

    while (true)
    {
        ch = (char)getch(); // 获取键盘输入的字符，但不显示在屏幕上

        if (ch == '\r') {
            passwordarray[i] = '\0'; // 将字符串结束符加入密码字符串
            break; // 输入结束，退出循环
        }
        else if (ch == '\b')
        {
            if (i > 0)
            {
                i--;
                printf("\b \b"); // 退格操作，删除上一个字符并移动光标位置
            }
        }
        else
        {
            passwordarray[i] = ch; // 将字符存入密码字符串
            i++;
            printf("*"); // 显示*代替输入的字符
        }
    }

    //printf("\npassarray: %s\n", passwordarray);//测试链接
    std::string cppstrchange(passwordarray);
    password = cppstrchange;

}

bool startsWith(const std::string& str, const std::string& prefix)
{
    // 比较前缀长度和字符串长度
    if (str.size() < prefix.size())
    {
        return false;
    }
    // 使用 compare 函数进行前缀比较
    return str.compare(0, prefix.size(), prefix) == 0;
}
