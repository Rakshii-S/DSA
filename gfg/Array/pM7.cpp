//Find intersection of intervals given by two lists

/*Given two 2-D arrays which represent intervals. Each 2-D array represents a list of intervals. Each list of intervals is disjoint and sorted in increasing order. Find the intersection or set of ranges that are common to both the lists.
 


Disjoint means no element is common in a list. Example: {1, 4} and {5, 6} are disjoint while {1, 4} and {2, 5} are not as 2, 3 and 4 are common to both intervals.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void inputValues(vector<vector<int>> &interval, int n)
{
    cout<<"Enter the intervals: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
             cin>>interval[i][j];
        }
    }
}

void FindIntersection(vector<vector<int>> &n1, vector<vector<int>> &n2)
{
    int l=INT_MIN,r=INT_MIN;
    int pointer1 = 0, pointer2=0;
    while(pointer1<n1.size() && pointer2<n2.size())
    {
        l = max(n1[pointer1][0], n2[pointer2][0]);
        r = min(n1[pointer1][1], n2[pointer2][1]);

        if(l<=r)
            cout<<"{"<<l<<" "<<r<<"}"<<endl;

        if(n1[pointer1][1]<n2[pointer2][1])
            pointer1++;
        else
            pointer2++; 
    }
}

int main()
{
    int n1, n2;
    cout<<"Enter the count of intervals in first set and second set: ";
    cin>>n1>>n2;
    vector<vector<int>> interval1(n1,vector<int>(2,0));
    vector<vector<int>> interval2(n2,vector<int>(2,0));

    inputValues(interval1, n1);
    inputValues(interval2, n2);

    //sort the arrays
    sort(interval1.begin(), interval1.end());
    sort(interval2.begin(), interval2.end());

    FindIntersection(interval1,interval2);
}