// //resursion solution - using more space - giving TLE

// class Solution {
// public:
//     int f(int idx, int prev, int n, vector<int> arr)
//     {
//         if(idx == n)   //base case - reached index out of bound
//             return 0;  //length is 0 now - after the (n-1)th index
        
//         int len = f(idx+1,prev,n,arr); //not take - not increase in length
        
//         if(prev == -1 || arr[idx] > arr[prev])            
//             len = max(len,1+f(idx+1,idx,n,arr));  //take
//             //idx = is your prev idx now
//         return len;
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int ans = f(0,-1,nums.size(),nums);   //give the length of LIS with prev element
//         //that is, length of LIS starting from idx, whose prev element is prev
//         //eg., f(3,0) --> length of LIS starting from 3rd index, whose prev index is 0
//         return ans;
//     }
// };

// //TC = 2^n
// //SC = O(N)  //auxilary stack space


// //dp solution - giving tle, 22/54 test cases passed

// class Solution {
// public:
//     int f(int idx, int prev, int n, vector<int> arr, vector<vector<int>> &dp)
//     {
//         if(idx == n)   //base case - reached index out of bound
//             return 0;  //length is 0 now - after the (n-1)th index
//         if(dp[idx][prev+1] != -1)   return dp[idx][prev+1];
        
//         int len = 0 + f(idx+1,prev,n,arr,dp); //not take - not increase in length
        
//         if(prev == -1 || arr[idx] > arr[prev])            
//             len = max(len,1+f(idx+1,idx,n,arr,dp));  //take - increase in length
//             //idx = is your prev idx now
//         return dp[idx][prev+1] = len;
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n,vector<int>(n+1,-1));
//         int ans = f(0,-1,n,nums,dp);   //give the length of LIS with prev element
//         //that is, length of LIS starting from idx, whose prev element is prev
//         //eg., f(3,0) --> length of LIS starting from 3rd index, whose prev index is 0
//         //1 1 1 2 2 3 4 4  --> dp array - containing the size of increasing subsequence with every element at              the end of that subsequence
           //eg.,[10] -> size is 1(prev is > 10); [9] -> size is 1(prev is > 9); [2] -> size is 1(prev is > 2); [2,5] -> size is 2(prev is < 5); [2,3] -> size is 2(prev is < 3); prev
        
//         return ans;
//     }
// };

//TC = O(N*N)
//SC = O(N*N) + O(N)

//other solution - binary search - to find the ceil value index, rest is simple comparison

class Solution {
public:
    int CeilValueIndex(vector<int>& v, int l, int r, int key)
    {
        while(r-l > 1)
        {
            int m = l + (r-l)/2;
            if(v[m] >= key)  //ceil value - greater than or equal to
                r = m;
            else
                l = m;
        }
        return r;
    }
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) //no need here, on LC, due to given constraints
            return 0;
        vector<int> tail(nums.size(),0);  //auxillary array
        int length = 1;   //always points empty slot in tail
        tail[0] = nums[0];  //assumed first value to be smallest
        for(int i = 1; i < nums.size(); i++)   //for(size_t i = 1; i < v.size(); i++)  
        {
            if(nums[i] < tail[0])
                tail[0] = nums[i];  //new smallest value
            
            else if(nums[i] > tail[length-1])
                tail[length++] = nums[i];   //v[i] extends largest subseq
            // v[i] will become end candidate of an existing
            // subsequence or Throw away larger elements in all
            // LIS, to make room for upcoming greater elements
            // than v[i] (and also, v[i] would have already
            // appeared in one of LIS, identify the location
            // and replace it)
            else
                tail[CeilValueIndex(tail,-1,length-1,nums[i])] = nums[i];
        }
        return length;
    }
};

// size_t type is a base unsigned integer type of C/C++ language. It is the type of the result returned by sizeof operator. The type's size is chosen so that it can store the maximum size of a theoretically possible array of any type. On a 32-bit system size_t will take 32 bits, on a 64-bit one 64 bits.


// TC = O(N log N)
// SC = O(N)
