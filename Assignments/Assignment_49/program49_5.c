#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    CountTwoDigits
//Description:      Count two digits number
//Author:           Aaryaa Patil
//Output:           Integer
//Date:             2/1/26
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

int CountTwoDigit(PNODE first)
{
    PNODE temp = NULL;
    temp = first;

    int iCount = 0;

    while(temp != NULL)
    {
        if(temp->data >= 10 && temp -> data <= 99)
        {
            iCount++;
        }

        temp = temp -> next;
    }

    return iCount;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,67);
    InsertFirst(&head,560);
    InsertFirst(&head,35);
    InsertFirst(&head,9);
    InsertFirst(&head,13);
    InsertFirst(&head,111);
    InsertFirst(&head,39);

    Display(head);

    iRet = CountTwoDigit(head);
    printf("Two digits node:%d",iRet);

    return 0;
}