#include <stdio.h>

int a[] = {3, 1, 2, 7, 6, 4, 5, 4};
int d[8];

int main(void) 
{
	int N = sizeof(a)/sizeof(a[0]);
	// d[] 초기화
	for(int i= 0; i<N; i++)
	{
		d[i] = 1;	
	}
	int maxD = 0;
	for(int i = 1; i<N; i++)// a[i]가 수열의 마지막 원소일 때 d[i] 찾기
	{
		for(int j = 0; j < i; j++) // i앞의 모든  원소 j에 대해 
		{
			if(a[j] < a[i] && d[i] < (d[j] + 1))
				d[i] = d[j] + 1;
		}
		if(d[i]>maxD)
			maxD = d[i];
	}
//	for(int i = 1; i<N; i++)// a[i]가 수열의 마지막 원소일 때 d[i] 찾기
//	{
//		int maxV = 0;
//		for(int j = 0; j < i; j++) // i앞의 모든  원소 j에 대해 
//		{
//			if(a[j] < a[i] && d[j]>maxV)
//				maxV = d[j];
//		}
//		d[i] = maxV + 1;
//		if(d[i]>maxD)
//			maxD = d[i];
//	}
	printf("%d\n", maxD);
	return 0;
}
