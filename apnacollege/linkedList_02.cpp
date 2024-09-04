#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAthead(node *&head, int val)
{
    // create a node
    node *n = new node(val);
    // initialise with head
    n->next = head;
    head = n;
}

void display(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

// Meen swathh draw karun kadhla
node *mergeLinked(node *&head1, node *&head2)
{
    node *p1 = head1;
    node *p2 = head2;
    node *Dumynode = new node(-1);
    node *p3 = Dumynode;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
    }

    //here one of linkedlist is null hence remaining linkedlist we have to make empty for that this two while loops
    while(p1!=NULL){
        p3->next = p1;
        p1= p1->next;
        p3 = p3->next;
    }

    while(p2!=NULL){
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;

    }



    return Dumynode;
}

int main()
{
    int arr1[] = {3, 2, 1};
    int arr2[] = {10, 9, 8, 7, 6, 5, 4};
    // cout<<sizeof(arr1)/sizeof(arr1[0]);
    node *head1 = NULL;
    node *head2 = NULL;

    for (int i = 0; i < (sizeof(arr1) / sizeof(arr1[0])); i++)
    {
        insertAthead(head1, arr1[i]);
    }

    for (int i = 0; i < (sizeof(arr2) / sizeof(arr2[0])); i++)
    {
        insertAthead(head2, arr2[i]);
    }

    display(head1);
    display(head2);
    node *newhead = mergeLinked(head1, head2);
    display(newhead);

    return 0;
}