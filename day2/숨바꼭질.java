import java.util.Scanner;

public class Main {
	static int [] visited;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		visited = new int[100001];
		System.out.println(bfs(n, k));
	}
	public static int bfs(int n, int k)
	{
		int [] q = new int [100001];
		int front = -1;
		int rear = -1;
		// 시작점  enqueue, 방문표시
		q[++rear] = n;
		visited[n] = 1;
		while( front != rear )
		{
			n = q[++front]; // dequeue
			if( n == k )
			{
				return (visited[n] -1);
			}
			// n에 인접이고, 방문하지 않은 노드  enqueue, 방문표시
			if(( n-1>=0) && (visited[n-1]==0))
			{
				q[++rear] = n-1;
				visited[n-1] = visited[n] + 1;
			}
			if((n+1<=100000)&&(visited[n+1]==0))
			{
				q[++rear] = n+1;
				visited[n+1] = visited[n] + 1;
			}
			if((n*2<=100000)&&(visited[n*2]==0))
			{
				q[++rear] = n*2;
				visited[n*2] = visited[n] + 1;
			}
		}
		return 0;
	}
}
