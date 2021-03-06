/*
Problem Description
the second year of the university somebody started a study on the romantic relations between the students. The relation “romantically involved” is defined between one girl and one boy. For the study reasons it is necessary to find out the maximum set satisfying the condition: there are no two students in the set who have been “romantically involved”. The result of the program is the number of students in such a set.

The input contains several data sets in text format. Each data set represents one set of subjects of the study, with the following description:

the number of students
the description of each student, in the following format
student_identifier:(number_of_romantic_relations) student_identifier1 student_identifier2 student_identifier3 ...
or
student_identifier:(0)

The student_identifier is an integer number between 0 and n-1, for n subjects.
For each given data set, the program should write to standard output a line containing the result.
 

Sample Input
7
0: (3) 4 5 6
1: (2) 4 6
2: (0)
3: (0)
4: (2) 0 1
5: (1) 0
6: (2) 0 1
3
0: (2) 1 2
1: (1) 0
2: (1) 0
 

Sample Output
5
2

*/

#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

namespace maxMatchNS
{
    int nx, ny;
    vector<int> matchX, matchY;
    vector< vector<int> > biGraph;

    void initialize(vector< vector<int> > graph)
    {
        nx = graph.size();
        ny = graph[0].size();
        matchX.resize(nx);
        matchY.resize(ny);
        biGraph = graph;

       for(int i = 0;i < nx;i++)
            matchX[i] = -1;
       for(int i = 0;i < ny;i++)
            matchY[i] = -1;
    }
}

vector<int> yUsed;
// find augment path
int path(int xNode)
{
    for(int i = 0;i < maxMatchNS::ny;i++)
    {
        if (maxMatchNS::biGraph[xNode][i] && !yUsed[i])
        {
            yUsed[i] = 1;

            if (maxMatchNS::matchY[i] == -1 || path(maxMatchNS::matchY[i]))
            {
                maxMatchNS::matchX[xNode] = i;
                maxMatchNS::matchY[i] = xNode;
                return 1;
            }
        }
    }
    return 0;
}

int maxMatch(vector< vector<int> > graph)
{
    maxMatchNS::initialize(graph);
    yUsed.resize(maxMatchNS::ny);

    int res = 0;
    for(int i = 0;i < maxMatchNS::nx;i++)
    {
        for(int j = 0;j < maxMatchNS::ny;j++)
            yUsed[j] = 0;
        res += path(i);
    }

    return res;
}


int main()
{
    int n;
    
    while(cin >> n)
    {
        vector< vector<int> > graph;
        graph.resize(n);
        for(int i = 0;i < n;i++)
            graph[i].resize(n);
        
        for(int i = 0;i < n;i++)
        {
            int id, fNum;
            scanf("%d: (%d)", &id, &fNum);
        
            for(int j = 0;j < fNum;j++)
            {
                int sId;
                cin >> sId;
                graph[id][sId] = 1;
            }
        }
        
        cout << (n * 2 - maxMatch(graph)) / 2 << endl;
    }
    return 0;
}
