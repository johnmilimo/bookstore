#include "book_store.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int books[] = {0,0,0,0,0};
int original_total_books = 0;
float rates[] = {1.00,0.95,0.90,0.80,0.75};
int price_per_book = 800;

// discount/books ratio
// offer_choices = [0/1,5/2,10/3,20/4,25/5]
int offer_choices[] = {0,2,3,5,5};

int total(int *basket, int size)
{
    int offers_count = sizeof(offer_choices)/sizeof(offer_choices[0]);
    int top_offer = largest(offer_choices, offers_count);   
    int *costs, n=0, c=0;
    for(int j=0; j<offers_count; j++)
        if(offer_choices[j]==top_offer)
            n++;
    costs = (int*)calloc(n, sizeof(int));

    // this is literaly brute force: computing based on all 
    // best offers. They can be multiple with similar value per item
    // Not an efficient algorithm.
    for(int i=0; i < offers_count; i++)
    {
        if(offer_choices[i] == top_offer)
        {
            prep_books(basket, size);
            costs[c] = compute(i);
            c++;
        }
    }
    int min = smallest(costs, n);
    free(costs);
    return min;
}

int compute(int max_group_size)
{
    int cost = 0,books_count = 0;
    int b_count = sizeof(books)/sizeof(int);
    while(original_total_books > 0)
    {
        books_count = 0;
        for(int index=0; index <= max_group_size; index++)
        {
            if(books[index]>0)
            {
                books[index] -= 1;
                books_count += 1;
            }
        }
        cost += books_count*(price_per_book*rates[books_count-1]);
        sortInDesc(books, b_count);
        original_total_books -= books_count;
    }
    return cost;
}

void prep_books(int *basket, int size)
{
    original_total_books = size;
    int b_count = sizeof(books)/sizeof(int);
    for(int i=0; i < size; i++)
    {
        int entry = basket[i] - 1;
        books[entry]++;
    }
    sortInDesc(books, b_count);
}

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