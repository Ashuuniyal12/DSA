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

char* InToPre(char *infix)
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

int evaluate(char *postfix, int len)
{
    int x1,x2,r;
    for(int i=len-1 ;i>=0; i--)
    {
        if(isOperand(postfix[i]))
            push(postfix[i]);
        else
        {
            x1 = (int)(pop()-'0');
            x2 = (int)(pop()-'0');
            switch(postfix[i])
            {
                case'+':
                    r= x1+x2;
                    push((char)(r+48));
                    break;
                case'-':
                    r= x1-x2;
                    push((char)(r+48));
                    break;
                case'*':
                    r= x1*x2;
                    push((char)(r+48));
                    break;
                case'/':
                    r= x1/x2;
                    push((char)(r+48));
                    break;
            } 
        }
    }
    return (int)(pop()-'0');
}

void revstr(char *str1, int len)  
{  
  
    int i, len, temp;  
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
    int len = strlen(str);

    revstr(str,len);

    char *infix =str;
    
    char *postfix=InToPre(infix);

    revstr(postfix, len);
    printf("The prefix Evaluation of Expression is \n: %s",postfix);

    printf("\nThe result after evaluation of prefix expression is: %d", evaluate(postfix,len));
}