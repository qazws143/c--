#include "iostream"

using namespace std;

int mystrcmp(char *str1, char *str2)
{
    while (*str1 && *str1 == *str2)
    {
        str1++;
        str2++;
    }
    return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}

int main()
{
    char a[20] = "987456";
    char b[] = "laststr";
    int ret = mystrcmp(a, b);
    cout << ret << endl;
    return 0;
}