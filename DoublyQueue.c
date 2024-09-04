#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// insert node at the front
void insertFront(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;

    newNode->next = (*head);

    newNode->prev = NULL;

    if ((*head) != NULL)
        (*head)->prev = newNode;

    (*head) = newNode;
    printf("Node Inserted At Front successfully. \n");
}

// insert a newNode at the end of the list
void insertEnd(struct Node **head, int data)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;

    newNode->next = NULL;

    struct Node *temp = *head;

    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    newNode->prev = temp;
        printf("Node Inserted At End successfully. \n");
}

// delete a node from the doubly linked list
void deleteNode(struct Node **head, struct Node *del_node)
{

    if (*head == NULL || del_node == NULL)
        return;

    if (*head == del_node)
        *head = del_node->next;

    if (del_node->next != NULL)
        del_node->next->prev = del_node->prev;

    if (del_node->prev != NULL)
        del_node->prev->next = del_node->next;

    free(del_node);
    printf("Node deleted \n");
}

// print the doubly linked list
void displayForward(struct Node *node)
{
    struct Node *last;

    while (node != NULL)
    {
        printf("%d->", node->data);
        last = node;
        node = node->next;
    }
    if (node == NULL)
        printf("NULL\n");
}

void reverse(struct Node *head_ref)
{
    struct Node *temp = NULL;
    struct Node *current = head_ref;

    /* swap next and prev for all nodes of
       doubly linked list */
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    /* Before changing head, check for the cases like empty
        list and list with only one node */
    if (temp != NULL)
        head_ref = temp->prev;
}

int main()
{

    struct Node *head = NULL;
    insertFront(&head, 8);
    insertEnd(&head, 5);
    insertFront(&head, 1);
    insertFront(&head, 6);
    insertEnd(&head, 9);
    printf("Displaying Before delete\n");
    displayForward(head);

    // delete the last node
    deleteNode(&head, head->next->next->next->next);
    printf("Displaying After delete\n");
    displayForward(head);

    // printf("Displaying Bckward\n");
    // reverse(head);
    // displayForward(head);
}