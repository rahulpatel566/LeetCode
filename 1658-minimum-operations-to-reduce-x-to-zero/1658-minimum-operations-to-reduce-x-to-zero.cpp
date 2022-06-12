class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size(),sum=0,ans=INT_MAX;
        for(auto &u:nums)
            sum+=u;
        int remSum=sum-x;
        if(remSum<0)
            return -1;
        if(remSum==0)
            return n;
        int left=0;
        sum=0;
        for(int right=0;right<n;right++)
        {
            sum+=nums[right];
            while(sum>remSum)
            {
               sum-=nums[left];
                left++;
            }
            if(sum==remSum)
            ans=min(ans,left+n-right-1);
        }
        return ans==INT_MAX?-1:ans;
        
       // int n=nums.size(),sum=0,ans=INT_MIN;
       //  for(auto &n:nums)
       //      sum+=n;
       //  if(sum==x)
       //      return n;
       //  int k=sum-x;
       //  sum=0;
       //  unordered_map<int,int> um;
       //  um[0]=-1;
       //  for(int i=0;i<n;i++)
       //  {
       //      sum+=nums[i];
       //      if(um.find(sum-k)!=um.end())
       //       ans=max(ans,i-um[sum-k]);
       //      um[sum]=i;
       //  }
       //  return ans==INT_MIN?-1:n-ans;
        
        
       //  int n=nums.size(),sum=0;
       //  unordered_map<int,int> right;
       //  right[0]=0;
       //  for(int i=n-1;i>=0;i--)
       //  {
       //      sum+=nums[i];
       //      if(sum>x)
       //          break;
       //      right[sum]=n-i;
       //  }
       //  int ans=INT_MAX;
       //  if(right.find(x)!=right.end())
       //      ans=right[x];
       //  sum=0;
       //  for(int left=0;left<n;left++)
       //  {
       //      sum+=nums[left];
       //      if(sum>x)
       //          break;
       //      if(right.find(x-sum)!=right.end())
       //      {
       //          int rightIdx=n-right[x-sum];
       //          if(left<rightIdx)
       //          ans=min(ans,left+1+right[x-sum]);
       //      }
       //  }
       // return ans==INT_MAX?-1:ans;
        
    }
};