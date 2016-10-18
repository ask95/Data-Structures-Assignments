
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    struct Node *previous;
    struct Node *next;
    int val;
};

struct Node *head = NULL;
struct Node *tail = NULL;

//struct Node *current = NULL;


void insert(int value)
{
    struct Node *newnode = malloc(sizeof(struct Node));
    newnode->next = NULL;
    newnode->previous = NULL;
    newnode->val = value;
    if (head == NULL)
    {
        head = newnode;
        tail = head;
    }
    else if(head->val>value)
    {
        newnode->next = head;
        head->previous = newnode;
        head = head->previous;
    }
    else
    {
        struct Node *curr = head;
        int tempval = 0;
        while(curr!=NULL && curr->val <= value  )
        {
            tempval = curr->val;
            curr = curr->next;
        }
        
        if(curr!= NULL)
        {
        curr->previous->next = newnode;
        newnode->previous = curr->previous;
        curr->previous = newnode;
        newnode->next = curr;
        }
        else
        {
            tail->next=newnode;
            newnode->previous = tail;
            tail = tail->next;
        }
    }
    
}

int main()
{
    int n,i;
    char c[20][100];
    scanf("%d\n",&n);
    //printf("\nThe number of lines in the input file , n = %d \n",n);
    for(i=0; i<n; i++)
    {
        gets(c[i]);
        //printf("c[%d]=%s\n",i ,c[i]);
        struct Node *temp = head;
        if(*c[i] =='P')
        {
            while(temp!=NULL)
            {
                printf("%d",temp->val);
                //printf("5");
                temp = temp->next;
            }
        }
        else
        {
            int a = atoi(c[i]);
            //printf("%d\n",a);
            insert(a);
        }
        printf("\n");
    
    }
    
    printf("\nFinal sorted list : ");
    struct Node *temp = head;
    while(temp!=NULL)
    {
        printf("%d",temp->val);
        temp = temp->next;
    }
    printf("\n");

    
    return 2;

}
