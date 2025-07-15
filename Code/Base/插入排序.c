#include <stdio.h>

void insert(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];                  // 将后一个元素设为基准元素
        j = i - 1;                     // 将j设为前一个元素
        while (j >= 0 && arr[j] > key) // 前一个元素大于基准元素
        {
            arr[j + 1] = arr[j]; // 将前一个元素后移
            j--;                 // 继续向前检查,是否有大于基准元素的
        }
        arr[j + 1] = key; // 将基准元素放到正确位置
    }
}

int main(void)
{
    int arr[10] = {1, 9, 7, 5, 3, 4, 2, 8, 6, 7};

    printf("排序前为:");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        printf("%d ", arr[i]);
    printf("\n");

    insert(arr, sizeof(arr) / sizeof(arr[0]));
    printf("排序后为:");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        printf("%d ", arr[i]);
    return 0;
}