class Solution {
public:
    int dp[13][10001];
    int solve(vector<int>&coins,int i,int t)
    {
        if(t==0)
            return 0;
        if(i==coins.size())
            return 100000;
        if(dp[i][t]!=-1)
            return dp[i][t];
        int op1=INT_MAX,op2=INT_MAX;
        if(coins[i]<=t)
            op1=1+solve(coins,i,t-coins[i]);
        op2=solve(coins,i+1,t);
        return dp[i][t]= min(op1,op2);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans= solve(coins,0,amount);
        if(ans==100000)
            return -1;
        return ans;
    }
};