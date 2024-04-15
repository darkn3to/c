#include <bits/stdc++.h>
using namespace std;

unordered_set<string> searchTriplets(vector<int>& nums) {
    unordered_set<string> triplets;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            int sum = nums[i] + nums[j];
            if (find(nums.begin(), nums.end(), sum) != nums.end()) {
                vector<int> triplet = {nums[i], nums[j], sum};
                sort(triplet.begin(), triplet.end());
                string triplet_str = to_string(triplet[0]) + "," + to_string(triplet[1]) + "," + to_string(triplet[2]);
                triplets.insert(triplet_str);
            }
        }
    }
    return triplets;
}

int main() {
    vector<int> nums = {2,1,1,4,3,6,1};
    unordered_set<string> triplets = searchTriplets(nums);
    for (const auto& triplet : triplets) {
        cout << triplet << endl;
    }
    return 0;
}