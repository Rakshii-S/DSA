//Sort an array after applying the given equation

/*We have an integer array that is sorted in ascending order. We also have 3 integers A, B and C. We need to apply A*x*x + B*x + C for each element x in the array and sort the modified array. 
Example: 

Input : arr[] = {-1, 0, 1, 2, 3, 4} 
       A = -1, B = 2, C = -1
Output : {-9, -4, -4, -1, -1, 0}  
Expalnation:
Input array is {-1, 0, 1, 2, 3, 4}. After
applying the equation A*x*x + B*x + C on
every element x we get, {-4,-1, 0, -1, -4, -9}
After sorting, we get {-9, -4, -4, -1, -1, 0}*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void ApplyEquation(vector<int> &num, int A, int B, int C)
{
    int n = num.size();
    vector<int> ans(n,0);
    for(int i=0;i<n;i++)
    {
       num[i] = A*(num[i]*num[i]) + B*(num[i]) + C;
    }

    int maximum = INT_MIN, index;
    for(int i=0;i<n;i++)
    {
        if(maximum<num[i])
        {
            maximum = num[i];
            index = i;
        }
    }

    int i = 0, j=n-1, k=0;
    while(i<index && j>index)
    {
        if(num[i]<num[j])
            ans[k++] = num[i++];
        else
            ans[k++] = num[j--];
    }
    while(i<index)
        ans[k++] = num[i++];
    while(j>index)
        ans[k++] = num[j--];
    
    ans[n-1] = maximum;

    for(int i=0;i<n;i++)
    {
        num[i] = ans[i];
    }
}
int main()
{
    int n, A, B, C;
    cout<<"Enter the count of elements: ";
    cin>>n;
    vector<int> num(n,0);
    cout<<"Enter "<<n<<" values: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    cout<<"Enter A, B and C value for expression -> A(x^2)+B(x)+c: ";
    cin>>A>>B>>C;
    ApplyEquation(num,A,B,C);
    for(int i=0;i<n;i++)
    {
        cout<<num[i]<<" ";
    }
    return 0;
}