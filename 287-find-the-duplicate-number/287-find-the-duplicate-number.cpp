class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int n = nums[0];
        int n = nums.size();
        // int i = 0;
        // int j = n-1;
        int elem;
        // for(int i = 1; i < nums.size(); i++)
        // {
        //     if(nums[i] != n)
        //         n = nums[i];
        //     if(nums[i] == n)
        //         break;
        // }
        // sort(nums.begin(), nums.end());
        // while(i <= j)
        // {
        //     if(nums[i] == nums[j])
        //         elem = nums[i];
        //     else if(nums[i] < nums[j])
        //         j--;
        //     else
        //         i++;
        // }
        // return elem;
        vector<int> cnt(n,0);
        for(int i = 0; i < n; i++)
        {
            cnt[nums[i]]++;
        }
        for(int i = 0; i < cnt.size(); i++)
        {
            if(cnt[i] > 1)
            {
                elem = i;
                break;
            }
                // elem = i;
        }
        return elem;
    }
};