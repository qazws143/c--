#include "iostream"

using namespace std;

char *Mymemmove(char *dest, const char *src, int num)
{
    char *temp_dest = (char *)dest;
    const char *temp_src = (const char *)src;
    if (temp_dest > temp_src && temp_dest < temp_src + num)
    {
        for (int i = num; i > 0; i--)
            temp_dest[i - 1] = temp_src[i - 1];
    }
    else
    {
        for (int i = 0; i < num; i++)
        {
            temp_dest[i] = temp_src[i];
        }
    }
    return dest;
}

int main()
{
    char a[] = "987456";
    char b[] = "98564";
    char *ret = Mymemmove(a, b, 3);
    cout << ret << endl;
    return 0;
}