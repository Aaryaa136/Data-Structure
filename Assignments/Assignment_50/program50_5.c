#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    DisplayNode
//Description:      Display nodes at nth position
//Input:            Integer
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

void DisplayNode(PNODE first , int pos)
{
    int iCount = 0;

    while(first != NULL && iCount < pos) 
    {
       iCount++;
       printf("%d\n",first->data);
       first = first -> next;
    }
}

int main()
{
    PNODE head = NULL;
    int iValue = 0;

    InsertFirst(&head,21);
    InsertFirst(&head,45);
    InsertFirst(&head,9);
    InsertFirst(&head,84);
    InsertFirst(&head,63);
    InsertFirst(&head,16);

    Display(head);

    printf("Enter position:");
    scanf("%d",&iValue);

    DisplayNode(head,iValue);
    
    return 0;
}