class Solution {
public:
    //recursion, giving tle at 44 and 45
    // int f(int idx)
    // {
    //     if(idx == 0)    return 1;
    //     if(idx == 1)    return 1;
    //     int left = f(idx - 1);
    //     int right = f(idx - 2);
    //     return left + right;
    // }
    // int climbStairs(int n) {
    //     int ans = f(n);
    //     return ans;
    // }
    
    //dp solution  //memoization
    int f(int idx)
    {
        vector<int> dp(idx+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <=idx; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[idx];
    }
    int climbStairs(int n) {
        int ans = f(n);
        //cout<<ans[0]<<ans[1];
        return ans;
    }
};