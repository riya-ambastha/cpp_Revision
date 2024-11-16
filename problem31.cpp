#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findSubarrayPowers(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> results;

    for (int i = 0; i <= n - k; ++i) {
        vector<int> subarray(nums.begin() + i, nums.begin() + i + k);

        // Check if the subarray is consecutive and sorted
        vector<int> sortedSubarray = subarray;
        sort(sortedSubarray.begin(), sortedSubarray.end());

        bool isConsecutive = true;
        for (int j = 1; j < k; ++j) {
            if (sortedSubarray[j] != sortedSubarray[j - 1] + 1) {
                isConsecutive = false;
                break;
            }
        }

        if (isConsecutive) {
            results.push_back(*max_element(subarray.begin(), subarray.end()));
        } else {
            results.push_back(-1);
        }
    }

    return results;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 3, 2, 5};
    int k1 = 3;
    vector<int> result1 = findSubarrayPowers(nums1, k1);

    cout << "Example 1 Output: ";
    for (int r : result1) {
        cout << r << " ";
    }
    cout << endl;

    vector<int> nums2 = {2, 2, 2, 2, 2};
    int k2 = 4;
    vector<int> result2 = findSubarrayPowers(nums2, k2);

    cout << "Example 2 Output: ";
    for (int r : result2) {
        cout << r << " ";
    }
    cout << endl;

    vector<int> nums3 = {3, 2, 3, 2, 3, 2};
    int k3 = 2;
    vector<int> result3 = findSubarrayPowers(nums3, k3);

    cout << "Example 3 Output: ";
    for (int r : result3) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
