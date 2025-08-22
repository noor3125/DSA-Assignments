#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cout<<"Enter number of rows (including sum row): ";
    cin>>m;
    cout<<"Enter number of columns (including sum col): ";
    cin>>n;
    int a[m][n];
    int i,j;
    cout<<"Enter elements ("<<(m-1)<<" x "<<(n-1)<<"):\n";
    for (i=0;i<m-1;i++)
    {
        for (j=0;j<n-1;j++)
        {
            cin>>a[i][j];
        }
    }
    for (i=0;i<m-1;i++)
    {
        a[i][n-1]=0;
        for (j=0;j<n-1;j++)
            a[i][n-1]+=a[i][j];
    }
    for (j=0;j<n-1;j++)
    {
        a[m-1][j]=0;
        for (i=0;i<m-1;i++)
            a[m-1][j]+=a[i][j];
    }
    a[m-1][n-1]=0;
    for (i=0;i<m-1;i++)
        a[m-1][n-1]+=a[i][n-1];
    cout<<"\nFinal Matrix with row & column sums:\n";
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}

