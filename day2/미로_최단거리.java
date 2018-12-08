import java.io.FileInputStream;
import java.util.Scanner;

public class Solution {
	static int [][] maze;
	static int cnt; // 경로의 수 저장
	static int minV; // 최단 거리
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int tc = 1; tc <= T; tc++)
		{
			int N = sc.nextInt();
			int sti = 0;
			int stj = 0;
			cnt = 0;
			minV = Integer.MAX_VALUE;
			maze = new int[N][N];
			for(int i=0; i < N; i++)
			{
				String str = sc.next();
				for(int j = 0; j < N; j++)
				{
					maze[i][j] = str.charAt(j) - '0';
					if(maze[i][j] == 2)
					{
						sti = i;
						stj = j;
					}
				}
			}
			//find(sti, stj); //  경로의 수
			//System.out.println("#"+tc+" "+cnt);
//			find2(sti, stj, 0); // dfs 최단거리
//			if(minV == Integer.MAX_VALUE)
//				minV = 1;
//			System.out.println("#"+tc+" "+(minV-1));
			// bfs  최단거리.
			System.out.println("#"+tc+" "+bfs(sti,stj,N));
		}
	}
	// dfs, 최단 거리..
	public static void find2(int i, int j, int e)
	{
		int [] di = {0, 1, 0, -1};
		int [] dj = {1, 0, -1, 0};
		if(maze[i][j] == 3)
		{
			if(minV > e)
				minV = e;
		}
		else if( maze[i][j] == 1)
		{
			return;
		}
		else
		{
			maze[i][j] = 1; // 무한반복 방지
			for(int k = 0; k < 4; k++)
			{
				int ni = i + di[k];
				int nj = j + dj[k];
				find2(ni, nj, e+1);
			}
			maze[i][j] = 0; // 다른 경로로 진입 허용
		}
	}
	// 경로의 개수
	public static void find(int i, int j)
	{
		int [] di = {0, 1, 0, -1};
		int [] dj = {1, 0, -1, 0};
		if(maze[i][j] == 3)
		{
			cnt++;
		}
		else if( maze[i][j] == 1)
		{
			return;
		}
		else
		{
			maze[i][j] = 1; // 무한반복 방지
			for(int k = 0; k < 4; k++)
			{
				int ni = i + di[k];
				int nj = j + dj[k];
				find(ni, nj);
			}
			maze[i][j] = 0; // 다른 경로로 진입 허용
		}
	}
	
	//bfs, 최단거리..
	public static int bfs(int i, int j, int N)
	{
		int [] di = {0, 1, 0, -1};
		int [] dj = {1, 0, -1, 0};
		int [] q = new int [20000];
		int front = -1;
		int rear = -1;
		int [][] visited = new int[N][N];
		// 시작점 enqueue
		q[++rear] = i;
		q[++rear] = j;
		visited[i][j] = 1;
		while(front != rear)
		{
			i = q[++front];
			j = q[++front];
			if(maze[i][j]==3)
				return visited[i][j] - 2;
			// 인접이고, 미방문이면 enqueue
			for(int k = 0; k < 4; k++)
			{
				int ni = i + di[k];
				int nj = j + dj[k];
				if(maze[ni][nj] != 1 && visited[ni][nj] == 0)
				{
					q[++rear] = ni;
					q[++rear] = nj;
					visited[ni][nj] = visited[i][j] + 1;
				}
			}
		}
		return 0;
	}
}
