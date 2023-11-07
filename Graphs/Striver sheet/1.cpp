#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = {{0,-1},{0,1},{1,0},{-1,0}};
vector<string> dch = { "d", "r" , "u" , "l"};
int n,m;
void dfs(int i,int j,int **arr,string &s)
{
    if(i < 0 || i>=n || j<0 || j>=m || arr[i][j] == 0) return;
    arr[i][j] = 0;
    for(int k=0;k < dir.size();k++)
    {
        int nx = i+ dir[k][0],ny = j+dir[k][1];
        if(nx < 0 || nx >=n || ny<0 || ny >= m || arr[nx][ny] == 0) continue;
       // cout<<arr[nx][ny] << " next ind " << nx<< " "<<ny<<endl;
        //cout<<"added "<<dch[k]<<endl; 
        s+= dch[k];
        dfs(nx,ny,arr,s);
        s+="b";
    }
    return;
}
//sddrbbb/
//sllbbb
//2

// 5
// 5
// 1 1 0 0 0
// 1 1 0 0 0
// 0 0 0 0 0
// 0 0 0 1 1 
// 0 0 0 1 1

int distinctIslands(int** arr, int n1, int m1)
{
    n=n1,m=m1;
    unordered_set<string> st;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j] == 1)
            {
                string s = "s";
                dfs(i,j,arr,s);
                //cout<<s<< endl;
                st.insert(s);
            }
        }
    }
    return st.size();
}