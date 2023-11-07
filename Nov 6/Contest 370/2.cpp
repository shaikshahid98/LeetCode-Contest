class Solution {
public:
    unordered_set<int> dfs(int st,vector<vector<int>> &gr,map<int,unordered_set<int>> &mp)
    {
        if(mp[st].size()) return mp[st];
        auto fr = unordered_set<int>(begin(gr[st]),end(gr[st]));
        for(int i:gr[st])
        {
            auto tmp = dfs(i,gr,mp);
            for(int i:tmp)
            fr.insert(i);
        }
        
        return  mp[st] = fr;
        
    }
    int findChampion(int n, vector<vector<int>>& edges) {
//         if(edges.size() == 0 ) return n==1 ? 0 : -1;
    
//         int m=edges[0].size();
//         vector<vector<int>> gr(n);
//         for(auto p:edges) {
//             gr[p[0]].push_back(p[1]);
//         }
//         map<int,unordered_set<int>> mp;        
//         for(int i=0;i<n;i++)
//         {
//             auto fr = dfs(i,gr,mp);
//             //cout<<fr<<" <- cnt "<<endl;
//             if(fr.size() == n-1) return i;
//         }
//         return -1;
        
        vector<int> ind(n,0);
        for(auto p:edges) ind[p[1]]++;
        
        int res= -1;
        for(int i=0;i<n;i++)
            if(ind[i] == 0)
            {
                if(res == -1) res = i;
                else return -1;
            }
        return res;
    }
};