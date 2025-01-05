// Maximu consecutive one's in a binary array
//Three Great Candidates

/*Given a binary array, find the count of a maximum number of consecutive 1s present in the array.

Examples : 

Input: arr[] = {1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1}
Output: 4
Explanation: The maximum number of consecutive 1’s in the array is 4 from index 8-11.


Input: arr[] = {0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}
Output: 1
Explanation: The maximum number of consecutive 0’s in the array is 1 from index 0-1.*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int ConsecutiveValues(vector<int> &num)
{
    int ans = 0, count = 0;
    for (int i = 1; i < num.size(); i++)
    {
        if(num[i] == 1)
        {
            count++;
        }else{
            ans = max(ans, count);
            count = 0;
        }
    }
    ans = max(ans, count);
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;

    vector<int> num(n,0);
    cout<<"Enter the values (0's or 1's): ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }

    int ans = ConsecutiveValues(num);
    cout<<"Maximum consecutive in a binary array is: "<<ans;
    return 0;
}