#include<iostream>
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
    node *n = new node(val);

    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    //when head is not NULLL
    node* temp = head;
    
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;

}

void insertAtLast(node* &head, int val){
    node* n = new node(val);
    node*temp = head;
    while(temp->next!=head){
        temp = temp->next;

    }
    temp->next = n;
    n->next = head;
}
void insertion(node *&head, int val, int pos)
{
    if (pos == 1)
    {
        insertAthead(head, val);
        return;
    }

   
}

void deletion(node* &head, int pos){
    if(head==NULL){
        return;
    }
    node* temp = head;
    node* todelete= NULL;
    if(pos==1){
        todelete = head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next = temp->next->next;
        head = temp->next;
        delete todelete;
    }
}

void display(node *head)
{
    node *ptr = head;
    do
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    } while (ptr != head);
    cout<<endl;
}

int main()
{
    node *head = NULL;
   
    insertAthead(head,2);
    insertAthead(head,20);
    insertAthead(head,90);

    insertAtLast(head,3);
    insertAtLast(head,4);
    display(head);

    deletion(head,1);
    display(head);
    return 0;
}