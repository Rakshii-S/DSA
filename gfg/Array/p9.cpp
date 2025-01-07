//Adding one to number represented as array of digits

/*Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by the digits ). The digits are stored such that the most significant digit is the first element of the array.

Examples : 

Input : [1, 2, 4]
Output : [1, 2, 5]
Input : [9, 9, 9]
Output : [1, 0, 0, 0]*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void PlusOne(vector<int> &num)
{
    int idx = num.size()-1;
    int add, carry=1;
    while(idx>=0)
    {
        add = num[idx] + carry;
        if(to_string(add).length() == 2)
        {
            num[idx] = add%10;
            carry = add/10;
            if(idx == 0)
            {
                num.insert(num.begin(), carry);
            }
        }else
        {
            num[idx] = add;
            carry = 0;
        }
        idx--;
    }
}

int main()
{
    int n;
    cout<<"Enter the range: ";
    cin>>n;
    vector<int> num(n,0);
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }

    PlusOne(num);

    cout<<"Value of array after rotating: ";
    for(int i=0;i<num.size();i++)
    {
        cout<<num[i]<<" ";
    }
    return 0;
}