class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> v(m,string(n,'#'));
        for (int j=0;j<n;j++){
            v[0][j]='.';
        }
        for(int i=0;i<m;i++){
            v[i][n-1]='.';
        }
        return v;
    }
};