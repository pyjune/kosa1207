#include <stdio.h>

int used[10];
int p[10];
int t[10][10];
int minV;

void npr(int n, int k, int m);

int main(void) 
{
	int T;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		int N;
		minV = 100;
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				scanf("%d", &t[i][j]);
			}		
		}
		//npr( 0, N, N);
		npr2(0, N, N, 0);
		printf("#%d %d\n", tc, minV);
	}
	return 0;
}

void npr2(int n, int k, int m, int s) // s : n-1까지 일을 하는데 걸리는 시간.. 
{
	if(n==k)
	{
		if(minV>s)
			minV = s;
	}
	else if( s >= minV)
	{
		return;
	}
	else
	{
		for(int i = 0; i < m; i++)
		{
			if(used[i] == 0)
			{
				used[i] = 1;
				p[n] = i;
				npr2(n+1, k, m, s+t[p[n]][n]);
				used[i] = 0;
			}
		}
	}
}
void npr(int n, int k, int m)
{
	if(n==k)
	{
		int s = 0;
		for(int i = 0; i < k; i++)
			s += t[p[i]][i];
		if(minV>s)
			minV = s;
	}
	else
	{
		for(int i = 0; i < m; i++)
		{
			if(used[i] == 0)
			{
				used[i] = 1;
				p[n] = i;
				npr(n+1, k, m);
				used[i] = 0;
			}
		}
	}
}
