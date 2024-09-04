#include <iostream>
#include <stack>
using namespace std;

int minSteps(int x, int y)
{
    int minS = x / y;
    int remain = x % y;
    minS = minS + remain;
    return minS;
}

int main()
{
    int a = minSteps(8, 3);
    cout << "minimum steps" << a;
    return 0;
}