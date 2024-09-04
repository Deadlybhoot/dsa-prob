#include <iostream>
#include <vector>
using namespace std;
// implementation of heap reference from love babbar & programiz
class heap
{
public:
    vector<int> arr;
    int size;

    heap()
    {
        // size = 0;
        size = arr.size();
    }

    void heapify(int i)
    {
        size = arr.size();
        int large = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < size && arr[large] < arr[l])
        {
            large = l;
            swap(arr[large], arr[i]);
            heapify(large);
        }

        if (r < size && arr[large] < arr[r])
        {
            large = r;
            swap(arr[large], arr[i]);
            heapify(large);
        }

        // if(large != i){
        //     //inbuilt swap
        //     swap(arr[large], arr[i]);//main arr[i] not arr[anything]
        //     heapify(large);
        // }
    }

    void insert(int val)
    {
        size = arr.size(); // must call
        if (size == 0)
        {
            arr.push_back(val);
        }
        else
        {
            // push at last
            arr.push_back(val);
            // and then call heapify
            for (int i = size / 2 - 1; i >= 0; i--)
            { // except leaf nodes , not from val because it is at leaf node
                heapify(i);
            }
        }
    }

    void deleteNode(int val)
    {//kontihi node delete karu shakto
        size = arr.size();
        int index;
        //jadlok desired element lok pohchatni tadlok for index
        for(index=0; index<size; index++){
            if(arr[index] == val){
                break;
            }
        }
        swap(arr[index], arr[size-1]);
        arr.pop_back();

        for(int i=size/2-1; i>=0; i--){
            heapify(i);
        }

    }

    void printHeap()
    {
        for (auto x : arr)
        {
            cout << x << " ";
        }
        cout<<endl;
    }
};

int main()
{
    heap h;
    h.insert(3);
    h.insert(4);
    h.insert(9);
    h.insert(5);
    h.insert(2);
    h.printHeap();
    h.deleteNode(4);
    h.printHeap();

    return 0;
}