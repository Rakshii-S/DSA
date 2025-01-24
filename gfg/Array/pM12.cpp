//Number of subarrays having product less than K

/*Given an array of positive numbers, calculate the number of possible contiguous subarrays having product lesser than a given number K.
Examples : 

Input : arr[] = [1, 2, 3, 4] 
            K = 10
Output : 7
The subarrays are {1}, {2}, {3}, {4}, {1, 2}, {1, 2, 3} and {2, 3}



Input  : arr[] = [1, 9, 2, 8, 6, 4, 3] 
             K = 100
Output : 16



Input  : arr[] = [10, 5, 2, 6]  
             K = 100
Output : 8*/

#include <iostream>
#include <vector>
using namespace std;

int CountOfSubarrays(vector<int> &num, int k)
{
    //sliding window approach
    int start = 0, end = 0, count = 0;
    long long currMultiple = 1; // Use long long to handle larger products

    while (end < num.size()) {
        currMultiple *= num[end]; // Expand the window by including num[end]

        // Shrink the window until the product is less than k
        while (start <= end && currMultiple >= k) {
            currMultiple /= num[start];
            start++;
        }

        // Count all valid subarrays ending at 'end'
        count += (end - start + 1);
        end++;
    }

    return count;
}
int main()
{
    int n,k;
    cout<<"Enter the range: ";
    cin>>n;
    vector<int> num(n,0);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    cout<<"Enter the k value: ";
    cin>>k;
    cout<<"Number of subarrays having product less than K: "<<CountOfSubarrays(num,k);
    return 0;
}