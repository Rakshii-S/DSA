//Meeting Scheduler for Two Persons

/*You have given the availability time slots 'slots1' and 'slots2' of two people and a meeting duration 'd', for any i, slots[i] = {starti , endi}. return the earliest time slot that works for both of them and is of 'd' duration.

If there is no common time slot that satisfies the requirements, return an empty array.

It is guaranteed that no two availability slots of the same person intersect with each other. That is, for any two time slots [start1, end1] and [start2, end2] of the same person, either start1 > end2 or start2 > end1.

Examples:

Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], d = 8
Output: [60,68]



Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], d = 12
Output: [] */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void inputValues(vector<vector<int>> &slot, int n)
{
    cout<<"Enter time slots: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>slot[i][j];
        }
    }
}

vector<int> ManageSchedule(vector<vector<int>> &slot1, vector<vector<int>> &slot2, int duration)
{
    sort(slot1.begin(), slot1.end());
    sort(slot2.begin(), slot2.end());

    int pointer1 = 0, pointer2 = 0;
    while(pointer1<slot1.size() && pointer2<slot2.size())
    {
        int intersectLeft = max(slot1[pointer1][0],slot2[pointer2][0]);
        int intersectRight = min(slot1[pointer1][1], slot2[pointer2][1]);

        if(intersectRight-intersectLeft >= duration)
        {
            return{intersectLeft,intersectLeft+duration};
        }

        if(slot1[pointer1][1]<slot2[pointer2][1])
            pointer1++;
        else 
            pointer2++;
    }
    return {};
}
int main()
{
    int n1, n2, dur;
    cout<<"Enter available timeslots of person one: ";
    cin>>n1;
    cout<<"Enter available timeslots of person two: ";
    cin>>n2;
    cout<<"Enter the time duration of the meeting: ";
    cin>>dur;

    vector<vector<int>>slot1(n1,vector<int>(2,0));
    vector<vector<int>>slot2(n2,vector<int>(2,0));

    inputValues(slot1, n1);
    inputValues(slot2, n2);

    vector<int>availableTimeSlot = ManageSchedule(slot1,slot2,dur);
    cout<<"Available time slot for meeting is: "<<availableTimeSlot[0]<<" "<<availableTimeSlot[1];
}