#include <bits/stdc++.h>
using namespace std;


  int binary_search(int arr[], int l, int h, int x)
    {
        while (l <= h)
        {
            int mid = (l+h) / 2;
     
            // if 'x' is greater than or equal to arr[mid], 
            // then search in arr[mid+1...h]
            if (arr[mid] <= x)
                l = mid + 1;
     
            // else search in arr[l...mid-1]    
            else
                h = mid - 1;    
        }
         
        // required index
        return h;
    }
     
    // function to count for each element in 1st array,
    // elements less than or equal to it in 2nd array
    vector <int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
        vector <int> res;
        // sort the 2nd array
        sort(arr2, arr2+n);
         
        // for each element of 1st array
        for (int i=0; i<m; i++)
        {
            // last index of largest element 
            // smaller than or equal to x
            int index = binary_search(arr2, 0, n-1, arr1[i]);
             
            // required count for the element arr1[i]
            res.push_back (index+1);
        }
        return res;
    }





int main()
{
    int arr1[] = {1, 2, 3, 4, 7, 9};
    int arr2[] = {0, 1, 2, 1, 1, 4};
    sort(arr2, arr2 + 6);
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << arr2[i] << " ";
    // }
    vector<int>f = countEleLessThanOrEqual(arr1, arr2, 6, 6);
    for(auto x: f){
        cout<<x<<" ";
    }
    return 0;
}