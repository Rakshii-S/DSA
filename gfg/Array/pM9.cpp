//Last Moment Before All Ants Fall Out of a Plank

/*Given a plank of length n with ants moving left and right at 1 unit per second. When ants collide, they reverse their directions and if an ant reaches either end of the plank, it falls off immediately.

Given two integer arrays, left[] and right[] denoting the positions of ants moving left and right respectively, find the time when the last ant falls off the plank.

Examples:
Input: n = 4, left[] = [2], right[] = [0, 1, 3]
Output: 4

Input: n = 4, left[] = [] right[] = [0, 1, 2, 3, 4]
Output: 4

Input: n = 3, left[] = [0], right[] = [3]
Output: 0
Explanation: The ants will fall off the plank as they are already on the end of the plank.

Approach:
The idea is based on the observation that whenever two ants collide and reverse their directions, then it is same as if there was no collision and they continue moving in their original paths. This is because both ants move at the same speed and their collision is same as passing through each other. 

If one ant is moving left and another is moving right, upon collision, they both switch directions but their distance to the nearest end of the plank remains unchanged. Therefore, the time it takes for each ant to fall off the plank is independent on the collisions. Now, we  can simply calculate the time to fall off the plank(without collisions) for each ant and the maximum time among all ants will be the final result. */

#include <iostream>
#include <vector>
using namespace std;

int getLastMoment(int n ,vector<int> &left , vector<int> &right)
{
    int res = 0;
    //left
    for(int i=0;i<left.size();i++)
    {
        res = max(res,left[i]);
    }

    //right
    for(int i=0;i<right.size();i++)
    {
        res = max(res,n - right[i]);
    }

    return res;
}

int main()
{
    int n1, n2,n;
    cout<<"Enter the number of ants on the left and on the right: ";
    cin>>n1>>n2;
    vector<int> left(n1,0);
    vector<int> right(n2,0);

    cout<<"Enter the ants moving towards left: \n";
    for(int i=0;i<n1;i++)
    {
        cin>>left[i];
    }
    cout<<"Enter the ants moving towards right: ";
    for(int i=0;i<n2;i++)
    {
        cin>>right[i];
    }

    cout<<"Enter the length of the plank: ";
    cin>>n;

    cout<<"The time when the last ant falls off the plank is: "<<getLastMoment(n,left, right);
}