class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        
        // 1. Find the breakpoint
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }
        
        // 2. If no breakpoint exists, reverse the whole array and return
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // 3. Find the next greater element and swap
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        
        // 4. Reverse the remaining suffix
        reverse(nums.begin() + ind + 1, nums.end());
    }
};