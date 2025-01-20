//Find a seat with Distance between nearest Occupied Seats maximised

/*Given a string (seats) of 1s and 0s, where 1 represents a filled seat and 0 represents an empty seat in a row. Find an empty seat with maximum distance from an occupied seat. Return the maximum distance.

Examples:
Input: Seats = "1000101"
Output: 2
Explanation: Geek can take 3rd place and have a distance of 2 in left and 2 in right.

Input: Seats = "1000"
Output: 3
Explanation: Geek can take the rightmost seat to have a distance of 3.*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string val;
    cout << "Enter the string: ";
    cin >> val;

    int n = val.length();
    vector<int> prefix(n, n), suffix(n, n);
    int count = n; // Initialize to a large value for distance calculations.

    // Calculate prefix distances
    for (int i = 0; i < n; ++i) {
        if (val[i] == '1') {
            count = 0; // Reset count for occupied seat
        } else {
            count++;
        }
        prefix[i] = count;
    }

    // Calculate suffix distances
    count = n; // Reset count for suffix calculation
    for (int i = n - 1; i >= 0; --i) {
        if (val[i] == '1') {
            count = 0; // Reset count for occupied seat
        } else {
            count++;
        }
        suffix[i] = count;
    }

    // Calculate the maximum distance
    int maxDistance = 0;
    for (int i = 0; i < n; ++i) {
        if (val[i] == '0') { // Only consider empty seats
            maxDistance = max(maxDistance, min(prefix[i], suffix[i]));
        }
    }

    cout << "Maximum distance: " << maxDistance << endl;
    return 0;
}
