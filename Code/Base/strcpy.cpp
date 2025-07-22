#include "iostream"

using namespace std;

char *mystrcpy(char *prestr, char *newstr)
{
    char *ret = newstr;
    while ((*newstr++ = *prestr++) != '\0')
        ;
    return ret;
}

int main()
{
    char a[] = "987456";
    char b[] = "";
    char *ret = mystrcpy(a, b);
    cout << ret << endl;
    return 0;
}