//Missing ranges of numbers
/*You have an inclusive interval [lower, upper] and a sorted array of unique integers arr[], all of which lie within this interval. A number x is considered missing if x is in the range [lower, upper] but not present in arr. Your task is to return the smallest set of sorted ranges that includes all missing numbers, ensuring no element from arr is within any range, and every missing number is covered exactly once.

Examples

Input: arr[] = [14, 15, 20, 30, 31, 45], lower = 10, upper = 50
Output: [[10, 13], [16, 19], [21, 29], [32, 44], [46, 50]]
Explanation: These ranges represent all missing numbers between 10 and 50 not present in the array

Input: arr[] = [-48, -10, -6, -4, 0, 4, 17], lower = -54, upper = 17
Output: [[-54, -49], [-47, -11], [-9, -7], [-5, -5], [-3, -1], [1, 3], [5,16]]
Explanation: These ranges represent all missing numbers between -54 and 17 not present in the array.*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> MissingRange(vector<int> &num, int low, int upp)
{
    int n =num.size();
    vector<vector<int>> ans;
    if(low<num[0])
        ans.push_back({low, num[0]-1});
    
    for(int i=1;i<n-1;i++)
    {
        if(num[i+1]-num[i]>1)
            ans.push_back({num[i]+1, num[i+1]-1});
    }

    if(n>0 && upp > num[n-1])
        ans.push_back({num[n-1]+1,upp});
    
    return ans;
}
int main()
{
    int n,low,upp;
    cout<<"Enter the range: ";
    cin>>n;
    vector<int> num(n,0);
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    cout<<"Enter the lower limit: ";
    cin>>low;
    cout<<"Enter the upper limit: ";
    cin>>upp;
    vector<vector<int>> ans = MissingRange(num, low, upp); 
    for(const vector<int> &v : ans)
        cout<<v[0]<<" "<<v[1]<<endl;
    return 0;
}