/*
Description

Farmer John recently bought another bookshelf for the cow library, but the shelf is getting filled up quite quickly, and now the only available space is at the top.

FJ has N cows (1 ≤ N ≤ 20) each with some height of Hi (1 ≤ Hi ≤ 1,000,000 - these are very tall cows). The bookshelf has a height of B (1 ≤ B ≤ S, where S is the sum of the heights of all cows).

To reach the top of the bookshelf, one or more of the cows can stand on top of each other in a stack, so that their total height is the sum of each of their individual heights. This total height must be no less than the height of the bookshelf in order for the cows to reach the top.

Since a taller stack of cows than necessary can be dangerous, your job is to find the set of cows that produces a stack of the smallest height possible such that the stack can reach the bookshelf. Your program should print the minimal 'excess' height between the optimal stack of cows and the bookshelf.

Input

* Line 1: Two space-separated integers: N and B
* Lines 2..N+1: Line i+1 contains a single integer: Hi

Output

* Line 1: A single integer representing the (non-negative) difference between the total height of the optimal set of cows and the height of the shelf.

Sample Input

5 16
3
1
3
5
6
Sample Output

1
*/


#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[21];
int h,n,best;
void dfs(int k,int sum)
{
	if(sum>=h)
	{
		if(best>sum-h)
			best=sum-h;
		return;
	}
	if(k==n)
		return;
	dfs(k+1,sum+arr[k]);
	dfs(k+1,sum);
}
int main()
{
	int i;
	scanf("%d%d",&n,&h);
	best=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		best+=arr[i];
	}
	sort(&arr[0],&arr[n]);
	best-=h;
	dfs(0,0);
	printf("%d\n",best);
	return 0;
}
