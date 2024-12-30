#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool dfs(vector<vector<char>>&m, string &word, int row, int col, int k)
{
    int r = m.size();
    int c = m[0].size();
    if(k == word.size()) return true;

    if(row<0 || col<0 || row>=r || col>=c || m[row][col] != word[k]) return false;

    char temp = m[row][col];
    m[row][col] = '#';

    bool found = dfs(m,word,row+1, col, k+1) || dfs(m,word,row-1, col, k+1) || dfs(m,word,row, col+1, k+1) || dfs(m,word,row, col-1, k+1);

    m[row][col] = temp;
    return found; 
}

bool SearchString(vector<vector<char>>&m, string &word)
{
    int row = m.size();
    int col = m[0].size();
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
           if(dfs(m,word,i, j, 0)) return true;
        }
    }
    return false;
}

int main()
{
    int row, col;
    string word;
    cout<<"Enter the number of rows and columns: ";
    cin>>row>>col;
    vector<vector<char>> m(row,vector<char>(col));
    cout<<"Enter values for "<<row<<" and  "<<col<<":";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>m[i][j];
        }
    }

    cout<<"Enter the word to be searched: ";
    cin >> std::ws; // Discards leading whitespace
    getline(cin,word);

    cout<<SearchString(m,word);
}