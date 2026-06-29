class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int, int>> num;
        for (int i = 0; i < n; i++) {
            num.push_back({nums[i], i});
        }
        sort(num.begin(),num.end());
        int i=0;
        int j=n-1;
        vector<int> se(2);
        while(i<j){
            if(num[i].first+num[j].first==target){
                se[1]=num[j].second;
                se[0]=num[i].second;
                break;
            }
            else if(num[i].first+num[j].first>target){j--;}
            else if(num[i].first+num[j].first<target){i++;}
        }
        return se;
    }
};
