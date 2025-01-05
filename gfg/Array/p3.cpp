//Three Great Candidates
//Maximum product of a triplet(subsequence of size 3) in array

/*Given an integer array, find a maximum product of a triplet in the array.

Examples: 

Input:  [10, 3, 5, 6, 20]
Output: 1200
Explanation: Multiplication of 10, 6 and 20



Input:  [-10, -3, -5, -6, -20]
Output: -90



Input:  [1, -4, 3, -6, 7, 0]
Output: 168

*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int ThreeGreatCandidates(vector<int> &num)
{
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;
    int product1 , product2;
    for(int i=0;i<num.size();i++)
    {
        if(num[i]>max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = num[i];
        }else if(num[i] > max2 && num[i] < max1)
        {
            max3 = max2;
            max2 = num[i];
        }else if(num[i]>max3 && num[i]<max2 && num[i]<max1){
            max3 = num[i];
        }

        if(num[i]<min1)
        {
            min2 = min1;
            min1 = num[i];
        }else if(num[i]<min2 && num[i]>min1){
            min2 = num[i];
        }
    }
    product1 = max1*max2*max3;
    product2 = max1*min1*min2;
    return max(product1, product2);
}
int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;

    if(n<3)
    {
        cout<<"Array size should be greater than or equal to 3.";
        return 0;
    }

    vector<int> num(n,0);
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }

    int ans  = ThreeGreatCandidates(num);
    if(ans == -1)
        cout<<"Maximum product of triplets not found.";
    else
        cout<<"Maximum product of triplets is: "<<ans;

    return 0;
}