#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int countPair(vector<int>& nums, int target) {
    unordered_map<int, int> numCount;
    int pairCount = 0;
    for (int num : nums) {
        if (numCount.count(num - target)) {
            pairCount += numCount[num - target];
        }
        numCount[num]++;
    }
    return pairCount;
}
int main() {
    int t, n, target;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t--> 0) {
        cout << "Enter the number of elements: ";
        cin >> n;
        vector<int> nums(n);
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++) cin >> nums[i];
        cout << "Enter the target: ";
        cin >> target;
        cout << countPair(nums, target) << endl;
    }
    return 0;
}

