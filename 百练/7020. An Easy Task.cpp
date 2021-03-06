/*
描述
You are given an easy task by your supervisor -- to find the best value of X, one of the parameters in an evaluation function, in order to improve the accuracy of the whole program.

However, after a few days' analysis, you realize that it is far harder than you imagine. There are so many values X can be, and the only way to find the best one among them is to try all these possible values one after another!

Fortunately, you know that X is an integer and thanks to the previous works by your senior fellow apprentices, you have got n constraints on X. Each constraint must be in one of the following forms:
1. < k: means that X is less than integer k;
2. > k: means that X is greater than integer k;
3. <= k: means that X is less than or equal to integer k;
4. >= k: means that X is greater than or equal to integer k;
5. = k: means that X is equal to integer k.

Now, you are going to figure out how many possible values X can be, so that you can estimate whether it is possible to finish your task before deadline.



输入
The first line contains an integer T (1 ≤ T ≤ 10) -- the number of test cases.

For each test case:
The first line contains an integer n. 0 ≤ n ≤ 10 000.
Then follows n lines, each line contains a comparison operator o and an integer k, separated by a single space. o can be one of “>”, “<”, “>=”, “<=”, and “=”. 0 ≤ | k | ≤ 1 000 000 000.
There is no contradictory between these constraints, in other word, at least one integer value meets all of them.
输出
For each test case, output one integer in a single line -- the number of possible values of X, or “-1” if the answer is infinite.
样例输入
1
2
> 2
<= 5
样例输出
3

*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int ncase;
    cin >> ncase;

    while(ncase--)
    {
        int n;
        cin >> n;

        int bg, ed;
        int bgf = 0, edf = 0;
        for(int i = 0;i < n;i++)
        {
            string op;
            cin >> op;

            int num;
            cin >> num;

            if (op == "=")
            {
                bg = num;
                ed = num;
                bgf = 1;
                edf = 1;
            }
            else if (op == "<=")
            {
				if (!edf || num < ed)
					ed = num;
                edf = 1;
            }
            else if (op == ">=")
            {
				if (!bgf || num > bg)
					bg = num;
                bgf = 1;
            }
            if (op == ">")
            {
				if (!bgf || num + 1 > bg)
					bg = num + 1;
                bgf = 1;
            }
            if (op == "<")
            {
				if (!edf || num - 1 < ed)
					ed = num - 1;
                edf = 1;
            }
        }

        if (!edf || !bgf)
            cout << -1 << endl;
        else
            cout << ed - bg + 1 << endl;
    }
    return 0;
}
