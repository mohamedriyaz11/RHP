#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int mx=a[i-1][0];
            for(int k=0;k<=j;k++)
            {
                if(a[i-1][k]>mx)
                {
                    mx=a[i-1][k];
                }
            }
            a[i][j]+=mx;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}