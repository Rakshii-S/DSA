#include <iostream>
#include <string>
using namespace std;

bool isFreqSame(int freq1[], int freq2[])
{
    for(int i=0;i<26;i++)
    {
        if(freq1[i] != freq2[i])
        {
            return false;
        }
    }
    return true;
}

bool CheckInclusion(string str1, string str2)
{
    int freq[26] = {0};
    for(int i=0;i<str2.length();i++)
    {
        freq[str2[i]-'a']++;
    }

    int winSize = str2.length();
    for(int i=0;i<str1.length();i++)
    {
        int windIdx = 0, idx=i;
        int winFreq[26]={0};

        while(windIdx<winSize && idx<str1.length())
        {
            winFreq[str1[idx]-'a']++;
            windIdx++;
            idx++;
        }

        if(isFreqSame(freq,winFreq))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string str1,str2;
    cout<<"Enter the string:";
    getline(cin,str1);
    cout<<"Enter the sub string:";
    getline(cin,str2);
    if(CheckInclusion(str1, str2))
    {
        cout<<"Permutation of sub string is present in the main string.";
    }else{
        cout<<"Permutation of sub string is not present in the main string.";
    }
}