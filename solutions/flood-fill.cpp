// https://leetcode.com/problems/flood-fill

class Solution {
public:
    int color = -1;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)     {
        if(color == -1) color = image[sr][sc];
        if(image.empty() || sr == -1 || sr == image.size() || sc == -1
           || sc == image[0].size() || image[sr][sc] != color || color == newColor) 
            return image;
        image[sr][sc] = newColor;
        floodFill(image, sr - 1, sc, newColor);
        floodFill(image, sr + 1, sc, newColor);
        floodFill(image, sr, sc - 1, newColor);
        floodFill(image, sr, sc + 1, newColor);
        return image;
    }
};