#include <bits/stdc++.h>
using namespace std;

// Aim:-Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.


class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int tar)
{
    // code here
    Node *i = head;
    Node *j = head;
    vector<pair<int, int>> vp;
    while (j->next)
    {
        j = j->next;
    }

    while (i->data < j->data)
    {
        int sum = i->data + j->data;

        if (sum == tar)
        {
            // vp.push_back({i->data, j->data});
            vp.push_back(make_pair(i->data, j->data));
            i = i->next;
            j = j->prev;
        }

        else if (sum < tar)
        {
            i = i->next;
        }

        else
        {
            j = j->prev;
        }
    }
    return vp;
}

void createNode(Node *&head, int val)
{
    if (head == NULL)
    {
        Node *node = new Node(val);
        head = node;
        return;
    }

    else
    {
        Node *node = new Node(val);
        Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = node;
        node->prev = ptr;
    }
}

void printlist(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    Node *head = NULL;
    createNode(head, 1);
    createNode(head, 2);
    createNode(head, 4);
    createNode(head, 5);
    createNode(head, 6);
    createNode(head, 8);
    createNode(head, 9);

    // printlist(head);
    vector<pair<int, int>> vp = findPairsWithGivenSum(head, 7);

    for (auto x : vp)
    {
        cout << x.first << " " << x.second;
        cout << endl;
    }

    return 0;
} // 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9