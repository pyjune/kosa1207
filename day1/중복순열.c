#include <stdio.h>

int p[3];

void f(int n, int k);
void f2(int n, int k, int m); // k 순열의 길이, m 사용할 숫자의 개수 
int main(void) 
{
	
	//f(0, 3);
	f2(0, 3, 3);
	f2(0, 3, 5);
	return 0;
}
void f2(int n, int k, int m)
{
	if(n==k)
	{
		for(int i = 0; i < k; i++)
			printf("%d ", p[i]);
		printf("\n");
	}
	else
	{
		for(int i = 1; i<=m; i++)
		{
			p[n] = i;
			f2(n+1, k, m);
		}
	}
}
void f(int n, int k)
{
	if(n==k)
	{
		for(int i = 0; i < k; i++)
			printf("%d ", p[i]);
		printf("\n");
	}
	else
	{
		for(int i = 1; i<=k; i++)
		{
			p[n] = i;
			f(n+1, k);
		}
	}
}




