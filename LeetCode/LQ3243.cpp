#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int ShortestPathBFS(vector<vector<int>> &gr)
{
    queue<int> Que;
    unordered_set<int> Vis;
    Que.push(0);
    Vis.insert(0);
    int dist = 0;
    while(!Que.empty())
    {
        int size = Que.size();
        while(size>0)
        {
            int node  = Que.front();
            Que.pop();
            if(node == gr.size()-1)
                return dist;
            for(int neighbour: gr[node])
            {
                if(Vis.find(neighbour) == Vis.end())
                {
                    Que.push(neighbour);
                    Vis.insert(neighbour);
                }
            }
            size--;
        }
        dist++;
    }
    return -1;
}

int main()
{
    int n, rows, cols;
    cout<<"Enter the number of cities: ";
    cin>>n;
    cout<<"Enter the rows and columns: ";
    cin>>rows>>cols;
    cout<<"Enter the addition of roads from one city to another: ";
    vector<vector<int>> queries(rows, vector<int>(cols));
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cin>>queries[i][j];
        }
    }

    //logic
    vector<vector<int>> gr(n);
    vector<int> result(queries.size());
    for(int i=0;i<n-1;i++)
    {
        gr[i].push_back(i+1);
    }
    for(int i=0;i<queries.size();i++)
    {
        gr[queries[i][0]].push_back(queries[i][1]);
        result[i] = ShortestPathBFS(gr);
    }

    //print th results
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
}