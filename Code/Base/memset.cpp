#include "iostream"
#include "cstdio"

using namespace std;

/*初始化字符串*/
void *Mymemset(char *dest, int value, int num)
{
    char *ret = dest;
    for (int i = 0; i < num; i++)
    {
        *ret++ = value;
    }
    return dest;
}

int main()
{
    char a[20] = "987456";
    char b[] = "";
    char *ret = (char *)Mymemset(a, 1, sizeof(a));
    for (int i = 0; i < 6; ++i)
    {
        printf("%d", a[i]);
    }
    return 0;
}