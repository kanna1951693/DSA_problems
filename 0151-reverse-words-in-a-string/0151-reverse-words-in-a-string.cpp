class Solution {
public:
    string reverseWords(string s) {
        vector<vector<char>> sr;
        queue<char> q;
        int i=0;
        int n=s.size();
        while(i<n){
            if(s[i]==' '){
                if(!q.empty()){
                    vector<char> word;
                    while(!q.empty()){
                    int temp=q.front();
                    q.pop();
                    word.push_back(temp);
                    }
                    sr.push_back(word);
                }
            } 
            else q.push(s[i]);
            i++;
        }
        if (!q.empty()) {
        vector<char> word;
                while(!q.empty()){
                    int temp=q.front();
                    q.pop();
                    word.push_back(temp);
                }
        sr.push_back(word);
        }
        if (sr.empty()) return "";
        string res;
         n = sr.size();
        for(int i=n-1;i>0;i--){
            res = res + string(sr[i].begin(), sr[i].end()) + " ";
        }
        res += string(sr[0].begin(), sr[0].end());
        return res;
    }
};