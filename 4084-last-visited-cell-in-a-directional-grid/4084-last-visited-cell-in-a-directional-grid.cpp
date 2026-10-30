class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int r=0,c=0;
        vis[r][c]=true;
        while(true){
            int nr=r,nc=c;
            if(grid[r][c]=='L'){
                nc--;
            }else if(grid[r][c]=='R'){
                nc++;
            }else if(grid[r][c]=='U'){
                nr--;
            }else if(grid[r][c]=='D'){
                nr++;
            }
            if (nr<0 || nr>=m || nc<0 || nc>=n){
                break;
            }
            if(vis[nr][nc]){
                break;
            }
            r=nr;
            c=nc;
            vis[r][c]=true;
        }
        return {r,c};
    }
};