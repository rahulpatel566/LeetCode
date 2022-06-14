class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        //lis using binary search
        // vector<int> v;
        // for(auto &x:nums)
        // {
        //     auto it=lower_bound(v.begin(),v.end(),x);
        //     if(it!=v.end())
        //        *it=x;
        //     else
        //         v.push_back(x);
        // }
        // return (int)v.size();
        
        //using tabulation dp n^2
        int ans=1,n=nums.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
           ans=max(ans,dp[i]);
        }
        return ans;
    }
};