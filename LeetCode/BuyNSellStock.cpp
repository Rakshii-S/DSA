#include <iostream>
#include <vector>
using namespace std;

int MaxProfit(int d, vector<int> &p)
{
    int maxProfit = 0, bestBuy = p[0];
    for(int i=1;i<d;i++)
    {
        if(bestBuy<p[i])
        {
            maxProfit = max(maxProfit, p[i]-bestBuy);
        }
        bestBuy = min(bestBuy, p[i]);
    }
    return maxProfit;
}
int main()
{
    int days;
    cout<<"Enter the number of days: ";
    cin>>days;
    vector<int> prices(days,0);
    cout<<"Enter the price for each day: ";
    for(int i=0;i<days;i++)
    {
        cin>>prices[i];
    }
    int ans =  MaxProfit(days, prices);
    if(ans == 0)
    {
        cout<<"There is not profit.";
    }else{
        cout<<"Maximum Profit: "<<ans;
    }
}
