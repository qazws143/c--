#include <stdio.h>

void hill(int arr[], int n)
{
    int gap;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int j;
            int temp = arr[i];
            for (j = i; j >= 0 && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main(void)
{
    int arr[10] = {1, 9, 7, 5, 3, 4, 2, 8, 6, 7};

    printf("排序前为:");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        printf("%d ", arr[i]);
    printf("\n");

    hill(arr, sizeof(arr) / sizeof(arr[0]));
    printf("排序后为:");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        printf("%d ", arr[i]);
    return 0;
}