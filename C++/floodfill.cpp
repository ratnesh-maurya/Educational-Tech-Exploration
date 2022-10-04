#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>> &image,int initial_color,int color,int i,int j)
    { 
        int n=image.size();
        int m=image[0].size();
        if(i<0||j<0) 
            return;
        if(i>=n||j>=m)
            return;
        if(image[i][j]!=initial_color)
            return;
        image[i][j]=color;
        
    
        
        
        dfs(image,initial_color,color,i+1,j);
        dfs(image,initial_color,color,i-1,j);
        dfs(image,initial_color,color,i,j+1);
        dfs(image,initial_color,color,i,j-1);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial_color=image[sr][sc];
        if(initial_color!=color)
        dfs(image,image[sr][sc],color,sr,sc);
        return image;
    }
};