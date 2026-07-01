class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char,char> mpp;
        unordered_map<char,char> mp2;
        if(s.size()!=t.size()) return false;

        for(int i = 0; i < s.size(); i++) {
            if(mpp.count(s[i])) {
                if(mpp[s[i]] != t[i])
                    return false;
            }
            else {
                mpp[s[i]] = t[i];
            }
            if(mp2.count(t[i])) {
                if(mp2[t[i]] != s[i])
                    return false;
            }
            else {
                mp2[t[i]] = s[i];
            }
        }

        return true;
    }
};