#include <stdio.h>
#include <string.h>
#define maxsize  100

char S[maxsize]= {0};

char strout[maxsize]= {0};
int Top=-1;
int Topstr=-1;
void push( int data )
{
    if (Top==maxsize-1)
        printf("\nStack is Full\n");
    else
    {
        Top++;
           S[Top] = data; 
        
    }
}

int pop()
{
    int data=-1;
    if (Top==-1)
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        data = S[Top] ;
        Top--;
        pushstr(data);

    }
    return data;
}

void pushstr( int data )
{
    if (Topstr==maxsize-1)
        printf("\nStack is Full\n");
    else
    {
        Topstr++;
           strout[Topstr] = data; 
        
    }
}
int popstr()
{
    int data=-1;
    if (Topstr==-1)
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        data = S[Topstr] ;
        Topstr--;

    }
    return data;
}
void display()
{
    int i;
    if (Top==-1)
        printf("\nStack is Empty");
    else
        for (i =0; i <=Top ; i++)
            printf("\n%c",S[i]);
}

int main()
{

    char str[100];
    scanf("%s",&str);
    int i = 0;
    while(str[i]!='\0')
    {

        if(str[i]=='*'||str[i]=='/'||str[i]=='-'||str[i]=='+'||str[i]=='^')
        {
            if(str[i]=='*'||str[i]'/')
            {
                if(S[Top]=='*'||S[Top]=='/'||S[Top]=='^'){
                    pop();
                    push(str[i]);
                }
                
            }
            else
            {
                push(str[i]);
            }
        }
        else{
            pushstr(str[i]);
        }

        i++;
    }
    display();
    return 0;
}
