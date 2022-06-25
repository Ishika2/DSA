class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;  //maxHeap
        
        vector<int> ans(k,0); //size = k, initialised with 0
        
        for(int i = 0; i < nums.size(); i++)
        {
            pq.push({nums[i],i});   //added elements in maxHeap
        }
        
        for(int i = 0; i < k; i++)
        {
            ans[i] = pq.top().second;
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        for(int i = 0; i < k; i++)
        {
            ans[i] = nums[ans[i]];
        }
        
        return ans;
    }
};