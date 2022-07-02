class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //input = 7 9 8 3 4 5 1
        //suffixMaxArray = 9 9 8 5 5 5 1 (max value after ith element)
        //prefixmaxArray = 7 9 9 9 9 9 9 (max value before ith element)
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