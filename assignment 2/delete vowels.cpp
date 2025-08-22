#include<iostream>
using namespace std;
int main()
{
	char a[20];
	gets(a);
	int i,j;
	for (i=0;a[i]!='\0';i++)
	{
		if (a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
		{
			for (j=i;a[j]!='\0';j++)
			{
				a[j]=a[j+1];
			}
			i--;
		}
	}
	cout<<a;
}
