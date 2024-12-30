#include <iostream>
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string word;
    int count = 0, ans = INT_MIN;
    unordered_map<char, int> substr;
    cout<<"Enter the word:";
    getline(cin,word);

    for(int i=0;i<word.size();i++)
    {
        if(substr.find(word[i]) != substr.end())
        {
            count = 0;
            i = substr[word[i]];
            substr.clear();
            continue;
        }
        count++;
        ans = max(ans, count);
        substr[word[i]] = i;
    }

    cout<<ans;
}