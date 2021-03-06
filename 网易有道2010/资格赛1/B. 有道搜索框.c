/*
描述 
在有道搜索框中，当输入一个或者多个字符时，搜索框会出现一定数量的提示，如下图所示：
现在给你N个单词和一些查询，请输出提示结果，为了简化这个问题，只需要输出以查询词为前缀的并且按字典序排列的最前面的8个单词，如果符合要求的单词一个也没有请只输出当前查询词。 

输入 
第一行是一个正整数N，表示词表中有N个单词。
接下来有N行，每行都有一个单词，注意词表中的单词可能有重复，请忽略掉重复单词。所有的单词都由小写字母组成。
接下来的一行有一个正整数Q，表示接下来有Q个查询。
接下来Q行，每行有一个单词，表示一个查询词，所有的查询词也都是由小写字母组成，并且所有的单词以及查询的长度都不超过20，且都不为空
其中：N<=10000,Q<=10000 
输出 
对于每个查询，输出一行，按顺序输出该查询词的提示结果，用空格隔开。 
样例输入 
10 a ab hello that those dict youdao world your dictionary 6 bob d dict dicti yo z 
 
样例输出 
bob dict dictionary dict dictionary dictionary youdao your z 
*/


#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define N_CHAR 27
#define N 50
#define OUTL 8

struct node
{
	char c;
	int flag;
	struct node *next[N_CHAR];
};

char res[N];
struct node *root;
int outN;

void init()
{
	int i;
	root = (struct node *)malloc(sizeof(struct node));
	root->c = ' ';
	root->flag = 0;
	for(i = 0;i < N_CHAR;i++)
		root->next[i] = NULL;
}

void input(char *str)
{
	struct node *walk = root;
	struct node *temp;
	int i, j;
	int len = strlen(str);

	for(i = 0;i < len;i++)
	{
		if (walk->next[str[i] -'a'] == NULL)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->flag = 0;
			for(j = 0;j < N_CHAR;j++)
				temp->next[j] = NULL;
			walk->next[str[i] -'a'] = temp;
		}	
		walk = walk->next[str[i] -'a'];
	}
	walk->c = str[len - 1];
	walk->flag = 1;
}

void dfs(struct node *no, int depth)
{
	int i;
	if (outN >= OUTL)
		return;
	if (no->flag)
	{
		res[depth] ='\0';
		if (outN == 0)
			printf("%s", res);
		else
			printf(" %s", res);
		outN++;
	}
	for(i = 0;i < 26;i++)
		if (no->next[i])
		{
			res[depth] = i +'a';
			dfs(no->next[i], depth + 1);
		}
}
int main()
{
	int n, q;
	int i, j;
	int len;
	char str[N];
	struct node *temp;

	init();

	scanf("%d", &n);
	for(i = 0;i < n;i++)
	{
		scanf("%s", str);
		input(str);
	}

	scanf("%d", &q);
	for(i = 0;i < q;i++)
	{
		scanf("%s", str);
		temp = root;
		len = strlen(str);
		strcpy(res, str);
		res[len] = '\0';	
		outN = 0;
	
		for(j = 0;j < len;j++)
			if (temp->next[str[j] - 'a'] != NULL)
				temp = temp->next[str[j] - 'a'];
			else
				break;
		if ((j >= len && temp->flag) || j < len)
		{
			outN = 1;
			printf("%s", res);
		}
		if (j >= len)
		{
			for(j = 0;j < 26;j++)
				if (temp->next[j])
				{
					res[len] = 'a' + j;
					dfs(temp->next[j], len + 1);
				}
		}
		putchar('\n');
	}
	return 0;
}
