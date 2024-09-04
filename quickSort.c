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
    a[j] = a[pivot];
    a[pivot] = a[j];
    return j ;
    
}



void quickSort(int a[] , int low , int high){
  

  if(low < high) 
   {   int partitionindex = partition(a , low , high);
       quickSort(a , low , partitionindex - 1);
       quickSort(a, partitionindex + 1 , high);
   }
   
}



int main(){

int a[] = {23 , 34 , 45, 65, 76 ,23};
int n =  sizeof(a) / sizeof(a[0]);

quickSort(a , 0 , n - 1);

 for (int i = 0; i < n; i++)
 {
     printf("%d\n", a[i]);
 }
    return 0;
}
