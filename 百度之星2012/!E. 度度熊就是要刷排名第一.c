/*
描述：一天度度熊在Baidu游戏大厅中发现了一个隐藏的神奇游戏，叫做“度度熊的逆袭”。度度熊很好奇到底是什么情况，于是就进入了游戏。这个游戏很神奇，游戏会给出n个数Ai，度度熊可以任意从中选取一些数，一个数可以选任意多次。选好之后度度熊得到的分数为度度熊选出的数的Xor(异或)值。度度熊顿时产生了兴趣，决心要刷至Ranklist的第一名。但是度度熊犯难了，度度熊不知道自己给出的方案是不是最好的，于是度度熊找到了你，希望你告诉他对于某个回合，度度熊能得到的最高分和第二高分是多少？

输入
第1行1个数n，接下来1行n个整数表示Ai, (0<=Ai<231)
1<=n<=105

输出
输出一行两个数，表示度度熊能够得到的最高分和第二高分为多少

样例输入
2
5 3

样例输出
6 5

*/


#include <iostream>
using namespace std;

int record[10000

int main()
{
	scanf("%d", &n);
	int max = 0;
	for(i = 0;i < n;i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] > max)
			max = arr[i];
	}

	for(i = 0;i < n;i++)
	
}
