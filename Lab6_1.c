#include <stdio.h>
#define maxsize  10
int Q[maxsize]= {0};
int Front=-1, Rear=-1;
int size=0;
void enqueue(int);
int dequeue();
void displayQ();
int main()
{
    int i,n;
    for(i=1; i<1000; i*=2)
        enqueue(i);
    displayQ();
    scanf("%d",&n);
    for(i=1; i<=n; i++)
        dequeue();
    displayQ();
    for(i=10; i>=1; i/=2)
        enqueue(i);
    displayQ();
}

void enqueue ( int data )
{
    if (size == maxsize){

        printf("\nQueue is Full\n");
    }
    else
    {
        if (Front == -1 && Rear == -1)
        {
            Front =0;
            Rear =0;
        }
        else
        {
            Rear= (Rear+1)%maxsize;
        }
            Q[Rear] =data;
            size++;
        }

    }


int dequeue ()
{
    int data;
    if (size == 0)
    {
        printf("\nQueue is Empty\n");
        return -1;
    }
    else
    {
        data = Q[Front];
        Front =(Front+1)%maxsize;
        size--;
        return data;
    }
}

void displayQ()
{
    int i;
    if (size == 0)
        printf("\nQueue is Empty\n");
    else
    {
        printf("front[ ");
        for (i=0; i<size; i++)
            printf("%d ",Q[(Front+i)%maxsize]);
        printf("] rear \n");
    }
}

