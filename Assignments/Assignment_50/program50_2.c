#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    DisplayGreaterThanAvg
//Description:      Display elements greater than average
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

void DisplayGreaterThanAvg(PNODE first)
{
    int iSum = 0 , iAvg = 0 , iSize = 0;
    iSize = Count(first);

    PNODE temp = NULL;
    temp = first;

    while(temp != NULL)
    {
        iSum = iSum + temp->data;
        temp = temp -> next;
    }

    if(iSize == 0)
    {
        return;
    }

    iAvg = iSum / iSize;

    temp = first;
    while(temp != NULL)
    {
        if(temp -> data > iAvg)
        {
            printf("%d\n",temp->data);
        }
        temp = temp -> next;
    }

}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head,21);
    InsertFirst(&head,45);
    InsertFirst(&head,9);
    InsertFirst(&head,84);
    InsertFirst(&head,63);
    InsertFirst(&head,16);

    Display(head);

    printf("Elements greater than avg:\n");
    DisplayGreaterThanAvg(head);
    
    return 0;
}