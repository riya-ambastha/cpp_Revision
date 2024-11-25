#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        
        while (left < right) {
            // Calculate the current area
            int h = min(height[left], height[right]);
            int width = right - left;
            maxArea = max(maxArea, h * width);
            
            // Move the pointer with the smaller height
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxArea;
    }
};
