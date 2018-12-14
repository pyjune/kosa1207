#include <iostream>

int tree[100];

int makeT(int n, int s, int e);
int findT(int n, int s, int e, int left, int right);
int changeT(int n, int s, int e, int i, int v); // a[i]의 값이 v로 바뀌는 경우 

int a[] = { 10, 11, 12, 13, 14, 15};

int main(void) 
{
	makeT(1, 0, sizeof(a)/sizeof(a[0])-1);
	printf("%d\n", findT(1, 0, sizeof(a)/sizeof(a[0])-1, 2, 4));
	changeT(1, 0, sizeof(a)/sizeof(a[0])-1, 2, 5);
	printf("%d\n", findT(1, 0, sizeof(a)/sizeof(a[0])-1, 2, 4)); 
	return 0;
}

int changeT(int n, int s, int e, int i, int v)
{
	int diff = v - a[i]; // 변화량 
	while(s<e)
	{
		tree[n] += diff; // i를 포함한 구간의 노드값 갱신 
		if(i<=(s+e)/2) // 왼쪽 자식 구간에 포함 
		{
			 e = (s + e) / 2;
			 n = n * 2;
		}
		else // 오른쪽 자식 구간에 포함 
		{
			s = (s + e) / 2 +1;
			n = n * 2 + 1;
		}
	}
	tree[n] += diff; // leaf노드 갱신 
}
int findT(int n, int s, int e, int left, int right)
{
	if((e<left)||(right<s)) // 노드의 구간이 찾는 구간을 벗어난 경우.. 
	{
		return 0;
	}
	else if((left<=s)&&(e<=right)) // 노드 구간이 찾는 구간에 포함된 경우 
	{
		return tree[n];
	}
	else
	{
		int m = (s+e)/2;
		int r1 = findT(n*2, s, m, left, right);
		int r2 = findT(n*2+1, m+1, e, left, right);
		return (r1+r2);
	}

}

int makeT(int n, int s, int e)
{
	if( s == e )
	{
		tree[n] = a[s];
		return a[s];
	}
	else
	{
		int m = (s+e)/2;
		int r1 = makeT(n*2, s, m);
		int r2 = makeT(n*2+1, m+1, e);
		tree[n] = r1 + r2;
		return tree[n];
	}
}
