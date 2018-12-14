/*
5 6
1 2 3
1 3 1
2 5 4
3 2 1
3 4 2
5 4 2
*/
#include <stdio.h>
#define INF 0x7fffffff

int adj[6][6];
int u[6];
int d[6];
int V;
int E;

void dij(int n);

int main(void) 
{
	scanf("%d %d", &V, &E);
	for(int i = 1; i<=V; i++)
	{
		for(int j = 1; j<=V; j++)
		{
			if(i==j)
				adj[i][j] = 0;
			else
				adj[i][j] = INF;
		}
	}
	for(int i=0; i<E; i++)
	{
		int n1, n2, w;
		scanf("%d %d %d", &n1, &n2, &w);
		adj[n1][n2] = w;
	}
	dij(1);
	printf("%d\n", d[5]);
	return 0;
}

void dij(int n)
{
	int cnt = 1; // 경유지로 고려된 노드 수 
	u[n] = 1; // 시작점에 경유지 표시
	for(int i=1; i<=V; i++)
	{
		d[i] = adj[n][i]; // d[] 초기화 
	}
	while(cnt < V)
	{
		// 경유지로 고려안된 노드 중 d[t]가 최소인 t노드 찾기
		cnt++;
		int t;
		int minV = INF;
		for(int i=1; i<=V; i++)
		{
			if((u[i]==0)&&(d[i]<minV))
			{
				t = i;
				minV = d[i];
			}
		}
		u[t] = 1;// t를  경유지로 고려함 
		// t의 인접노드 i에 대해 t를 거쳐 i로 가는 비용과 기존 비용 비교
		for(int i = 1; i<=V; i++)
		{
			if((adj[t][i]!=0)&&(adj[t][i]!=INF))
			 	d[i] = (d[i]<(d[t]+adj[t][i])?d[i]:(d[t]+adj[t][i]));	
		} 
	}
}
