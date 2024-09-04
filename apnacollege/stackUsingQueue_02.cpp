#include <iostream>
#include <queue>
using namespace std;
// This approach is by modifying the pop operation;
class stack
{
    queue<int> q1;
    queue<int> q2;

public:
    void push(int num)
    {
        q1.push(num);
    }

    int pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty.." << endl;
            return -1;
        }
        // JAb tak q1 mein sirf ek element na rahe tab tak
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        int ans = q1.front();
        q1.pop(); // its necessary to pop last element from q1

        // swapping two queues
        queue<int> temp;
        temp = q1;
        q1 = q2;
        q2 = temp;

        return ans;
    }
};

int main()
{

    stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    return 0;
}
