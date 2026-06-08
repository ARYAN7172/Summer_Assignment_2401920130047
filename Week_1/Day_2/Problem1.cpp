class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int currentSum = nums[0];
        int maxSum = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            
            // Either start new subarray or continue
            if(currentSum + nums[i] > nums[i])
                currentSum = currentSum + nums[i];
            else
                currentSum = nums[i];
            
            // Update max
            if(currentSum > maxSum)
                maxSum = currentSum;
        }
        
        return maxSum;
    }