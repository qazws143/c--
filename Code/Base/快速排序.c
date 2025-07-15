#include "stdio.h"

/// @brief 元素交换
/// @param left
/// @param right
void swap(int *left, int *right)
{
    if (left == right)
        return;
    *left = *left ^ *right;
    *right = *left ^ *right;
    *left = *left ^ *right;
}

/// @brief 对数组进行排序
/// @param left
/// @param right
/// @param arr
/// @return 基准元素
int Quick(int left, int right, int arr[])
{
    int key = arr[left];
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && arr[j] >= key)
            j--;
        while (i < j && arr[i] <= key)
            i++;
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[left], &arr[i]);
    return i;
}

/// @brief 递归排序
/// @param left
/// @param right
/// @param arr
void QuickSort(int left, int right, int arr[])
{
    if (left >= right)
        return;
    int mid = Quick(left, right, arr);
    QuickSort(left, mid - 1, arr);  // 左半部分递归排序
    QuickSort(mid + 1, right, arr); // 右半部分递归排序
}

int main(void)
{
    int arr[10] = {1, 9, 7, 5, 3, 4, 2, 8, 6, 7};
    int left = 0;
    int right = sizeof(arr) / sizeof(arr[0]) - 1;
    printf("排序前为:");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        printf("%d ", arr[i]);
    printf("\n");

    QuickSort(left, right, arr);
    printf("排序后为:");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        printf("%d ", arr[i]);
    return 0;
}