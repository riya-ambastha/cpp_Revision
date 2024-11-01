 #include <iostream>
#include <vector>

int firstMissingPositive(std::vector<int>& nums) {
    int n = nums.size();
    
    for (int i = 0; i < n; ++i) {
       
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            std::swap(nums[i], nums[nums[i] - 1]);
        }
    }
   
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    
   
    return n + 1;
}

int main() {
    std::vector<int> nums1 = {1, 2, 0};
    std::vector<int> nums2 = {3, 4, -1, 1};
    std::vector<int> nums3 = {7, 8, 9, 11, 12};

    std::cout << "Missing positive for [1, 2, 0]: " << firstMissingPositive(nums1) << std::endl;
    std::cout << "Missing positive for [3, 4, -1, 1]: " << firstMissingPositive(nums2) << std::endl;
    std::cout << "Missing positive for [7, 8, 9, 11, 12]: " << firstMissingPositive(nums3) << std::endl;

    return 0;
}
