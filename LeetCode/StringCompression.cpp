#include <iostream>
#include <vector>
#include <string>
using namespace std;

int StringCompression(vector<char> &chars)
{
    int n = chars.size(), idx=0;
    for(int i=0;i<n;i++)
    {
        char currChar = chars[i];
        int count = 0;
        while(i<n && chars[i] == currChar)
        {
            count++;
            i++;
        }
        if(count == 1)
            chars[idx++] = currChar;
        else
        {
            chars[idx++] = currChar;
            string c = to_string(count);
            for(int dig: c)
            {
                chars[idx++] = dig;
            }
        }
        i--;
    }
    return idx;
}

int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;
    vector<char> chars;
    cout<<"Enter the characters: ";
    for(int i=0;i<n;i++)
    {
        char ele;
        cin>>ele;
        chars.push_back(ele);
    }
    cout<<"Size of the compressed string is : "<<StringCompression(chars);
}