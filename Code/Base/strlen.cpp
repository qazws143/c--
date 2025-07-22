#include "iostream"

using namespace std;

int mystrlen(char *str) // 手写字符串长度
{
    int len = 0;
    while (*str++ != '\0')
        len++;
    return len;
}

int main()
{
    char a[] = "987456";
    char b[] = "74";
    int ret = mystrlen(a);
    cout << ret << endl;
    return 0;
}