class Solution {
public:
    //one,zero
    int dp[601][101][101];
    int solve(vector<pair<int,int>>&nums,int i,int zero,int one)
    {
        if(i==nums.size())
            return 0;
        if(dp[i][zero][one]!=-1)
            return dp[i][zero][one];
        int op1=0,op2=0;
        if(nums[i].first<=one && nums[i].second<=zero)
         op1=1+solve(nums,i+1,zero-nums[i].second,one-nums[i].first);
        op2=solve(nums,i+1,zero,one);
        return dp[i][zero][one]=max(op1,op2);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> temp;
        for(auto &str:strs)
        {
            int one=0;
            for(auto &c:str)
            {
                if(c=='1')
                    one++;
            }
            temp.push_back({one,str.size()-one});
        }
        memset(dp,-1,sizeof(dp));
        return solve(temp,0,m,n);
    }
};