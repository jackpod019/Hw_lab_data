#include <stdio.h>
void InsertionSort(int A[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && A[j] < A[j - 1])
        {
            temp = A[j];
            A[j] = A[j - 1];
            A[j - 1] = temp;
            j = j - 1;
        }
    }
}
int main()
{
    int n,max,i,sum=0,count=0;
    scanf("%d %d",&n,&max);
    int A[n];
    for(i=0; i<n; i++)
        scanf("%d",&A[i]);
    InsertionSort(A,n);
    for(i=0; i<n; i++)
    {
        sum = sum+A[i];
        if(sum>=max)
            break;
        count++;
    }
    printf("\n%d",count);
    return 0;
}