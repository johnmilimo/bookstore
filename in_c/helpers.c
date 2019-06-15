#include "helpers.h"

void sortInDesc(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if(arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int largest(int arr[], int n) 
{ 
    int max = arr[0];  
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max) 
            max = arr[i]; 
    }
    return max; 
}

int smallest(int arr[], int n) 
{ 
    int min = arr[0];  
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min) 
            min = arr[i]; 
    }
    return min; 
}
