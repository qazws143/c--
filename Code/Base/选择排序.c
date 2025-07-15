#include "stdio.h"

void SelectSort(int *arr, int size)
{
    int i, j, max, tmp;
    for (i = 0; i < size - 1; i++)
    {
        max = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[max])
                max = j;
        }
        tmp = arr[i];
        arr[i] = arr[max];
        arr[max] = tmp;
    }
}

int main(void)
{
    int arr[10] = {1, 9, 7, 5, 3, 4, 2, 8, 6, 7};
    SelectSort(arr, 10);
    printf("排序后为:");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}