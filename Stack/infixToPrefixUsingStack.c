#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50

int stack[N];
int top =-1;

void push(char x) 
{
    if(top ==N-1)
        printf("Overflow\n");
    else
    {
        top++;  
        stack[top]=x;
    }

}

char pop() 
{
    char x =-1;
    if(top == -1)
        printf("Underflow");
    else
    {
        x= stack[top];
        top--;
    }
    return x;
}

int precidence(char x )
{
    if(x=='+' || x== '-')
     return 1;
    else if(x=='*' || x=='/')
        return 3;
    else if(x=='^')
        return 4;
    return 0;
}

int outstack( char x)
{
    if(x=='+' || x=='-')
        return 1;
    else if(x =='*' || x == '/')
        return 3;
    else if(x=='^')
        return 6;
    else if(x == '(')
        return 7;
    else if(x == ')')
        return 0;

}
int instack(char x)
{
    if(x=='+' || x=='-')
        return 2;
    else if(x =='*' || x == '/')
        return 4;
    else if(x=='^')
        return 5;
    else if(x=='(')
        return 0;
    else if(x == ')')
        return 0;
}

int isOperand(char x)
{
    if(x=='+' ||x=='-' ||x=='*' ||x=='/'|| x == '(' || x == '^' || x == ')')
        return 0;
    else 
        return 1;
}

char* InToPsot(char *infix)
{
    int i=0,  j =0;
    char *postfix;
    int  len = strlen(infix);
    postfix = (char*)malloc((len+2)*sizeof(char));

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(outstack(infix[i])> instack(stack[top]))
            {
                push(infix[i]);
                i++;
            }
            else
            {
                if(outstack(infix[i]) == instack(stack[top]))
                {
                   push(infix[i]);
                    i++;
                }
                
                else
                {
                    postfix[j]=pop();
                    j++;
                }
            }
        }
    }
    while(top>=0)
    {
        if(stack[top]!='(' || stack[top]!=')')
            postfix[j++]= pop();
    }
    postfix[j] = '\0';
    return postfix;
}

void revstr(char *str1)  
{  
  
    int i, len, temp;  
    len = strlen(str1); 

    for (i = 0; i < len/2; i++)  
    {  
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}  

int main()
{
    char str[N] ; 
    printf("Enter the Expression : ");
    scanf("%s", &str);
    revstr(str);

    char *infix =str;
    
    char *postfix=InToPsot(infix);
    revstr(postfix);
     printf("The prefix Evaluation of Expression is \n: %s",postfix);
}