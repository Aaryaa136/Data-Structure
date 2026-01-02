#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    CountDigits
//Description:      Count of each digit is
//Output:           Boolean
//Author:           Aaryaa Patil
//Date:             31/12/25
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
    while(first != NULL)
    {
        printf("| %d | -> ", first -> data);
        first = first -> next;
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

void CountDigits(PNODE first)
{
    int iCount = 0;
    int temp = 0;

    while(first != NULL)
    {
        temp = first -> data;
        iCount = 0;

        if(temp == 0)
        {
            iCount = 1;
        }
        else
        {
            while(temp != 0)
            {
                iCount++;
                temp = temp / 10;
            }
        }

        printf("Digits of %d nodes:%d\n",first->data,iCount);

        first = first -> next;
    }
}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head,45);
    InsertFirst(&head,891);
    InsertFirst(&head,6);
    InsertFirst(&head,56);
    InsertFirst(&head,7809);
    InsertFirst(&head,17);

    Display(head);

    printf("Digits of each node is:\n");

    CountDigits(head);

    return 0;
}