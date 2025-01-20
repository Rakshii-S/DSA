//Maximum Consecutive Ones After Flipping Zeroes

/*Given a binary array arr[] and an integer k, find the maximum length of a subarray containing all ones after flipping at most k zeroes to 1’s.

Examples: 

Input: arr[] = {1, 0, 1}, k = 1
Output: 3
Explanation: By flipping the zero at index 1, all the array elements become one.


Input: arr[] = {1, 0, 0, 1, 0, 1, 0, 1}, k = 2
Output: 5 
Explanation: By flipping the zeroes at indices 4 and 6, we get the longest subarray from index 3 to 7 containing all 1’s.*/

// C++ program to find the maximum subarray having all
// ones, using sliding window technique

#include <iostream>
#include <vector>
using namespace std;

int maxOnes(vector<int> &arr, int k) {
    int res=0, start = 0, end= 0, cnt=0;
    while(end<arr.size())
    {
        if(arr[end] == 0)
            cnt++;
        
        while(cnt>k)
        {
            if(arr[start] == 0)
                cnt--;
            start++;
        }

        res = max(res, end-start+1);
        end++;
    }
    return res;
}

int main() {
    int n, k;
    cout<<"Enter range: ";
    cin>>n;
    vector<int> arr(n,0);
    cout<<"Enter elements (0s and 1s): ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the k value: ";
    cin>>k;
    cout<<"The maximum length of a subarray containing all ones after flipping at most k zeroes to 1's is: "<<maxOnes(arr,k);
}