#include <stdio.h>

int rep(int n, int p[]);

int main(void) 
{
	int T;
	int N, M;
	int p[101];
	int cnt; 
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		cnt = 0;
		scanf("%d %d", &N, &M);
		for(int i = 1; i <= N; i++)
		{
			p[i] = i; // 각자 대표 원소로 초기화 
		}
		for(int i = 0; i < M; i++ )
		{
			int n1, n2;
			scanf("%d %d", &n1, &n2);
			p[rep(n2, p)] = rep(n1, p); // n2의 대표원소를 자기 자신에서 n1의 대표로 바꿈 
		}
		for(int i = 1; i <= N; i++)
		{
			if( p[i] == i)
			{
				cnt++; // 대표원소의 개수 확인 
			}	
		}
		printf("#%d %d\n", tc, cnt);	
	}
	return 0;
}

int rep(int n, int p[])
{
	while( p[n] != n)
	{
		n = p[n];
	}
	return n;
}
