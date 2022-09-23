class Solution {
public:
    void DFS(int i, int j, vector<vector<char>>& grid){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(int k=0; k<4; k++){
            DFS(i + dir[k][0], j + dir[k][1], grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size(), islands = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    DFS(i, j, grid);
                }
            }
        }
        return islands;
    }
};