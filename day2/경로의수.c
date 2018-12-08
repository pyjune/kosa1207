#include <stdio.h>
/* 입력 
V E
n1 n2 ...
5 6
1 2 1 3 3 2 3 4 2 5 5 4
*/
int adj[6][6]; // [V+1][V+1] 
int visited[6]; // [V+1]
int V, E;
int cnt;
 
void dfs2(int n, int k);

int main(void) 
{
	
	scanf("%d %d", &V, &E);
	for(int i = 0; i < E; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		adj[n1][n2] = 1;
		//adj[n2][n1] = 1; // 무방향인 경우.. 
	}
	dfs2(1, 4);
	printf("%d\n", cnt);
	
	return 0;
}

void dfs2(int n, int k)
{
	if(n == k) // n 노드가 목적지면
	{
		cnt++; // 경로의 개수 추가 
	}
	else
	{ 
		visited[n] = 1;
		for(int i = 1; i <= V; i++) // 모든 노드 i에 대해
		{
			if((adj[n][i] != 0) && (visited[i] == 0)) // n에 인접하고 미방문이면 
			{
				dfs2(i, k);
			}
		}
		visited[n] = 0;
	}
} 


