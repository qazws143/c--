#include "iostream"

using namespace std;

int mystrstr(char *str, char *substr)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        int j = 0;
        while (substr[j] != '\0' && str[i + j] == substr[j])
            j++;
        if (substr[j] == '\0')
            return 1;
    }
    return -1;
}

int main()
{
    char a[] = "987456";
    char b[] = "74";
    int ret = mystrstr(a, b);
    cout << ret << endl;
    return 0;
}