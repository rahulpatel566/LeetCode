class Solution {
public:
    int solve(vector<int>&nums,int k)
    {
        int ans=0,start=0,cnt=0;
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++)
        {
            um[nums[i]]++;
            if(um[nums[i]]==1)
                cnt++;
            while(cnt>k)
            {
                um[nums[start]]--;
                if(um[nums[start]]==0)
                    cnt--;
                start++;
            }
            ans+=(i-start+1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};


 