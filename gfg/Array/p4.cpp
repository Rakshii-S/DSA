// Maximu consecutive one's( or Zero's) in a binary array
//Three Great Candidates
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int ConsecutiveValues(vector<int> &num)
{
    int ans = 0, count = 0;
    int currEle = num[0];
    for (int i = 1; i < num.size(); i++)
    {
        if (num[i] == currEle)
        {
            count++;  // Increment count if the same element continues
        }
        else
        {
            ans = max(ans, count);  // Update maximum before resetting count
            currEle = num[i];       // Update current element
            count = 1;              // Reset count for the new sequence
        }
    }

    ans = max(ans, count);  // Final update to ensure last sequence is considered
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