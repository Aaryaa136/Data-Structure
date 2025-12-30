#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    DisplayPerfect
//Description:      Check each node is it perfecr number or not
//Input:            Integer
//Output:           Integer
//Author:           Aaryaa Patil
//Date:             22/12/25
//
//////////////////////////////////////////////////////////

struct node 
{
    int data;
    struct node* next;
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

    if((*first) == NULL)
    {
        (*first) = newn;
    }
    else
    {
        newn -> next = (*first);
        (*first) = newn;
    }
}

void DisplayPerfect(PNODE first)
{
    int iSum = 0;
    int iCnt = 0 , iNum =0;

    while(first != NULL)
    {
        iNum = first->data;
        iSum = 0;

        for(iCnt = 1; iCnt <= iNum / 2; iCnt++)
        {
            if(iNum % iCnt == 0)
            {
                iSum += iCnt;
            }
        }

        if(iSum == iNum)
        {
            printf("%d is a perfect number\n", iNum);
        }

        first = first->next;  
    }
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,89);
    InsertFirst(&head,6);
    InsertFirst(&head,41);
    InsertFirst(&head,17);
    InsertFirst(&head,28);
    InsertFirst(&head,11);

    DisplayPerfect(head);

    return 0;
}