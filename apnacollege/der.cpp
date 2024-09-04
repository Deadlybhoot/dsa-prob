#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(int arr[], int n, int s)
{
    // Your code here
    vector<int> v;
    int i = 0;
    int sum = arr[i];
    int j = 0;
    do
    {
        if (sum < s)
        {
            j += 1;
            sum += arr[j];
        }

        if (sum > s)
        {
            sum = sum - arr[i];
            i++;
        }
        if (sum == s)
        {

            v.push_back(i + 1);
            v.push_back(j + 1);
            return v;
            break;
        }
    } while (i < j);
}

int main()
{
    int A[] = {1, 2, 3, 7, 5};
    vector<int> ans;
    ans.push_back(2);
    ans = subarraySum(A, 5, 12);
    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}