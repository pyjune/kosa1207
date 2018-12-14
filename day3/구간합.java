public class Solution {
	static int [] a = {10, 11, 12, 13, 14, 15};
	static int [] tree;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int N = a.length;
		tree = new int[1000000];
		int r = mTree(1, 0, N-1);
		System.out.println(r);

		System.out.println(fTree(1, 0, N-1, 1, 3));
		System.out.println(fTree(1, 0, N-1, 2, 4));
		System.out.println(fTree(1, 0, N-1, 2, 3));
		System.out.println(fTree(1, 0, N-1, 2, 5));
		System.out.println(fTree(1, 0, N-1, 0, 3));
		
		cTree(0, N-1, 2, 5);
		System.out.println(fTree(1, 0, N-1, 1, 3));
		System.out.println(fTree(1, 0, N-1, 2, 4));
		System.out.println(fTree(1, 0, N-1, 2, 3));
		System.out.println(fTree(1, 0, N-1, 2, 5));
		System.out.println(fTree(1, 0, N-1, 0, 3));
		
	}
	public static void cTree(int s, int e, int i, int diff)
	{
		int n = 1;
		diff = diff - a[i];
		tree[n] += diff; // root
		while(s != e)
		{
			int m = ( s + e ) / 2;
			if( i <= m)
			{
				e = m;
				n = 2*n;
			}
			else
			{
				s = m + 1;
				n = 2*n + 1;
			}
			tree[n] += diff;
		}
	}
	public static int mTree(int n, int s, int e)
	{
		if(s==e) // leaf인 경우
		{
			tree[n] = a[s];
		}
		else
		{
			int m = (s + e) / 2;
			int r1 = mTree(n*2, s, m); // 왼쪽자식으로 이동
			int r2 = mTree(n*2+1, m+1, e); //  오른쪽 자식으로 이동
			tree[n] = r1 + r2;
		}
		return tree[n];
	}
	public static int fTree(int n, int s, int e, int l, int r)
	{
		if((e<l)||(r<s)) // 노드가 가진 구간이 찾는 구간을 벗어난 경우
		{
			return 0;
		}
		else if((l<=s)&&(e<=r)) // 찾는 구간에 포함된 노드
		{
			return tree[n];
		}
		else
		{
			int m = (s+e)/2;
			int r1 = fTree(n*2, s, m, l, r);
			int r2 = fTree(n*2+1, m+1, e, l, r);
			return (r1 + r2);
		}
	}
}
