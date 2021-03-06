/*
描述
Stan and Ollie are playing a guessing game. Stan thinks of a number between 1 and 10 and Ollie guesses what the number might be. After each guess, Stan indicates whether Ollie's guess is too high, too low, or right on. 
After playing several rounds, Ollie has become suspicious that Stan cheats; that is, that he changes the number between Ollie's guesses. To prepare his case against Stan, Ollie has recorded a transcript of several games. You are to determine whether or not each transcript proves that Stan is cheating.
输入
Standard input consists of several transcripts. Each transcript consists of a number of paired guesses and responses. A guess is a line containing single integer between 1 and 10, and a response is a line containing "too high", "too low", or "right on". Each game ends with "right on". A line containing 0 follows the last transcript.
输出
For each game, output a line "Stan is dishonest" if Stan's responses are inconsistent with the final guess and response. Otherwise, print "Stan may be honest".
样例输入
10
too high
3
too low
4
too high
2
right on
5
too low
7
too high
6
right on
0
样例输出
Stan is dishonest
Stan may be honest
*/


#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	int arr[15];
	int n;
	int i, ok;
	int res;
	char str[100];

	while(cin >> n, n)
	{
		getchar();
		memset(arr, 0, sizeof(arr));
		while(cin.getline(str, 100, '\n'))
		{
			if (strcmp(str, "right on") == 0)
			{
				if (arr[n])
					arr[n] = 2;
				else
					arr[n] = 3;
				res = n;
				break;
			}
			else if (strcmp(str, "too high") == 0)
			{
				if (!arr[n] || arr[n] == 1)
					arr[n] = 1;
				else
					arr[n] = 2;
			}
			else if (strcmp(str, "too low") == 0)
			{
				if (!arr[n] || arr[n] == -1)
					arr[n] = -1;
				else
					arr[n] = 2;
			}
			cin >> n;
			getchar();
		}

		ok = 1;
		for(i = 1;i < 11;i++)
		{
			if (!arr[i])
				continue;
			if (i < res && arr[i] != -1 || i > res && arr[i] != 1 || i == res && arr[i] != 3)
			{
			//	cout << i << " fdsa" << arr[i] << endl;
				ok = 0;
				break;
			}
		}

		if (ok)
			cout << "Stan may be honest" << endl;
		else
			cout << "Stan is dishonest" << endl;
	}	
	return 0;
}
