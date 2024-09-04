#include<bits/stdc++.h>
using namespace std;

class dynamic_memory{
    int *arr;
   
    
    public:
    void create();
    void insert();
    int max();



};
int n;
void dynamic_memory :: create(){
    
    cout<<"Enter size of array";
    cin>>n;
    arr =  new int(n);

}

void dynamic_memory :: insert(){
    
    cout<<"Enter elements of array";
    for(int i= 0; i<n; i++){
        cin>>arr[i];

    }
    


}

int dynamic_memory :: max(){
    int num = INT_MIN;
    for(int i = 0; i<n; i++){
        if(arr[i]>num){
            num = arr[i];
        }

    }
    
    
    return num;

}
int main (){
    dynamic_memory b;
    b.create();
    b.insert();
    int large_num = b.max();
    cout<<"largest number from array is : "<< large_num;


    return 0;
} 
