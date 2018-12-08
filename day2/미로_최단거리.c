#include <stdio.h>

int maze[100][100];
int N;

int q[20000];
int front;
int rear;
int visited[100][100];

int find(int r, int c);

int main(void) 
{
	int T;
	int sr, sc;
	int d;
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		front = -1;
		rear = -1;
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				scanf("%1d", &d);
				maze[i][j] = d;
				if(d == 2) // 시작 좌표 
				{
					sr = i;
					sc = j;
				}
			}
		}
		printf("#%d %d\n", tc, find(sr, sc));
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				visited[i][j] = 0;
			}
		}
	}

	return 0;
}

int find(int r, int c)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
 	// 시작노드 인큐와 방문표시 
	q[++rear] = r;
	q[++rear] = c;
	visited[r][c] = 1; 
	while(front != rear) // 큐가 비어있지 않으면 
	{
		r = q[++front];
		c = q[++front];
		if(maze[r][c] == 3)
		{
			return visited[r][c] - 2; // 출발, 도착칸 제외 
		}
		// 인접하고 미방문인 노드 인큐... 
		for(int k = 0; k < 4; k++)
		{
			int nr = r + dr[k];
			int nc = c + dc[k];
			if((maze[nr][nc] != 1) && (visited[nr][nc] == 0)) // 벽이 아니고(인접) 미방문이면
			{
				q[++rear] = nr;
				q[++rear] = nc;
				visited[nr][nc] = visited[r][c] + 1;	
			} 
		}
	}
	return 0;
}
