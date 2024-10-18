#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    
    
    std::sort(nums.begin(), nums.end());
    
    int n = nums.size();
    
     
    for (int i = 0; i < n - 2; ++i) {
       
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        int left = i + 1;
        int right = n - 1;
        
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
               
                result.push_back({nums[i], nums[left], nums[right]});
                
              
                while (left < right && nums[left] == nums[left + 1]) ++left;
                 
                while (left < right && nums[right] == nums[right - 1]) --right;
                
                
                ++left;
                --right;
            }
            else if (sum < 0) {
                 
                ++left;
            }
            else {
                 
                --right;
            }
        }
    }
    
    return result;
}

int main() {
    std::vector<int> nums;
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        int element;
        std::cin >> element;
        nums.push_back(element);
    }
    
    std::vector<std::vector<int>> result = threeSum(nums);
    
    std::cout << "The triplets that sum up to zero are: " << std::endl;
    for (const auto& triplet : result) {
        std::cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << std::endl;
    }
    
    return 0;
}
