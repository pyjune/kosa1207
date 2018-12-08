import java.util.Scanner;

public class Solution {
	static int [][] p;
	static int [][] used;
	static int [] a;
	static int N;
	static int M;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int tc = 1; tc <= T; tc++)
		{
			N = sc.nextInt();
			a = new int[N];
			for(int i = 0; i < N; i++)
			{
				a[i] = sc.nextInt();
			}
			M = sc.nextInt();
			p = new int[M][M];
			used = new int[M][M];
			for(int i = 0; i < M; i++)
			{
				for(int j = 0; j < M; j++)
				{
					p[i][j] = sc.nextInt();
				}
			}
			System.out.println("#"+tc+" "+search());
		}
	}
	public static int search()
	{
		for(int i = 0; i < M; i++)
		{
			for(int j = 0; j < M; j++)
			{
				if(p[i][j] == a[0])
				{
					if(find(i, j, 0)==1)
						return 1;
				}
			}
		}
		return 0;
	}
	// (i, j)에 n번 인덱스 숫자가 있는지 탐색
	public static int find(int i, int j, int n)
	{
		int [] di = { 0, 1, 0, -1};
		int [] dj = { 1, 0, -1, 0};
		if( n == N )
		{
			
			return 1;
		}
		else if(p[i][j] != a[n])
		{
			return 0;
		}
		else
		{
			used[i][j] = 1;
			for(int k = 0; k < 4; k++)
			{
				int ni = i+di[k];
				int nj = j+dj[k];
				if(ni>=0 && ni<M && nj>=0 && nj<M)
				{
					if(used[ni][nj] == 0) // 사용되지 않은 자리인 경우
					{
						if(find(ni, nj, n+1) == 1) //
							return 1; // 탐색중에 모두 찾은 경우
					}
				}
			}
			used[i][j] = 0;
			return 0;
		}
	}
}
