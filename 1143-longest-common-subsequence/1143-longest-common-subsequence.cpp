class Solution {
public:
    int dp[1001][1001];
    int solve(string &s1,int i,string &s2,int j)
    {
        if(i==s1.size() || j==s2.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j]= 1+solve(s1,i+1,s2,j+1);
        return dp[i][j] =max(solve(s1,i+1,s2,j),solve(s1,i,s2,j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
//         int n=text1.size(),m=text2.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
//         for(int i=0;i<=n;i++)
//         {
//             for(int j=0;j<=m;j++)
//             {
//                 //base case
//                 if(i==0 || j==0)
//                 {
//                     dp[i][j]=0;
//                     continue;
//                 }
//                 if(text1[i-1]==text2[j-1])
//                     dp[i][j]=dp[i-1][j-1]+1;
//                 else
//                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                
//             }
//         }
//         return dp[n][m];
        
        memset(dp,-1,sizeof(dp));
        return solve(text1,0,text2,0);
    }
};