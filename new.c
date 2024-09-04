#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedlistTraversal(struct node *ptr)
{
    while ((ptr != NULL))
    {
        printf("Element is %d \n ", ptr->data);
        ptr = ptr->next;
    }
}
struct node *insertatFirst(struct node *head, int num)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;
    ptr->next = head;

    return ptr;
}

struct node * InsertAtIndex(struct node *head, int index, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node * InserAtEnd(struct node *head , int data ){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
     ptr->data = data; 
     p->next = ptr;
    ptr->next = NULL;
    return head;
}

int main()
{
    struct node *head, *second, *third, *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 58;
    head->next = second;

    second->data = 45;
    second->next = third;

    third->data = 22;
    third->next = fourth;

    fourth->data = 56;
    fourth->next = NULL;
   

    linkedlistTraversal(head);

    //head = insertatFirst(head, 56);
    printf("AFTER INSERTING AN ELEMENT\n");

   head = InsertAtIndex(head, 2 , 10);
    
    head = InserAtEnd(head , 9);
    linkedlistTraversal(head);
    

    return 0;
}