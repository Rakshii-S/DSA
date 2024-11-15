#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string str,sub;
    cout<<"Enter the length of the string: ";
    cin>>n;
    cout<<"Enter the string value:";
    cin>>str;
    cout<<"Enter the sub string:";
    cin>>sub;
    cout<<str.find(sub)<<" ";
    while(str.length()>0 && str.find(sub)<str.length())
    {
        int position = str.find(sub);
        str.erase(position,sub.length());
    }
    cout<<"String after removing all the occurrences: "<<str;
    return 0;
}