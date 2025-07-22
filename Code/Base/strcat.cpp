#include "iostream"

using namespace std;

char *mystrcat(char *prestr, const char *laststr)
{
    char *ret = prestr;
    while (*prestr)
        prestr++; // 移动到 prestr 的末尾
    while ((*prestr++ = *laststr++))
        ; // 复制 laststr
    return ret;
}

int main()
{
    char a[20] = "987456";
    char b[] = "laststr";
    char *ret = mystrcat(a, b);
    cout << ret << endl;
    return 0;
}