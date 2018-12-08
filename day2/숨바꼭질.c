#include <stdio.h>

int visited[100001];
int q[1000000];
int front = -1;
int rear = -1;

int find(int n, int k);

int main(void) 
{
	int N, K;
	scanf("%d %d", &N, &K);
	
	printf("%d\n", find(N, K));
	
	return 0;
}

int find(int n, int k)
{
	q[++rear] = n; // 시작점 인큐 
	visited[n] = 1;
	while(front != rear) // 큐가 비어있지 않으면 반복
	{
		n = q[++front];
		if(n == k)
		{
			return (visited[k] - 1);
		}
		// 인접이고 미방문이면..
		if(n-1>=0 && visited[n-1]==0)
		{
			q[++rear] = n-1;
			visited[n-1] = visited[n] + 1;
		}
		if(n+1<=100000 && visited[n+1]==0)
		{
			q[++rear] = n+1;
			visited[n+1] = visited[n] + 1;
		}
		if(n*2<=100000 && visited[n*2]==0)
		{
			q[++rear] = n*2;
			visited[n*2] = visited[n] + 1;
		}
	}
	return 0; 
}
