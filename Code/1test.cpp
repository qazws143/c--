#include "vector"
#include "stack"
#include "string"

using namespace std;

typedef union
{
    long i;
    int k[5]; // 20
    char c;
} DATE;

struct data
{
    int cat;    // 4
    DATE cow;   // 20 里面虽然有long，但是对外是20字节int的数据
    double dog; // 8 看这个类型的整数倍
} too;

int main()
{
    printf("结构体：%zu\n", sizeof(struct data));
    printf("联合体：%zu\n", sizeof(DATE));
}
