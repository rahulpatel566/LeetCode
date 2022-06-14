class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for(auto &x:nums)
        {
            auto it=lower_bound(v.begin(),v.end(),x);
            if(it!=v.end())
               *it=x;
            else
                v.push_back(x);
        }
        return (int)v.size();
    }
};