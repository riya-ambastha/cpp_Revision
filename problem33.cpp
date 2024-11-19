#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int maximumSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    if (k > n) return 0;

    unordered_set<int> uniqueElements;
    int maxSum = 0, currentSum = 0;

    int left = 0;
    for (int right = 0; right < n; ++right) {
        // Add the current element to the sum
        currentSum += nums[right];

        // Add the current element to the set
        while (uniqueElements.find(nums[right]) != uniqueElements.end()) {
            // Remove elements from the left to maintain distinctness
            uniqueElements.erase(nums[left]);
            currentSum -= nums[left];
            left++;
        }
        uniqueElements.insert(nums[right]);

        // Check if the current window size is equal to k
        if (right - left + 1 == k) {
            maxSum = max(maxSum, currentSum);

            // Slide the window forward
            uniqueElements.erase(nums[left]);
            currentSum -= nums[left];
            left++;
        }
    }

    return maxSum;
}

int main() {
    vector<int> nums1 = {1, 5, 4, 2, 9, 9, 9};
    int k1 = 3;
    cout << "Example 1 Output: " << maximumSubarraySum(nums1, k1) << endl;

    vector<int> nums2 = {4, 4, 4};
    int k2 = 3;
    cout << "Example 2 Output: " << maximumSubarraySum(nums2, k2) << endl;

    return 0;
}
