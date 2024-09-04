#include <iostream>
#include <vector>
using namespace std;

//Given an unsorted array Arr of N positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
// Note: Array should start with positive number.
void rearrange(int arr[], int n)
{
    // code here
    vector<int> pos;
    vector<int> neg;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            pos.push_back(arr[i]);
        }
        else if (arr[i] < 0)
        {
            neg.push_back(arr[i]);
        }
    }
//FOr printing pos & neg

    // for(auto x: pos){
    //     cout<<x<<" ";
    // }
    // cout<<endl;

    // for(auto y: neg){
    //     cout<<y<<" ";
    // }
    //   cout<<endl;

    long len_pos = pos.size();
    long len_neg = neg.size();

    // arr[0] = pos[0];
    int p = 0;
    int q = 0;

    for (int i = 0; i < n; i++)
    {
         if(q >= len_neg){//-->= due to if any of from pos & neg comes as zero then this will run 
            int t = i;
            for(int j=p; j<len_pos; j++){
                arr[t] = pos[j];
                t++;
            }
            break;
        }

          if(p >= len_pos){
            int t = i;
            for(int j=q; j<len_neg; j++){
                arr[t] = neg[j];
                t++;
            }
            break;
        }
        
        
        if (i % 2 != 0)
        {
            arr[i] = neg[q];
            q++;
        }

        else if (i % 2 == 0)
        {
            arr[i] = pos[p];
            p++;
        }

       
    }

}

int main()
{
    // int Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2};
      int Arr[] = {-36,-9, -92, -87, -43, -44};
    rearrange(Arr, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << Arr[i] << " ";
    }

    return 0;
}
// 9 -2 4 -1 5 -5 0 -3 2