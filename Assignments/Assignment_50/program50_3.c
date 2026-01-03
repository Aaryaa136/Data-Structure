#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//////////////////////////////////////////////////////////
//
//Function Name:    CheckSorted
//Description:      Check whether list is sorted in ascending order
//Output:           Boolean
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

bool CheckSorted(PNODE first)
{
    while(first != NULL && first -> next != NULL)
    {
        if(first -> data > first -> next -> data)
        {
            return false;
        }
        first = first -> next;
    }

    return true;
}

int main()
{
    PNODE head = NULL;
    bool bRet = false;

    InsertFirst(&head,21);
    InsertFirst(&head,45);
    InsertFirst(&head,9);
    InsertFirst(&head,84);
    InsertFirst(&head,63);
    InsertFirst(&head,16);

    Display(head);

    bRet = CheckSorted(head);

    if(bRet == true)
    {
        printf("List sorted in ascending order");
    }
    else
    {
        printf("List is not sorted in order");
    }

    return 0;
}