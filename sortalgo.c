#include <stdio.h>

int partition (int a[] , int low , int high){
    int pivot = low;
    int i = low +1 ;
    int j = high;
    int temp;

    while (i < j )
    {
        while (a[i] <= a[pivot])
        {
            i++;
        }
        while (a[j] >a[pivot])
        {
           j--;
        }

        if (i<j)
        {
             temp = a[i];
            a[i] = a[j]; 
            a[j] = temp;
        }
        
        
    }
    temp = a[j]; 
    a[j] = a[low];
    a[low] = a[j];
    return j ;
    
}

void quickSort(int a[] , int low , int high){
  

  if(low < high) 
   {     int partitionindex = partition(a , low , high);
       quickSort(a , low , partitionindex - 1);
       quickSort(a, partitionindex + 1 , high);
   }
   
}




void selectionSort(int *a, int n)
{
    int indexmin ; //because we are only selecting not doing anything hence index not element
    int temp;
    for (int i = 0; i < n-1; i++)
    {   indexmin = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[indexmin] > a[j])
            {
                indexmin = j;
            }
        }
        temp = a[i];//this is main dont directly put like a[i] = a[indexmin] remember
        a[i] = a[indexmin];
        a[indexmin] = temp;
    }   
}

void bubblesort(int *a, int n)
{//easiest sorting 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int *a, int n)
{
    int key, j;

    for (int i = 0; i < n - 1; i++)
    {
        j = i;
        key = a[i + 1]; //due to we are inserting element
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

int main()
{

    int a[] = {23, 45, 11, 78, 9 };
    //insertionSort(a ,5);
    //bubblesort(a, 5);
   // selectionSort(a, 5);
  quickSort(a , 0 , 4);
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}