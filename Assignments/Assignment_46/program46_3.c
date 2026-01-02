#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//////////////////////////////////////////////////////////
//
//Function Name:    isEmpty
//Description:      Check whether LL is empty or not, return true if empty
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

bool isEmpty(PNODE first)
{
    int iSize = 0;
    iSize = Count(first);

    if(iSize < 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    PNODE head = NULL;
    bool bRet = false;

    InsertFirst(&head,45);
    InsertFirst(&head,89);
    InsertFirst(&head,6);
    InsertFirst(&head,56);
    InsertFirst(&head,78);
    InsertFirst(&head,17);

    Display(head);
    
    bRet = isEmpty(head);

    if(bRet == true)
    {
        printf("Linked list is empty");
    }
    else
    {
        printf("Linked list contains nodes");
    }

    return 0;
}