#include <stdio.h>

void bubble(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    int arr[10] = {1, 9, 7, 5, 3, 4, 2, 8, 6, 7};
    bubble(arr, 10);
    printf("排序后为:");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}