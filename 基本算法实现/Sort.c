#include <stdio.h>

int arraySize(int arr[]);
void printArr(int arr[], int arrSize);

void bubbleSort(int arr[], int arrSize); 

int main()
{
    int arr[12] = {32,5,22,7,475,5,87,234,553,2,89};
    bubbleSort(arr, arraySize(arr));
    return 0;
}

void printArr(int arr[], int arrSize)
{
    for(int i = 0; i < arrSize; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int arraySize(int arr[])
{
    int i=0;
    while(arr[i] != 0)
    {
        i++;
    }
    return i;
}

void bubbleSort(int arr[], int arrSize)
{
    printArr(arr, arrSize);
    for(int i = 0; i < arrSize - 1; i++)
    {
        for(int j = 0; j < arrSize - i - 1; j++) 
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printArr(arr, arrSize);
    return;
}
