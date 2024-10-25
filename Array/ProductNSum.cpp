#include <iostream>
#include <climits>
using namespace std;

int ProductNSum(int n, int arr[], int *sum, int *product)
{
    *sum = 0, *product=1;
    for(int i=0;i<n;i++)
    {
        *sum += arr[i];
        *product *= arr[i];
    }
    return 0;
}
int main()
{
    int n, arr[30], sum ,product;
    cout<<"Enter the size: ";
    cin>>n;
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    } 
    ProductNSum(n,arr, &sum, &product);
    cout<<"Sum of all elements is: "<<sum<<endl;
    cout<<"Product of all elements is: "<<product;
}