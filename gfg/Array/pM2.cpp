//Minimum number of increment-other operations to make all array elements equal.

/*We are given an array consisting of n elements. At each operation you can select any one element and increase rest of n-1 elements by 1. You have to make all elements equal performing such operation as many times you wish. Find the minimum number of operations needed for this.

Examples: 

Input : arr[] = {1, 2, 3}
Output : Minimum Operation = 3
Explanation : 
operation | increased elements | after increment
    1     |    1, 2            | 2, 3, 3
    2     |    1, 2            | 3, 4, 3
    3     |    1, 3            | 4, 4, 4

Input : arr[] = {4, 3, 4}
Output : Minimum Operation = 2
Explanation : 
operation | increased elements | after increment
     1    |    1, 2           | 5, 4, 4
     2    |    2, 3           | 5, 5, 5 */

/*Better Approach : If we took a closer look at each operation as well problem statement we will 
find that increasing all n-1 element except the largest one is similar to decreasing the largest 
element only. So, the smallest elements need not to decrease any more and rest of elements will 
got decremented upto smallest one. In this way the total number of operation required for making 
all elements equal will be arraySum – n * (smallestElement). Time complexity will be same as that
of finding smallest elements and array sum i.e. O(n).*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int incrementUntillEqual(vector<int> &num)
{
    int sum=0, smallestEle = INT_MAX, n = num.size(), count;
    for(int i=0;i<n;i++)
    {
        sum+= num[i];
        smallestEle = min(smallestEle, num[i]);
    }
    count = sum - (n*smallestEle);
    if(count == 0) return -1;
    return count;
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
    int ans = incrementUntillEqual(num);
    cout<<"Minimum operations: "<<ans;
}