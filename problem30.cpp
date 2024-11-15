#include <iostream>
#include <vector>
#include <algorithm>

int findShortestSubarrayToRemove(std::vector<int>& arr) {
    int n = arr.size();
    int left = 0, right = n - 1;
 
    while (left < n - 1 && arr[left] <= arr[left + 1]) {
        left++;
    }
 
    if (left == n - 1) {
        return 0;
    }
 
    while (right > 0 && arr[right - 1] <= arr[right]) {
        right--;
    }

   
    int result = std::min(n - left - 1, right);
 
    int i = 0, j = right;
    while (i <= left && j < n) {
        if (arr[i] <= arr[j]) {
            result = std::min(result, j - i - 1);
            i++;
        } else {
            j++;
        }
    }

    return result;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 10, 4, 2, 3, 5};
    std::vector<int> arr2 = {5, 4, 3, 2, 1};
    std::vector<int> arr3 = {1, 2, 3};

    std::cout << "Output for arr1: " << findShortestSubarrayToRemove(arr1) << std::endl;
    std::cout << "Output for arr2: " << findShortestSubarrayToRemove(arr2) << std::endl;
    std::cout << "Output for arr3: " << findShortestSubarrayToRemove(arr3) << std::endl;

    return 0;
}
