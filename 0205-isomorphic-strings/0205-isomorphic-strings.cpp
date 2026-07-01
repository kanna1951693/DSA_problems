class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> map1(256);
        vector<char> map2(256);

        for(int i=0;i<s.size();i++){
            if(map1[s[i]] != map2[t[i]]){
                return false;
            }

            map1[s[i]] = i+1;
            map2[t[i]] = i+1;
        }

        return true;
    }
};