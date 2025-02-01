//Stock Buy and Sell – Multiple Transaction Allowed

/*Given an array prices[] of size n denoting the cost of stock on each day, the task is to find the maximum total profit if we can buy and sell the stocks any number of times.

Note: We can only sell a stock which we have bought earlier and we cannot hold multiple stocks on any day.

Examples:
Input: prices[] = {100, 180, 260, 310, 40, 535, 695}
Output: 865
Explanation: Buy the stock on day 0 and sell it on day 3 => 310 – 100 = 210
                       Buy the stock on day 4 and sell it on day 6 => 695 – 40 = 655
                       Maximum Profit  = 210 + 655 = 865

Input: prices[] = {4, 2, 2, 2, 4}
Output: 2
Explanation: Buy the stock on day 3 and sell it on day 4 => 4 – 2 = 2
                       Maximum Profit  = 2*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int StockBuyNSell(vector<int> & num)
{
    int currMaxProfit = INT_MIN, MaxProfit = 0, bestBuy = num[0];
    for(int i=1;i<num.size();i++)
    {
        if(num[i]>bestBuy)
        {
            currMaxProfit = max(currMaxProfit, num[i]-bestBuy);
            if(num[i] > num[i+1] || i == num.size()-1)
            {
                MaxProfit += currMaxProfit;
                currMaxProfit = INT_MIN;
                bestBuy = num[i+1];
                continue;
            }
        }
        bestBuy = min(bestBuy, num[i]);
    }
    return MaxProfit;
}
int main()
{
    int n;
    cout<<"Enter the count of elements: ";
    cin>>n;
    vector<int> num(n,0);
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    cout<<"Maximum Profit: "<<StockBuyNSell(num);
}