// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        //create unordered map to store the distinct elements
        unordered_map<int,int> vis;
        for(int i = 0; i < n; i++)
        {
            vis[arr[i]]++;
        }
        int k = vis.size();
        vis.clear();
        int right = 0; //, left = 0;
        int window = 0; //no. of distinct elements, size <= k
        int ans = 0;
        for(int left = 0; left < n; left++)
        {
            while(right < n && window < k)
            {
                //increase visited array
                ++vis[arr[right]];
                if(vis[arr[right]] == 1)  //visiting first time
                    window++;
                right++;
            }
            if(window == k)
                ans += (n - right + 1);
            --vis[arr[left]];
            if(vis[arr[left]] == 0)
                window--;
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends