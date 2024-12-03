#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

string Swap(string currentState, int currZero, int newZero)
{
    swap(currentState[currZero], currentState[newZero]);
    return currentState;
}
int main()
{
    vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
    int n=2, m=3;
    vector<vector<int>> board(n, vector<int>(m));
    cout<<"Enter the board values: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>board[i][j];
        }
    }
    string target = "123450";
    string startState = "";
    for(auto &row:board)
    {
        for(int cell: row)
        {
            startState += to_string(cell);
        }
    }
    
    //bfs
    queue<string> Que;
    unordered_set<string> Vis;
    Que.push(startState);
    Vis.insert(startState);
    int moves = 0;
    while(!Que.empty())
    {
        int size = Que.size();
        while(size>0)
        {
            string currentState = Que.front();
            Que.pop();
            if(currentState == target)
            {
                cout<<"Number of moves is: "<<moves;
                return 0;
            } 
            int currZeroPos = currentState.find('0');
            for(int newZeroPos: directions[currZeroPos])
            {
                string nextState = Swap(currentState, currZeroPos, newZeroPos);
                if(Vis.find(nextState) == Vis.end())
                {
                    Que.push(nextState);
                    Vis.insert(nextState);
                }
            }
            size--;
        }
        moves++;
    }
    cout<<"Puzzle is already solved.";
}