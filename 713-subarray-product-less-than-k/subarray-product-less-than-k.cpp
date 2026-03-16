typedef long long ll;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        ll prod = 1;

        for(int i=0, j=0; j<n; ++j){
            prod *= nums[j];

            while(prod >= k && i < j)
                prod /= nums[i++];

            if(prod < k)
                count += (j-i+1);
        }

        return count;
    }
};