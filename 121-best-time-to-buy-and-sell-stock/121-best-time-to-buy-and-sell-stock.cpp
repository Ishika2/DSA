class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vector<int> SuffixMaxArr(n,INT_MIN);
        int SuffixMaxArr[n];// = {INT_MIN};
        //fill(SuffixMaxArr,SuffixMaxArr+n,INT_MIN);
        SuffixMaxArr[n-1] = prices[n-1];
        for(int i = n-2; i >= 0; i--)
        {
            SuffixMaxArr[i] = max(SuffixMaxArr[i+1],prices[i]);
        }
        int profit = 0;
        for(int i = 0; i < n; i++)
        {
            if(SuffixMaxArr[i] > prices[i])
                profit = max(SuffixMaxArr[i] - prices[i],profit);
        }
        return profit;
    }
};