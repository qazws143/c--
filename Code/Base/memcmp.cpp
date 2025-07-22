#include "iostream"

using namespace std;

/*比较前num个字符的大小*/
int Mymemcmp(char *str1, char *str2, int num)
{
    char *tem_str1 = str1;
    char *tem_str2 = str2;
    int res = 0;
    while (num--)
    {
        res = *tem_str1 - *tem_str2;
        if (res != 0)
            break;
        *tem_str1++;
        *tem_str2++;
    }
    return res;
}

int main()
{
    char a[20] = "987456";
    char b[] = "987";
    int ret = Mymemcmp(a, b, 3);
    cout << ret << endl;
    return 0;
}