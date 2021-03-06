/*
描述
菲波那切数列可以用下列的式子表示:
f(1)=1
f(2)=1
f(n)=f(n-1)+f(n-2) (n>=3)

现在我们根据这个规则定义另一种数列 命名为"辛波那切数列", 它是这样定义的：
s(x)=0 (x<0)
s(x)=1 (0<=x<1)
s(x)=s(x-1)+s(x-3.14) (x>=1)

现在需要计算出s(x) MOD 1000000007的值。
输入
第一行有一个正整数T表示有T组测试数据。
接下来T行,每行包含一个数x。
其中 T<=10000, -1000.0<=x<=1000.0
输出
有T行，依次输出每组数据的结果。
样例输入
3
-1
0.667
3.15
样例输出
0
1
2
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 100005
#define MOD 1000000007

long long buf[N];
long long resolve(int a)
{
	if (a < 0)
		return 0;
	if (!buf[a])
		buf[a] = (resolve(a - 100) + resolve(a - 314)) % MOD;
	return buf[a];
}

int main()
{
	int i;
	int ncase;
	int aInt;
	double a;

	scanf("%d", &ncase);
	memset(buf, 0, sizeof(buf));
	for(i = 0;i < 100;i++)
		buf[i] = 1;

	while(ncase--)
	{
		scanf("%lf", &a);
		if (a < 0)
		{
			printf("0\n");
			continue;
		}
		aInt = (int)(a * 100);
		printf("%lld\n", resolve(aInt));
	}
	return 0;

}
