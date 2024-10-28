#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    
    for (int i = 0; i < nums.size(); i++) {
       
        if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
            continue;
        }
        
     
        used[i] = true;
        current.push_back(nums[i]);
        
       
        backtrack(nums, used, current, result);
       
        used[i] = false;
        current.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end()); 
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);
    
    backtrack(nums, used, current, result);
    return result;
}

int main() {
    vector<int> nums1 = {1, 1, 2};
    vector<vector<int>> result1 = permuteUnique(nums1);
    
    cout << "Example 1 Output:\n";
    for (const auto& perm : result1) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    vector<int> nums2 = {1, 2, 3};
    vector<vector<int>> result2 = permuteUnique(nums2);
    
    cout << "\nExample 2 Output:\n";
    for (const auto& perm : result2) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
