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

node *reverseIterative(node *&head)
{

    node *prev = NULL;
    node *cur = head;
    // node* Next = cur->next; ----this is nottrue due to at the end when thisat NULL , NULL has no next pointer hence
    node *Next = NULL; //----APnaaacolge
    while (cur != NULL)
    {
        Next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = Next;
    }

    head = prev;
    return head;
}

node *reverseKNodes(node *&head, int k)
{
    node *prev = NULL;
    node *cur = head;
    node *Next = NULL;
    int count = 0;
    while (cur != NULL && count < k)
    {
        Next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = Next;
        count++;
    }
    if (Next != NULL)
    {
        head->next = reverseKNodes(Next, k);
    }
}

node *revesrseRecursive(node *&head, node *cur, node *prev = NULL)
{

    if (cur == NULL)
    {
        head = prev;
        return head;
    }

    node *newnode = revesrseRecursive(head, cur->next, cur);
    cur->next = prev;
    return newnode;
}

void makeCycleAt(node *&head, int pos)
{
    node *temp = head;
    node *startnode = NULL;
    int count = 0;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startnode = temp;
        }
        temp = temp->next;
        count++;
    }

    temp->next = startnode;
}

bool detectCycle(node* head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)//--remember here the sequence matters dont interchange
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}
//do by imagining the apna college diagram
void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;
    //
    do{//do while duw to allready slow == fast
        slow = slow->next;
        fast= fast->next->next;
        
    }while(fast != slow);
    
    //this will removes the cycle
    if(fast==slow){
        fast = head;
        while(fast->next!=slow->next){
            fast = fast->next;
            slow= slow->next;
        }
        slow->next = NULL;
    }
}

int length(node* head){
    node* temp = head;
    int l = 1;
    while(temp->next!=NULL){
        temp = temp->next;
        l++;
    }
    return l;
}

node* appendLastKnode(node* &head , int k){
    node* newtail = NULL;
    node* newhead = NULL;
    node* tail = head;
    int count = 1;
    int l = length(head);

    while(tail->next!= NULL){
        if(count == l-k){
            newtail = tail;
        }
        if(count == l-k+1){
            newhead = tail;
        }
        tail = tail->next;
        count++;

    }
    tail->next = head;
    newtail->next = NULL;
    return newhead;
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
int main()
{

    node *head = NULL;
    insertAthead(head, 1);
    insertAthead(head, 2);
    insertAthead(head, 3);
    insertAthead(head, 4);
    insertAthead(head, 5);
    insertAthead(head, 6);
    ;
      display(head);
    node *cur = head;
    head = revesrseRecursive(head, cur);
    display(head);

    // head = recursiveIterative(head);
    // display(head);

   // makeCycleAt(head,3);
    // display(head);
    // cout<<detectCycle(head)<<endl;
    // removeCycle(head);
    // cout<<detectCycle(head);

    head = appendLastKnode(head,3);
    display(head);
    // cout<<length(head);

    
    return 0;
}