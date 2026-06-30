class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        vector<int> res;
        for(auto it:mpp){
            if(it.second>n/3) res.push_back(it.first);
        }
        return res;
    }
};