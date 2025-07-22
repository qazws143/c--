#include "vector"
#include "stack"
#include "iostream"
#include "string"
#include "assert.h"

using namespace std;

int sstrstr(char *str, char *substr)
{
    if (*substr == '\0') // 如果子串为空，返回 0
        return 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        int j = 0;
        while (substr[j] != '\0' && str[i + j] == substr[j])
            j++;

        if (substr[j] == '\0') // 如果子串全部匹配，返回起始位置
            return i;
    }
    return -1; // 未找到
}

int main()
{
    char a[] = "987456";
    char b[] = "74";
    int ret = sstrstr(a, b);
    cout << ret << endl;
    return 0;
}
