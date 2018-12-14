#include <stdio.h>

int box[1000][1000];
int visited[1000][1000];
int M, N;
int cnt;
int q[2000000];
int front = -1;
int rear = -1;

int find(void);

int main(void) {
	scanf("%d %d", &M, &N);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			scanf("%d", &box[i][j]);
			if(box[i][j] == 0)
				cnt++;
		}
	}
	printf("%d\n", find());
	return 0;
}

int find(void)
{
	int di[] = {0, 1, 0, -1};
	int dj[] = {1, 0, -1, 0};
	int last = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(box[i][j] == 1)
			{
				q[++rear] = i;
				q[++rear] = j;
			}
		}
	}
	while(front != rear)
	{
		int i = q[++front];
		int j = q[++front];
		for(int k = 0; k < 4; k++)
		{
			int ni = i + di[k];
			int nj = j + dj[k];
			if(ni>=0 && ni<N && nj>=0 && nj<M)
			{
				if((visited[ni][nj] == 0)&&(box[ni][nj]==0))
				{
					q[++rear] = ni;
					q[++rear] = nj;
					visited[ni][nj] = visited[i][j] + 1;
					last = visited[ni][nj];
					cnt--;
				}
			}
		}
	}
	if(cnt!=0)
		last = -1;
	return last;	
}
