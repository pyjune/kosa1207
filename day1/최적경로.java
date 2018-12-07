import java.io.FileInputStream;
import java.util.Scanner;

public class Solution {
	static int [] used;
	static int [] p;
	static int [][] dis;
	static int minV;
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		//System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int tc = 1; tc <= T; tc++)
		{
			int N = sc.nextInt();
			minV = Integer.MAX_VALUE;
			used = new int[N+2];
			p = new int[N+2];
			dis = new int [N+2][N+2];
			int [][] pos = new int[N+2][2];
			pos[0][0] = sc.nextInt();
			pos[0][1] = sc.nextInt();
			pos[N+1][0] = sc.nextInt();
			pos[N+1][1] = sc.nextInt();
			for(int i = 1; i <= N; i++)
			{
				pos[i][0] = sc.nextInt();
				pos[i][1] = sc.nextInt();
			}
			for(int i = 0; i <= N+1; i++)
			{
				for(int j = 0; j <= N+1; j++)
				{
					dis[i][j] = Math.abs(pos[i][0] - pos[j][0]) + Math.abs(pos[i][1]-pos[j][1]);
				}
			}
			p[0] = 0;
			used[0] = 1;
			find(1, N+1, N+1);
			System.out.println("#"+tc+" "+minV);
		}
	}
	public static void find( int n, int k, int m)
	{
		if(n==k)
		{
			int s = 0;
			for(int i = 1; i < k; i++)
			{
				s += dis[p[i-1]][p[i]];
			}
			s += dis[p[k-1]][k]; // 마지막 고객 -> 집
			if( minV > s )
				minV = s;
		}
		else
		{
			for(int i = 0; i < m; i++)
			{
				if(used[i] == 0)
				{
					used[i] = 1;
					p[n] = i;
					find( n+1, k, m);
					used[i] = 0;
				}
			}
		}
	}
}
