#include <stdio.h>

int max(int x, int y)
{

    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}


int traped(int array[], int n)
{

    int left = 0, right = n - 1, water = 0;

    int maxleft = array[left];
    int maxright = array[right];

    while (left < right)
    {
        if (array[left] <= array[right])
        {
            left++;

            maxleft = max(maxleft, array[left]);
            water += maxleft - array[left];
        }

        else
        {

            right--;
            maxright = max(maxright, array[right]);
            water += maxright - array[right];
        }
    }

    return water;
}

int main()
{

    int array[] = {1 , 2 };

    int n = sizeof(array) / sizeof(array[0]);

    printf("The maximum amount of water that can be traped into array is %d", traped(array, n));

    return 0;
}
