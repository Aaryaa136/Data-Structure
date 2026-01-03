#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    MakeAbsolute
//Description:      Replace negative numbers with absolute value
//Author:           Aaryaa Patil
//Date:             3/1/26
//
//////////////////////////////////////////////////////////

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE first , int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn -> next = *first;
        *first = newn;
    }
}

void Display(PNODE first)
{
    PNODE temp = NULL;
    temp = first;

    while(temp != NULL)
    {
        printf("| %d | -> ",temp->data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first -> next;
    }

    return iCount;
}

void MakeAbsolute(PNODE first)
{
    while(first != NULL)
    {
        if(first->data < 0)
        {
            first -> data = -first -> data;
        }

        first = first -> next;
    }

}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head,121);
    InsertFirst(&head,-111);
    InsertFirst(&head,101);
    InsertFirst(&head,51);
    InsertFirst(&head,-21);
    InsertFirst(&head,11);

    Display(head);

    printf("Negative numbers with absolute value:\n");
    MakeAbsolute(head);
    Display(head);

    return 0;
}