class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())return 0;
        int n=nums.size();
        int i=1;
        int idx=1;
        while(i< n){
            if(nums[i]!=nums[i-1]){
                nums[idx]=nums[i];
                idx++;
            }
            i++;
        }
        return idx;
    }
};