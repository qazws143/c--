#include "stdio.h"
#include "stdlib.h"

/**
 * @brief 合并数组
 *
 * @param sourceArr 原数组
 * @param tempArr   临时数组
 * @param startIndex 起始索引
 * @param midIndex  中间元素
 * @param endIndex 结尾元素
 */
void Merge(int sourceArr[], int tempArr[], int startIndex, int midIndex, int endIndex)
{
    int i = startIndex;   // 左区间起始
    int j = midIndex + 1; // 右区间起始
    int k = startIndex;   // 临时数组起始
    // 比较两个子数组的元素，将较小的放入临时数组
    while (i != midIndex + 1 && j != endIndex + 1)
    {
        if (sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    // 将剩余元素复制到临时数组
    while (i != midIndex + 1)
        tempArr[k++] = sourceArr[i++];
    while (j != endIndex + 1)
        tempArr[k++] = sourceArr[j++];
    // 将临时数组复制回原数组
    for (i = startIndex; i <= endIndex; i++)
        sourceArr[i] = tempArr[i];
}

/**
 * @brief 递归排序
 *
 * @param sourceArr 源数组
 * @param tempArr 临时数组
 * @param startIndex 起始
 * @param endIndex 结尾
 */
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
    int midIndex;
    if (startIndex < endIndex)
    {
        midIndex = startIndex + (endIndex - startIndex) / 2;       // 计算中间点
        MergeSort(sourceArr, tempArr, startIndex, midIndex);       // 左半排序
        MergeSort(sourceArr, tempArr, midIndex + 1, endIndex);     // 右半排序
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex); // 合并为一个有效数组
    }
}

int main(void)
{
    int arr[10] = {1, 9, 7, 5, 3, 4, 2, 8, 6, 7};
    int ch[10];
    printf("排序前为:");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        printf("%d ", arr[i]);
    printf("\n");

    MergeSort(arr, ch, 0, 9);
    printf("排序后为:");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        printf("%d ", arr[i]);
    return 0;
}