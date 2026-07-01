class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int first=INT_MAX;
        int yes;
        int j=0;
        for(int i=0;i<n;i++){
            if(needle[j]==haystack[i]){
                if(j==0) yes=i;
                if(j==needle.size()-1){
                    first=min(first,yes);
                }
                j++;
            }
            else {
                if (j > 0) {
                i = yes;
                j = 0;  
                }
            }
        }
        if(first==INT_MAX) return -1;
        return first;
    }
};