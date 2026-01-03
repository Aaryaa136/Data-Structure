#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    Difference
//Description:      Find difference between maximum and minimum node
//Output:           Integer
//Author:           Aaryaa Patil
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

int Difference(PNODE first)
{
    int iMax = 0 , iMin = 0;
    PNODE temp = NULL;
    
    temp = first;

    if(first == NULL)
    {
        return 0;
    }

    iMax = temp -> data;
    iMin = temp -> data;

    while(temp != NULL)
    {
        if(temp -> data > iMax)
        {
            iMax = temp -> data;
        }

        if(temp -> data < iMin)
        {
            iMin = temp -> data;
        }

        temp = temp -> next;
    }

    return (iMax - iMin);
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,67);
    InsertFirst(&head,56);
    InsertFirst(&head,3);
    InsertFirst(&head,98);
    InsertFirst(&head,40);
    InsertFirst(&head,111);
    InsertFirst(&head,39);

    Display(head);

    printf("\n");

    iRet = Difference(head);
    printf("Differnce between maximum and minimum node is:%d",iRet);

    return 0;
}