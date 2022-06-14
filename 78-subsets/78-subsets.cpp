class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        int opt=1<<n;
        for(int i=0;i<opt;i++)
        {
            vector<int> temp;
            int num=i,pos=0;
            while(num)
            {
                int rsb=num&1;
                if(rsb)
                    temp.push_back(nums[pos]);
                pos++;
                num=num>>1;
            }
            res.push_back(temp);
        }
        return res;
    }
};