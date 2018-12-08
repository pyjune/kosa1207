import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Scanner;
public class Solution {

	static int V;
	static ArrayList<Integer>[] adjlist;
	static int [] visited;
	static int[][] adj;
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		//System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		for(int tc=1; tc<=10;tc++)
		{
			int E = sc.nextInt();
			int stx = sc.nextInt();
			V = 100;
			visited = new int[V+1];
			// 인접리스트
			adjlist = new ArrayList[V+1];
			adj = new int [V+1][V+1];
			for(int i = 0; i<=100; i++)
			{
				adjlist[i] = new ArrayList<>();
			}
			
			for(int i = 0; i < E/2; i++)
			{
				int n1 = sc.nextInt();
				int n2 = sc.nextInt();
					
				adj[n1][n2] = 1; // 인접행렬
				adjlist[n1].add(n2); // 인접리스트
			}
			bfs(stx);
			int maxIdx = 1;
			for(int i = 2; i <=V ; i++)
			{
				if(visited[maxIdx] <= visited[i])
				{
					maxIdx = i;
				}
			}
			System.out.println("#"+tc+" "+maxIdx);
		}
	}
	public static int bfs(int n)
	{
		int [] q = new int[V*10];
		int front = -1;
		int rear = -1;
		// 시작노드 인큐, 방문표시
		q[++rear] = n;
		visited[n] = 1;
		while( front != rear )
		{
			n = q[++front]; // dequeue
			
//			for(int i = 1; i <= V; i++)
//			{
//				if((adj[n][i]!=0)&&(visited[i]==0))
//				{
//					q[++rear] = i;
//					visited[i] = visited[n] + 1;
//				}
//			}
			//  인접리스트인 경우..
			for(int i=0; i<adjlist[n].size(); i++)
			{
				int t = adjlist[n].get(i);
				if(visited[t]==0)
				{
					q[++rear] = t;
					visited[t] = visited[n] + 1;
				}
			}
		}
		return 0;
	}
}
