#include<stdio.h>
int count=0;
int main()
{
    char l[20],p[20];
    int n,r,x=0;
    printf("enter n and r .\n");
    scanf("%d %d",&n,&r);
    printf("\nEnter the string : ");
    scanf("%s",l);
    printf("\nThe list is :  %s ",l);
    printf("\n");
    permutation(l,n,r,p,x);

}
  del(char l[],int i,int n, char u[])
{
    int j;
    for(j=0;j<i;j++)
        u[j]=l[j];
    for(j=i;j<n-1;j++)
        u[j]=l[j+1];
}
 permutation(char l[],int n,int r,char p[],int m)
{
    int i;//count =0;
    char u[20];
    if(r==0)
    {
        p[m]='\0';
        printf("%s ",p);
       // printf("\nThe list is :  %s ",l);
        count++;
        if(count==6)
        {
            printf("\n");
            count=0;
        }
        return;

    }
    else
    {
        for(i=0;i<n;i++)
        {
            p[m]=l[i];
            del(l,i,n,u);
            permutation(u,n-1,r-1,p,m+1);

        }
        return;
    }
}
