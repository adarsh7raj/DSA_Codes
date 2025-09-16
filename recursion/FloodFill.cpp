

class Solution {
public:
 bool isValid(int x, int y, int sp,int n,int m, vector<vector<int>> & image) {
        return x >= 0 && y >= 0 && x < m && y < n && image[x][y]==sp;
    }
void ColorFill(vector<vector<int>> & image,int sp,int x , int y , int color,int n,int m){
         
          int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};
      
      for(int i=0;i<4;i++){
        int di=x+dx[i];
        int dj=y+dy[i];
        if(isValid(di,dj,sp,n,m,image)){
            image[di][dj]=color;
ColorFill(image,sp,di,dj,color,n,m);
        }
         
      }
      
        
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
int m=image.size();
int n=image[0].size();
int sp=image[sr][sc];
image[sr][sc]=color;
if (sp == color) return image;
ColorFill(image,sp,sr,sc,color,n,m);
return image;
    
        
    }
};