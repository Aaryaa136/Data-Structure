#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//////////////////////////////////////////////////////////
//
//Function Name:    CheckAllPositive
//Description:      Find difference between maximum and minimum node
//Output:           Boolean
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

bool CheckAllPositive(PNODE first)
{
    int iSize = 0 , iCnt = 0;
    PNODE temp = NULL;

    temp = first;
    iSize = Count(first);

    for(iCnt = 1 ; iCnt <= iSize ; iCnt++)
    {
        if(temp -> data <= 0)
        {
            return false;
        }     
        temp = temp -> next;
    }

    return true;
}

int main()
{
    PNODE head = NULL;
    bool bRet = false;

    InsertFirst(&head,67);
    InsertFirst(&head,-56);
    InsertFirst(&head,3);
    InsertFirst(&head,98);
    InsertFirst(&head,40);
    InsertFirst(&head,-111);
    InsertFirst(&head,39);

    Display(head);

    printf("\n");

    bRet = CheckAllPositive(head);
    
    if(bRet == true)
    {
        printf("LL contains all positive nodes");
    }
    else
    {
        printf("LL contains negative nodes");
    }

    return 0;
}