#include <stdio.h>
#define INF 0x7fffffff

int map[500][500];
int u[500][500];
int d[500][500];
int N;

void dij(void);

int main(void) 
{
	int T;
	freopen("input.txt","r",stdin);
	scanf("%d", &T);
	for(int tc = 1; tc<=T; tc++)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		dij();
		printf("#%d %d\n", tc, d[N-1][N-1]);
	}
	return 0;
}

void dij(void)
{
	int di[] = {0, 1, 0, -1};
	int dj[] = {1, 0, -1, 0}; 
	// u[s] = 1, d[] 초기화

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			d[i][j] = INF;
			u[i][j] = 0;
		}
	}
	u[0][0] = 1; // 시작점은 경유지로 표시 
	d[0][0] = 0; // 시작점에 인접인 곳의 비용 초기화 
	d[0][1] = 1 + (map[0][1]>map[0][0]?map[0][1] - map[0][0]:0);
	d[1][0] = 1 + (map[1][0]>map[0][0]?map[1][0] - map[0][0]:0);
	int cnt = 1;
	while(cnt<N*N)
	{
		cnt++;
		// u[] = 0이고 d[t]가 최소인 t찾기..
		int minI;
		int minJ;
		int minV = INF;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j<N; j++)
			{
				if((u[i][j]==0) && (minV>d[i][j]))
				{
					minV = d[i][j];
					minI = i; 
					minJ = j;
				}
			}
		}
		u[minI][minJ] = 1;
		// t(minI, minJ)에 인접인 칸에 대해 t를 거쳐가는 비용과 기존비용 비교
		for(int k = 0; k < 4; k++)
		{
			int ni = minI + di[k];
			int nj = minJ + dj[k];
			if(ni>=0 && ni<N && nj>=0 && nj<N)
			{
				int h = (map[ni][nj]>map[minI][minJ]?map[ni][nj]-map[minI][minJ]:0);
				if(d[minI][minJ]!=INF)
					d[ni][nj] = (d[ni][nj]>(d[minI][minJ] + 1 + h)?(d[minI][minJ] + 1 + h):d[ni][nj]);
			}
		}
		 
	}
}
