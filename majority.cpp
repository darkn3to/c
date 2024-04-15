#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int findMajority(vector<int>& nums) {
    unordered_map<int, int> counts;
    int majority = nums.size() / 2;
    for (int num : nums) {
        if (++counts[num] > majority) {
            return num;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int majority = findMajority(nums);
    if (majority != -1) {
        cout << "The majority element is " << majority << endl;
    } else {
        cout << "No majority element exists" << endl;
    }
    return 0;
}