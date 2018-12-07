#include <stdio.h>

int p[10];
int used[11];
int t[11][11];
int minV;

void find(int n, int k);

int main(void) 
{
	int T;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		int N;
		scanf("%d", &N);
		minV = 0x7fffffff;
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				scanf("%d", &t[i][j]);
			}
		}
		used[1] = 1;
		p[0] = 1;
		find(1, N);
		printf("#%d %d\n", tc, minV);
	}
	return 0;
}

void find(int n, int k)
{
	if(n==k)
	{
		int s = 0;
		for(int i = 1; i<k; i++)
		{
			s+= t[p[i-1]][p[i]];
		}
		s+=t[p[k-1]][1];// 마지막 나무->사무실
		if(minV>s)
			minV = s; 
	}
	else
	{
		for(int i = 1; i<=k; i++)
		{
			if(used[i]==0)
			{
				used[i] = 1;
				p[n] = i;
				find(n+1, k);
				used[i] = 0;
			}
		}
	}
}
