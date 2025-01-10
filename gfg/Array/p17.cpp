//Missing and Repeating in an Array

/*Given an unsorted array of size n. Array elements are in the range of 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. Find these two numbers.

Examples: 

Input: arr[] = {3, 1, 3}
Output: Missing = 2, Repeating = 3
Explanation: In the array, 2 is missing and 3 occurs twice 


Input: arr[] = {4, 3, 6, 2, 1, 1}
Output: Missing = 5, Repeating = 1*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void FindEle(vector<int> &num, int &a, int &b)
{
    unordered_set<int> s;
    int n=num.size(),Esum=0, aSum=0;
    Esum = n*(n+1)/2;
    for(int i=0;i<num.size();i++)
    {
        aSum+=num[i];
        if(s.find(num[i]) != s.end())
        {
            a = num[i];
        }
        s.insert(num[i]);
    }

    b = (Esum + a) - aSum;
}

int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;
    vector<int> num(n,0);
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    int a=0, b=0;
    FindEle(num,a,b);

    cout<<"The repeating number: "<<a<<endl;
    cout<<"The missing number: "<<b;
    return 0;
}