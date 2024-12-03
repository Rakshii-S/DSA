#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int ShortestPathBFS(vector<vector<int>> &Croads)
{
    queue<int> Queue;
    unordered_set<int> visited;
    int distance = 0;
    Queue.push(0);
    visited.insert(0);
    while(!Queue.empty())
    {
        int size = Queue.size();
        while(size>0)
        {
            int node = Queue.front();
            Queue.pop();
            if(node == Croads.size()-1) 
                return distance;
            for(int neighbors: Croads[node])
            {
                if(visited.find(neighbors) == visited.end())
                {
                    Queue.push(neighbors);
                    visited.insert(neighbors);
                }
            }
            size--;
        }
        distance++;
    }
    return -1;
}

int main()
{
    int n, rows, cols;
    cout<<"Enter the number of cities: ";
    cin>>n;
    cout<<"Enter rows and columns: ";
    cin>>rows>>cols;
    cout<<"Enter the additional roads:";
    vector<vector<int>> queries(rows, vector<int>(cols));
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cin>>queries[i][j];
        }
    }

    //logic
    vector<vector<int>> Croads(n);
    vector<int> result(queries.size());
    for(int i=0;i<n-1;i++)
    {
        Croads[i].push_back(i+1);
    }

    for(int i=0;i<queries.size();i++)
    {
        Croads[queries[i][0]].push_back(queries[i][1]);
        result[i] = ShortestPathBFS(Croads);
    }
    //print the final answer
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
}