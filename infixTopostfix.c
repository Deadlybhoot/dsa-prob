#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};
int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {

        return 1;
    }
    else
    {

        return 0;
    }
}
int IsEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr, char ch)
{
    if (isfull(ptr))
    {
        printf("The stack is overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = ch;
    }
}
int presidance(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else{
    return 0;
        }
}

int isoperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

char pop(struct stack *ptr)
{
    if (IsEmpty(ptr))
    {
        return 1;
    }
    else{
    char pp = ptr->arr[ptr->top];
    ptr->top--;
    return pp;
    }
}

char *infixTopostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(strlen(infix + 1) * sizeof(char));
    char *postfix = (char *)malloc(strlen(infix + 1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {

        if (!isoperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }

        else
        {
            if (presidance(infix[i]) > presidance(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }

    while (!IsEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }

    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "x-y/z-k*d";
    printf("postfix is %s ", infixTopostfix(infix));

    return 0;
}