#include <stdio.h>

int input[100005][3];

int main()
{
	long long res;
	int n, m, k, b;
	int i, j;
	scanf("%d %d %d", &n, &m, &k);

	for(i = 0;i < m;i++)
		scanf("%d %d %d", &input[i][0], &input[i][1], &input[i][2]);

	res = 0;
	for(i = 0;i < k;i++)
	{
		scanf("%d", &b);
		for(j = 0;j < m;j++)
			if (input[j][0] <= b && input[j][1] >= b)
				res += b - input[j][0] + input[j][2];
	}

	printf("%I64d\n", res);
	return 0;
}
