#include <stdio.h>

int binary(int a[], int n, int x)
{
	int l=0, h=n-1, m;
	while(l<=h)
	{
		m = l+h/2;
		if(a[m]==x)
		{
			return m;
		}
		else if(a[m]<x)
		{
			l = m+1;
		}
		else
		{
			h = m-1;     
		}
	}
	return -1;
}
int main()
{
	int a[5] = {1,2,3,6,10};
	int x;
	printf("Enter the element: ");
	scanf("%d",&x);
	int n = sizeof(a)/sizeof(a[0]);
	int r = binary(a, n, x);
	if(r!=-1)
	{
		printf("Element found at index %d",r);
	}
	else
	{
		printf("Element not found");
	}
}
