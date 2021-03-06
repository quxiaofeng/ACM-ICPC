/*
Robert is a famous engineer. One day he was given a task by his boss. The background of the task was the following:

Given a map consisting of square blocks. There were three kinds of blocks: Wall, Grass, and Empty. His boss wanted to place as many robots as possible in the map. Each robot held a laser weapon which could shoot to four directions (north, east, south, west) simultaneously. A robot had to stay at the block where it was initially placed all the time and to keep firing all the time. The laser beams certainly could pass the grid of Grass, but could not pass the grid of Wall. A robot could only be placed in an Empty block. Surely the boss would not want to see one robot hurting another. In other words, two robots must not be placed in one line (horizontally or vertically) unless there is a Wall between them.

Now that you are such a smart programmer and one of Robert's best friends, He is asking you to help him solving this problem. That is, given the description of a map, compute the maximum number of robots that can be placed in the map.


Input

The first line contains an integer T (<= 11) which is the number of test cases. 

For each test case, the first line contains two integers m and n (1<= m, n <=50) which are the row and column sizes of the map. Then m lines follow, each contains n characters of '#', '*', or 'o' which represent Wall, Grass, and Empty, respectively.


Output

For each test case, first output the case number in one line, in the format: "Case :id" where id is the test case number, counting from 1. In the second line just output the maximum number of robots that can be placed in that map.


Sample Input

2
4 4
o***
*###
oo#o
***o
4 4
#ooo
o#oo
oo#o
***#


Sample Output

Case :1
3
Case :2
5
*/


#include <iostream>
#include <cstring>
using namespace std;

int graph[2500][2500];
int visited[2500];
int matchX[2500], matchY[2500];
int nodeNum;

bool find(int x)
{
	for(int i = 0;i < nodeNum;i++)
	{
		if (!visited[i] && graph[x][i])
		{
			visited[i] = 1;
			if (matchY[i] == -1 || find(matchY[i]))
			{
				matchY[i] = x;
				matchX[x] = i;
				return true;
			}
		}
	}
	return false;
}

int maxMatch()
{
	int res = 0;
	for(int i = 0;i < nodeNum;i++)
		matchX[i] = matchY[i] = -1;
	for(int i = 0;i < nodeNum;i++)
	{
		memset(visited, 0, sizeof(visited));
		if (find(i))
			res++;
	}
	return res;
}

int main()
{
	int ncase;
	cin >> ncase;

	for(int icase = 1;icase <= ncase;icase++)
	{
		int m, n;
		string gross[55];

		cin >> m >> n;
		for(int i = 0;i < m;i++)
			cin >> gross[i];

		memset(graph, 0, sizeof(graph));

		int vIndex[55];
		for(int i = 0;i < 55;i++)
			vIndex[i] = i;
		int vNum = n;
		int hNum = 0;

		for(int i = 0;i < m;i++)
		{
			int flag = 0;
			for(int j = 0;j < n;j++)
			{
				if (gross[i][j] == 'o')
				{
					if (!flag)
					{
						flag = 1;
						hNum++;
					}
					graph[hNum - 1][vIndex[j]] = 1;
				}
				else if (gross[i][j] == '#')
				{
					flag = 0;
					vIndex[j] = vNum;
					vNum++;
				}
			}
		}
	
		nodeNum = max(hNum, vNum);
		cout << "Case :" << icase << endl << maxMatch() << endl;
	}
	return 0;
}
