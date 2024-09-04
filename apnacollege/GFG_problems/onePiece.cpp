#include<bits/stdc++.h>
using namespace std;


// int FindOnePiece(int arr[], int n){
//     int f = 0;
//     int b = n-1;
//     bool swap;
//     int x1=0, y1=0, x2=0, y2=0;

//     while(f<=b){
//         if(f==b){
            
//         }
//        if(swap){
//         x1 += arr[f];
//         y1 += arr[b];
//         f = f+1;
//         b = b-1;
//         swap = false;
//        }
//        else{
//         x1 += arr[b];
//         y1 += arr[f];
//         f = f+1;
//         b = b-1;
//         swap = true;
//        }
//     } 

//      f = 0;
//     b = n-1;

//       while(f<b){
//        if(swap){
//         x2 += arr[b];
//         y2 += arr[f];
//         f = f+1;
//         b = b-1;
//         swap = false;
//        }
//        else{
//         x2 += arr[f];
//         y2 += arr[b];
//         f = f+1;
//         b = b-1;
//         swap = true;
//        }
//     } 

//     int large = max(x1,x2);
//     return large;
// }

int FindOnePiece(int a[], int n){
     int f = 0;
    int b = n-1;
    int x=0;
    int y =0;
    while(f<=b){
        if(a[f]>a[b]){
            x += a[f];
            f = f+1;
        }
        else{
            x += a[b];
            b = b-1;
        }


           if(a[f]>a[b]){
            y += a[f];
            f = f+1;
        }
        else{
            y += a[b];
            b = b-1;
        }
      
    }
    return x;
}

int main(){
vector<int>V;
int a[] =  {8, 15, 3, 7};
int b = FindOnePiece(a,4);
cout<<"Maximum is:-"<<b;




    return 0;
}