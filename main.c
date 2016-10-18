
#include <stdio.h>

struct Stack
{
    char *array[100];
    int *top;
};

void push(struct Stack stack, char c)
{
    
    if (*stack.top < 100)
    
    {
        
        *stack.top += 1;
        *stack.array[*stack.top] = c;
    }
    else
    {
        printf("Stack is full");
    }
}

char pop(struct Stack stack)
{
    if (*stack.top == 0)
    {
        printf("Stack is empty");
        return 'a';
    }
    else
    {
        char a = *stack.array[*stack.top];
        *stack.top -= 1;
        return a;
    }
}

int main()

{
    int n,i,j;
    char c[20][100];
    scanf("%d\n",&n);
    printf("\nThe number of expressions , n = %d",n);
    for ( i = 0 ; i < n ; i ++)
    {
        gets(c[i]);
        struct Stack stack1;
        struct Stack stack2;
        
        //for power-----------------------------------
        
        for(j=0; j<100 ; j++)
        {
            
            if(c[i][j] == '^')
            {
                char temp, temp3;
                int temp2;
                temp = pop(stack1);
                int tempint = temp - '0';
                int tempint3 = temp3 - '0';
                temp2 = tempint^tempint3;
                char tempchar = temp2 + '0';
                push(stack1, tempchar);
            }
            else
            {
            push(stack1, c[i][j]);
            }
        }
        //----------------------------------------------
        for(j=0; j<100 ; j++)
        {
            char perm = pop(stack1);
            push(stack2, perm);
        }
        
        //for division------------------------------------
        
        for(j=0; j<100 ; j++)
        {
            char perm = pop(stack2);
            if(perm == '/')
            {
                char temp, temp3;
                int temp2;
                temp = pop(stack1);
                int tempint = temp - '0';
                int tempint3 = temp3 - '0';
                temp2 = tempint/tempint3;
                char tempchar = temp2 + '0';
                push(stack1, tempchar);
            }
            else
            {
                push(stack1, perm);
            }
        }
        //----------------------------------------------
        for(j=0; j<100 ; j++)
        {
            char perm = pop(stack1);
            push(stack2, perm);
        }
        
        //for multiplication------------------------------------
        
        for(j=0; j<100 ; j++)
        {
            char perm = pop(stack2);
            if(perm == '*')
            {
                char temp, temp3;
                int temp2;
                temp = pop(stack1);
                int tempint = temp - '0';
                int tempint3 = temp3 - '0';
                temp2 = tempint*tempint3;
                char tempchar = temp2 + '0';
                push(stack1, tempchar);
            }
            else
            {
                push(stack1, perm);
            }
        }
        //----------------------------------------------
        for(j=0; j<100 ; j++)
        {
            char perm = pop(stack1);
            push(stack2, perm);
        }
        
        //for addition-------------------------------------
        
        for(j=0; j<100 ; j++)
        {
            char perm = pop(stack2);
            if(perm == '+')
            {
                char temp, temp3;
                int temp2;
                temp = pop(stack1);
                int tempint = temp - '0';
                int tempint3 = temp3 - '0';
                temp2 = tempint+tempint3;
                char tempchar = temp2 + '0';
                push(stack1, tempchar);
            }
            else
            {
                push(stack1, perm);
            }
        }
        //----------------------------------------------
        for(j=0; j<100 ; j++)
        {
            char perm = pop(stack1);
            push(stack2, perm);
        }
        
        //for subtraction------------------------------------
        
        for(j=0; j<100 ; j++)
        {
            char perm = pop(stack2);
            if(perm == '-')
            {
                char temp, temp3;
                int temp2;
                temp = pop(stack1);
                int tempint = temp - '0';
                int tempint3 = temp3 - '0';
                temp2 = tempint-tempint3;
                char tempchar = temp2 + '0';
                push(stack1, tempchar);
            }
            else
            {
                push(stack1, perm);
            }
        }
       //----------------------------------------------
       
        char answerchar = pop(stack1);
        int answer = answerchar - '0';
        printf ("\n %d \n", answer);
       
    }
    
        //printf ("\nc[%d]=%s \n",i, c[i]);
    
    
    return 1;
}
