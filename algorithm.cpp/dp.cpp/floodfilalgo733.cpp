//this code is for problem no .733 on letcode the topic is floodfill algorithm which is nearly similar to krushkal algorithm . 
//this is a level of easy problem in algorithm 


class Solution {
public:

    void dfs(int row,int col,int n,int m, vector<vector<int>>& image,vector<vector<bool>>& vis , int newColor , int oldcolor) {
        vis[row][col] = true;
        image[row][col] = newColor;
        //up
        if(row-1 >= 0 && !vis[row-1][col] && image[row-1][col] == oldColor){
            dfs(row-1 ,col,n,m,image,vis,newColor,oldColor);
        }
        //down
         if(row+1 < n && !vis[row+1][col] && image[row+1][col] == oldColor){
            dfs(row+1 ,col,n,m,image,vis,newColor,oldColor);
        }
        //left
         if(col-1 >= 0 && !vis[row][col-1] && image[row][col-1] == oldColor){
            dfs(row ,col-1,n,m,image,vis,newColor,oldColor);
        }
        //right
         if(col+1 < m && !vis[row][col
        +1] && image[row][col+1] == oldColor){
            dfs(row ,col+1,n,m,image,vis,newColor,oldColor);
        }
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        dfs(sr,sc,n,m,image,vis,newColor,image[sr][sc]);
        return image;

    }
    
    
};

//2 approach - copilot 

class Solution {
public:
    void dfs(int row, int col, int n, int m, vector<vector<int>>& image,
             vector<vector<bool>>& vis, int newColor, int oldColor) {
        vis[row][col] = true;
        image[row][col] = newColor;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                !vis[newRow][newCol] && image[newRow][newCol] == oldColor) {
                dfs(newRow, newCol, n, m, image, vis, newColor, oldColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];
        if (oldColor == newColor) return image;

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        dfs(sr, sc, n, m, image, vis, newColor, oldColor);
        return image;
    }
};