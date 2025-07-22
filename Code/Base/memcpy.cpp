#include "iostream"

using namespace std;

/*拷贝num个字符到dest中*/
char *Myememcpy(char *dest, char *src, int num)
{
    char *temp = dest;
    while (num--)
        *temp++ = *src++;
    return dest;
}

int main()
{
    char a[20] = "987456";
    char b[] = "laststr";
    char *ret = Myememcpy(a, b, 3);
    cout << ret << endl;
    return 0;
}