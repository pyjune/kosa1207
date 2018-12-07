import java.util.Scanner;
import java.io.FileInputStream;

public class Solution {
	static int [] p;
	static int [] u;
	static int [][] t;
	static int min;
	public static void main(String[] args) throws Exception{

		System.setIn(new FileInputStream("Text.txt"));
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		for(int tc = 1; tc<=T; tc++)
		{
			int N = sc.nextInt();
			p = new int[N];
			u = new int[N];
			t = new int [N][N];
			min = Integer.MAX_VALUE;
			for(int i = 0; i<N; i++)
			{
				for(int j =0; j<N; j++)
				{
					t[i][j] =sc.nextInt();
				}
			}
			find(0, N, 0);
			System.out.println("#"+tc+" "+min);
		}
	}
	public static void find(int n, int k, int s)
	{
		if(n==k)
		{
			if(s<min)
			{
				min = s;
			}
		}
		else if(s>=min)
			return;
		else
		{
			for(int i = 0; i<k; i++)
			{
				if(u[i]==0)
				{
					u[i]=1;
					p[n] = i;
					find(n+1, k, s+t[p[n]][n]);
					u[i]=0;
				}
			}
		}
	}
}
