class Solution {
public:
    void solve(vector<int>&nums,int i,int sum,vector<int>&temp,vector<vector<int>>&res,int t)
    {
        if(i==nums.size())
        {
            if(sum==t)
                res.push_back(temp);
            return;
        }
        if(nums[i]+sum<=t)
        {
            temp.push_back(nums[i]);
             solve(nums,i,sum+nums[i],temp,res,t);
            temp.pop_back();
        }
        solve(nums,i+1,sum,temp,res,t);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(candidates,0,0,temp,res,target);
        return res;
    }
};