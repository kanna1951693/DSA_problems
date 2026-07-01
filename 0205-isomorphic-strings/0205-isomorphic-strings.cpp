class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mpp;
        unordered_map<char,char> pmm;
        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i])!=mpp.end()){
                if(mpp[s[i]]!=t[i]) return false;
            }
            mpp[s[i]]=t[i];
        }
        for(int i=0;i<s.size();i++){
            if(pmm.find(t[i])!=pmm.end()){
                if(pmm[t[i]]!=s[i]) return false;
            }
            pmm[t[i]]=s[i];
        }
        return true;
    }
};