class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs[0].size();
        vector<char> res(n);
        if(strs.empty()) return "";
        for(int i=0;i<n;i++){
            res[i]=strs[0][i];
        }
        int m=strs.size();
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(strs[i][j]!=res[j]){n=j; break;}
            }
        }
        string s;
        for(int i=0;i<n;i++){
            s+=res[i];
        }
        return s;
    }
};