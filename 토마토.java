// acmicpc.net 7576번

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static int M;
	static int N;
	static int [][] box;
	static int [][] visited;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		M = sc.nextInt();
		N = sc.nextInt();
		box = new int[N][M];
		visited = new int[N][M];
		int cnt = 0;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				box[i][j] = sc.nextInt();
				if(box[i][j] == 0)
					cnt++;
			}
		}
		System.out.println(bfs(cnt));
	}
	public static int bfs(int cnt)
	{
		int [] di = {0, 1, 0, -1};
		int [] dj = {1, 0, -1, 0};
		int last = 0;
		Queue<Integer> q = new LinkedList<>();
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				if(box[i][j] == 1)
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
			for(int k = 0; k < 4; k++)
			{
				int ni = i + di[k];
				int nj = j + dj[k];
				if(ni>=0 && ni<N && nj>=0 && nj<M)
				{
					if((visited[ni][nj] == 0)&&(box[ni][nj]==0))
					{
						q.add(ni);
						q.add(nj);
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
}
