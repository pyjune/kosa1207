#include <stdio.h>

int bat[10];
int minV;
void f(int n, int k, int e, int c); // n 정류장, k 종점, e 남은에너지, c 교환횟수 

int main(void) 
{
	int T;
	int N;
	
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N); // 종점 번호 
		minV = 10;
		for(int i = 1; i <= N - 1; i++)
		{
			scanf("%d", &bat[i]); // 정류장 별 배터리 용량 
		}
		//f( 1, N, 0, 0); // 1번부터 교환횟수를 고려하는 경우... 
		f( 2, N, bat[1] - 1, 0);
		printf("#%d %d\n", tc, minV);
	}

	return 0;
}

void f(int n, int k, int e, int c)
{
	if(n==k)
	{
		if(minV>c)
			minV = c;
	}
	else
	{
		// 통과
		if(e>0) // 에너지가 남아있어야 함 
			f(n+1, k, e-1, c);
		// 교체
		f(n+1, k, bat[n]-1, c+1);
	}
}
