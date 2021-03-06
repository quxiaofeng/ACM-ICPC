/*
Problem Description
Homer: Marge, I just figured out a way to discover some of the talents we weren’t aware we had.
Marge: Yeah, what is it?
Homer: Take me for example. I want to find out if I have a talent in politics, OK?
Marge: OK.
Homer: So I take some politician’s name, say Clinton, and try to find the length of the longest prefix
in Clinton’s name that is a suffix in my name. That’s how close I am to being a politician like Clinton
Marge: Why on earth choose the longest prefix that is a suffix???
Homer: Well, our talents are deeply hidden within ourselves, Marge.
Marge: So how close are you?
Homer: 0!
Marge: I’m not surprised.
Homer: But you know, you must have some real math talent hidden deep in you.
Marge: How come?
Homer: Riemann and Marjorie gives 3!!!
Marge: Who the heck is Riemann?
Homer: Never mind.
Write a program that, when given strings s1 and s2, finds the longest prefix of s1 that is a suffix of s2.
 

Input
Input consists of two lines. The first line contains s1 and the second line contains s2. You may assume all letters are in lowercase.
 

Output
Output consists of a single line that contains the longest string that is a prefix of s1 and a suffix of s2, followed by the length of that prefix. If the longest such string is the empty string, then the output should be 0.
The lengths of s1 and s2 will be at most 50000.
 

Sample Input
clinton
homer
riemann
marjorie
 

Sample Output
0
rie 3
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

__int64 welcomeV[2][10005];
__int64 blockW[105][10005];
__int64 blockT[105][10005];

struct sumType
{
    __int64 start;
    __int64 value;
    sumType(__int64 s, __int64 v)
    {
        start = s;
        value = v;
    }
    sumType()
    {
        start = 0LL;
        value = 0LL;
    }
    bool operator()(const sumType &a, const sumType &b)
    {
        if (a.value < b.value)
            return 1;
        else
            return 0;
    }
};

int main()
{
    __int64 m, n, k;
    while(cin >> n >> m >> k, k || m || n)
    {
        __int64 now = 1LL, pre = 0LL;
       // memset(welcomeV, 0, sizeof(welcomeV));
        for(__int64 i = 0LL;i < 10005LL ;i++)
            welcomeV[0][i] = welcomeV[1][i] = 0LL;
        
        for(__int64 i = n;i >= 0LL;i--)
            for(__int64 j = 0LL;j < m;j++)
                scanf("%I64d", &blockW[i][j]);

        for(__int64 i = n;i >= 0LL;i--)
            for(__int64 j = 0LL;j < m;j++)
                scanf("%I64d", &blockT[i][j]);

        for(__int64 i = 0LL;i <= n;i++)
        {
            __int64 upBlock = 0LL;
            __int64 timeSum = 0LL;
            __int64 valueSum = 0;
            int temp = 0LL;
            priority_queue<sumType, vector<sumType>, sumType> maxSumQ;
            
            maxSumQ.push(sumType(0LL, welcomeV[pre][0]));
            welcomeV[now][0] = welcomeV[pre][0];
            for(__int64 j = 1LL;j <= m;j++)
            {
                valueSum += (__int64)(blockW[i][j - 1]);
                temp += blockW[i][j - 1];
                //if valu
            //    if (valueSum > temp)
             //      while(1);
                timeSum += blockT[i][j - 1];
                maxSumQ.push(sumType(j, welcomeV[pre][j] - valueSum)); 
                while(timeSum > k)
                {
                    timeSum -= blockT[i][upBlock];
                    upBlock++;
                }
                
                while(1)
                {
                    sumType maxSum = maxSumQ.top();
                    if (maxSum.start >= upBlock)
                    {
                        welcomeV[now][j] = maxSum.value + valueSum;
                        break;
                    }   
                    else
                        maxSumQ.pop();
                }
            }

            timeSum = 0LL;
            valueSum = 0LL;
            upBlock = m;
            temp = 0LL;
            priority_queue<sumType, vector<sumType>, sumType> maxSumQ2;
            maxSumQ2.push(sumType(m, welcomeV[pre][m]));
            for(__int64 j = m - 1;j >= 0LL;j--)
            {
                valueSum += (__int64)(blockW[i][j]);
                timeSum += (__int64)(blockT[i][j]);
                temp += blockW[i][j];
             //   if (valueSum > temp)
            //       while(1);
                maxSumQ2.push(sumType(j, welcomeV[pre][j] - valueSum)); 
                while(timeSum > k)
                {
                    timeSum -= blockT[i][upBlock - 1];
                    upBlock--;
                }
                while(1)
                {
                    sumType maxSum2 = maxSumQ2.top();
                    if (maxSum2.start <= upBlock)
                    {
                        if (welcomeV[now][j] < (maxSum2.value + valueSum))
                            welcomeV[now][j] = maxSum2.value + valueSum;
                        break;
                    }   
                    else
                        maxSumQ2.pop();
                }
            }
            now = 1 - now;
            pre = 1 - pre;
        }
        
        __int64 maxV = welcomeV[pre][0];
        for(__int64 i = 0LL;i <= m;i++)
            if (maxV < welcomeV[pre][i])
                maxV = welcomeV[pre][i];
        printf("%lld\n", maxV);
    }
    return 0;
}
