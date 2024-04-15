#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void heapSort(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = pq.top();
        pq.pop();
    }
}

int main() {
    vector<int> nums = {4, 3, 2, 10, 12, 1, 5, 6};
    heapSort(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}