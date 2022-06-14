class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int left=1,right=1,ans=INT_MIN,n=nums.size();
        for(int i=0;i<n;i++)
        {
            left*=nums[i];
            right*=nums[n-i-1];
            ans=max({ans,left,right});
            if(nums[i]==0)
                left=1;
            if(nums[n-i-1]==0)
                right=1;
        }
        return ans;
    }
};