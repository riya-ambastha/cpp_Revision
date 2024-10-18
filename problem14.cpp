#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> result;
 
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
 
    for (int i = 0; i < n - 3; ++i) {
   
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        for (int j = i + 1; j < n - 2; ++j) {
           
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            
            int left = j + 1;
            int right = n - 1;
            
          
            while (left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                
                if (sum == target) {
               
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                   
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    
                    
                    ++left;
                    --right;
                } else if (sum < target) {
               
                    ++left;
                } else {
                    
                    --right;
                }
            }
        }
    }
    
    return result;
}

int main() {
    std::vector<int> nums;
    int n, target;
    
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        int element;
        std::cin >> element;
        nums.push_back(element);
    }
    
    std::cout << "Enter the target sum: ";
    std::cin >> target;
    
    std::vector<std::vector<int>> result = fourSum(nums, target);
    
    std::cout << "The quadruplets that sum up to the target are: " << std::endl;
    for (const auto& quadruplet : result) {
        std::cout << "[" << quadruplet[0] << ", " << quadruplet[1] << ", " << quadruplet[2] << ", " << quadruplet[3] << "]" << std::endl;
    }
    
    return 0;
}
