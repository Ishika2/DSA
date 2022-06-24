class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> powers(n,1);
        int mod = 1e9 + 7;
        for(int i = 1; i < n; ++i)
        {
            powers[i] = powers[i-1] * 2 % mod;
        }
        int cnt = 0;
        int low = 0;
        int high = nums.size()-1;
        while(low <= high)
        {
            if(nums[low] + nums[high] <= target)
            {                
                cnt = (cnt + powers[high - low]) % mod;      
                low++;
            }
            else  high--;
        }
        return cnt;
    }
};