class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> temp;
        int m=matrix.size();
        int n=matrix[0].size();
        int top=0;
        int bottom=m-1;
        int left=0;
        int right=n-1;

        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                temp.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                temp.push_back(matrix[i][right]);
            }
            right--;
            //checking the colums are reaming
            if(top <= bottom) {
            for(int i=right;i>=left;i--){
                temp.push_back(matrix[bottom][i]);
            }
            bottom--;
            }
            //checking the rows are remaining
            if(left <= right) {
            for(int i=bottom;i>=top;i--){
                temp.push_back(matrix[i][left]);
            }
            left++;
            }
        }
        

        return temp;
    }
};