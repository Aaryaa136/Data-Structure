#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    DisplayByDivByFive
//Description:      Display elements divisible by 5
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

void DisplayDivByFive(PNODE first)
{
    PNODE temp = NULL;
    temp = first;

    while(temp != NULL)
    {
        if(temp -> data % 5 == 0)
        {
            printf("%d \n",temp->data);
        }

        temp = temp -> next;
    }
}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head,67);
    InsertFirst(&head,56);
    InsertFirst(&head,35);
    InsertFirst(&head,98);
    InsertFirst(&head,40);
    InsertFirst(&head,111);
    InsertFirst(&head,39);

    Display(head);

    printf("Nodes divisible by five are:\n");

    DisplayDivByFive(head);

    return 0;
}