#include <iostream>
#include <string>
using namespace std;

bool isAlphaNumeric(char ch)
{
    if((ch >= 0 && ch<=9) || (ch>='A' && ch<= 'Z') || (ch>='a' && ch<='z'))
        return true;
    else
        return false;
}
bool isPalindrome(string str){
    int st = 0, en = str.length()-1;
    while(st<en)
    {
        if(isAlphaNumeric(str[st]))
        {
            st++;
            continue;
        }
        if(isAlphaNumeric(str[en]))
        {
            en--;
            continue;
        }
        if(islower(str[st]) != islower(str[en]))
            return false;
        st++;
        en--;
    }
    return true;
}
int main()
{
    int n;
    string str;
    cout<<"Enter the length of the string: ";
    cin>>n;
    cout<<"Enter the string value: ";
    getline(cin,str,'.');
    if(isPalindrome(str) == true)
        cout<<"Valid Palindrome";
    else
        cout<<"Not a valid Palindrome";
    return 0;
}