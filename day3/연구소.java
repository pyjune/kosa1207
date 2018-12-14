import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static int N;
	static int M;
	static int [][] map;
	static int maxV;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		map = new int [N][M];
		maxV = 0;
		for(int i = 0; i<N; i++)
		{
			for(int j=0; j<M; j++)
			{
				map[i][j] = sc.nextInt(); 
			}
		}
		find(0, 3);
		System.out.println(maxV);
	}
	public static void find(int n, int k)
	{
		if(n==k)
		{
			int r = bfs();
			if( maxV < r)
				maxV = r;
		}
		else
		{
			for(int i = 0; i<N; i++ )
			{
				for(int j = 0; j<M; j++)
				{
					if(map[i][j] == 0)
					{
						map[i][j] = 1;
						find(n+1, k);
						map[i][j] = 0;
					}
				}
			}
		}
	}
	public static int bfs()
	{
		int [] di = {0, 1, 0, -1};
		int [] dj = {1, 0, -1, 0};
		int [][] map2 = new int[N][M];
		int cnt = 0;
		Queue<Integer> q = new LinkedList();
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j< M; j++)
			{
				map2[i][j] = map[i][j];
				if(map[i][j] == 2)
				{
					q.add(i);
					q.add(j);
				}
			}
		}
		while(!q.isEmpty())
		{
			int i = q.poll();
			int j = q.poll();
			for(int k = 0; k<4; k++)
			{
				int ni = i+di[k];
				int nj = j+dj[k];
				if(ni>=0 && ni<N && nj>=0 && nj<M)
				{
					if(map2[ni][nj]==0)
					{
						map2[ni][nj] = 2;
						q.add(ni);
						q.add(nj);
					}
				}
			}
		}
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				if(map2[i][j]==0)
					cnt++;
			}
		}
		return cnt;
	}
}
