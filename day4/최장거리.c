#include <stdio.h>

int adj[1001][1001];
int ind[1001];
int d[1001];
int V;
int E;

int q[1000];

int find(void);

int main(void) {
	int T;
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &V, &E);
		for(int i = 0 ; i<E; i++)
		{
			int n1, n2, w;
			scanf("%d %d %d", &n1, &n2, &w);
			adj[n1][n2] = w;
			ind[n2]++; // 진입차수 = 도착으로 언급된 횟수 
		}
		printf("#%d %d\n", tc, find());
		for(int i= 0; i<=V; i++)
		{
			ind[i] = 0;
			d[i] = 0;
			for(int j = 0; j<=V; j++)
			{
				adj[i][j] = 0;
			}
		}
	}
	return 0;
}

int find(void)
{
	int front = -1;
	int rear = -1;
	// 0번노드에서 시작으로 정해져 있으므로..
	q[++rear] = 0;
	while(front != rear)
	{
		int n = q[++front];
		for(int i = 0; i <= V; i++) // n으로 진입하는 노드로 부터 최장거리 찾기 
		{
			if(adj[i][n] != 0)
			{
				if(d[n]<(d[i]+adj[i][n]))
					d[n] = d[i] + adj[i][n];
			}
		}
		for(int i = 0; i <= V; i++)
		{
			if(adj[n][i] != 0) // n에 인접인 노드 i에 대해 진입차수 1 감소 
			{
				ind[i]--;
				if(ind[i] == 0)
					q[++rear] = i; // i의 진입차수가 0이 된 경우 enqueue 
			}
		}
	}
	return d[V];
}
