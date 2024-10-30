#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    int jumps = 0, currentEnd = 0, farthest = 0;

    for (int i = 0; i < n - 1; ++i) {
        farthest = max(farthest, i + nums[i]);
        
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
        }
        
        if (currentEnd >= n - 1) {
            break;
        }
    }

    return jumps;
}

int main() {
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {2, 3, 0, 1, 4};

    cout << "Minimum jumps for nums1: " << jump(nums1) << endl;  // Output: 2
    cout << "Minimum jumps for nums2: " << jump(nums2) << endl;  // Output: 2

    return 0;
}
