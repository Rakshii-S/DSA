#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cout<<"Enter the string: ";
    getline(cin, s);
    int n = s.length();
    //step 1
    reverse(s.begin(), s.end());
    string word, ans = "";
    for(int i=0;i<n;i++)
    {
        word = "";
        while(s[i] != ' ' && i<n)
        {
            word+=s[i];
            i++;
        }
        //step 2
        reverse(word.begin(), word.end());
        if(word.length()>0)
        {
            ans += " " + word;
        }
    }
    cout<<"Reversed string: "<<ans.substr(1);
}