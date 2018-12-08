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
int stack[6];
int top = -1;

void dfs(int n);
int dfs2(int n, int k); // k에 도달하면 1, 아니면 0 리턴
 
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
	//dfs(1);
	printf("%d\n", dfs2(2, 3));
	return 0;
}

int dfs2(int n, int k) // k에 도달하면 1, 아니면 0 리턴
{
	stack[++top] = n; // 시작노드 push()
	visited[n] = 1;
	while(top >= 0) // 스택이 비어있지 않으면 반복	
	{
		n = stack[top--]; // pop()
		if(n == k) // n번 노드 처리
			return 1;
		for(int i = 1; i <= V; i++) // 모든 노드 i에 대해 
		{
			if((adj[n][i] !=0 ) && (visited[i] == 0)) // 인접이고 처리 전이면 
			{
				stack[++top] = i;
				visited[i] = 1;
			} 			
		} 
	}
	return 0;
} 

void dfs(int n) // 단순탐색
{
	stack[++top] = n; // 시작노드 push()
	visited[n] = 1;
	while(top >= 0) // 스택이 비어있지 않으면 반복	
	{
		n = stack[top--]; // pop()
		printf("%d ", n); // n번 노드 처리
		for(int i = 1; i <= V; i++) // 모든 노드 i에 대해 
		{
			if((adj[n][i] !=0 ) && (visited[i] == 0)) // 인접이고 처리 전이면 
			{
				stack[++top] = i;
				visited[i] = 1;
			} 			
		} 
	}
} 
