//Finding sum of digits of a number until sum becomes single digit
/*Given an integer n, we need to repeatedly find the sum of its digits until the result becomes a single-digit number.

Examples:

Input: n = 1234 
Output: 1 
Explanation:
Step 1: 1 + 2 + 3 + 4 = 10 
Step 2: 1 + 0 = 1


Input: n = 5674
Output: 4
Explanation: 
Step 1: 5 + 6 + 7 + 4 = 22 
Step 2: 2 + 2 = 4*/

#include <iostream>
#include <vector>

using namespace std;

int SingleDigit(int num)
{
    int sum = 0;

    while(num>0)
    {
        sum+= num%10;
        num /= 10;
    }

    if(sum == 0)
        return 0;
    else if(sum == 9)
        return 9;
    
    return (sum%9);
}

int main()
{
     int num;
    cout<<"Enter the value: ";
    cin>>num;

    int ans = SingleDigit(num);
    cout<<"The sumof digits of a number until sum becomes single digit is: "<<ans;
    return 0;
}