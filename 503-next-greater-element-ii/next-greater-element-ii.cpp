class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>stk;
        int n = nums.size();
        for(int i=n-1; i>=0; i--) stk.push(nums[i]);

        for(int i=n-1; i>=0; i--){
            while(!stk.empty() && stk.top() <= nums[i]) stk.pop();
            int temp = nums[i];
            if(!stk.empty()) nums[i] = stk.top();
            else nums[i] = -1;
            stk.push(temp);
        }
        return nums;
    }
};