#include <stdio.h>

int map[10][10];
int used[10][10];
int p[10];
int N;
int M;

int find(void);
int dfs(int i, int j, int n);

int main(void) {
	int T;
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &p[i]);
		}
		scanf("%d", &M);
		for(int i = 0; i < M; i++)
		{
			for(int j = 0; j < M; j++)
			{
				scanf("%d", &map[i][j]);
				used[i][j] = 0;
			}
		}
		printf("#%d %d\n", tc, find());
	}
	return 0;
}

int dfs(int i, int j, int n)
{
	int di[] = {0, 1, 0, -1};
	int dj[] = {1, 0, -1, 0};
	if(n == N) // 수열을 모두 찾은 경우
	{
		return 1;
	}
	else if(map[i][j] != p[n])
	{
		return 0;
	}
	else if(used[i][j] != 0)
	{
		return 0;
	}
	else
	{
		used[i][j] = 1; // 현재 숫자 사용
		for(int k = 0; k < 4; k++)
		{
			int ni = i + di[k];
			int nj = j + dj[k];
			if(ni>=0 && ni<M && nj>=0 && nj<M) // ni, nj가 유효한 영역이면 
			{
				//if(used[ni][nj] == 0)
				{
					if(dfs(ni, nj, n+1) == 1)
						return 1;
				}
			}
		} 
		used[i][j] = 0;
		return 0;
	} 
}

int find(void)
{
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(map[i][j] == p[0])
			{
				if(dfs(i, j, 0) == 1)
					return 1;
			}
		}
	}
	return 0;
}

