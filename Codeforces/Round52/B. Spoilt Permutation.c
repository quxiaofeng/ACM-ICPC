#include <stdio.h>

int main()
{
	int n;
	int ans;
	int i, a, t, bg, flag;
	scanf("%d", &n);

	ans = 1;
	flag = 0;
	bg = -1;
	t = -1;
	for(i = 0;i < n;i++)
	{
		scanf("%d", &a);

		if (flag == -1)
		{
			if (a != i + 1)
				ans = 0;
			continue;
		}
		if (flag)
		{
			if (a + i != t)
				flag = -1;
		}
		else
		{
			if (a != i + 1)
			{
				bg = i;
				flag = 1;
				t = a + i;
			}
		}
	}
	if (ans)
		printf("%d %d\n", bg + 1, t - bg);
	else
		printf("0 0\n");
	return 0;
}
