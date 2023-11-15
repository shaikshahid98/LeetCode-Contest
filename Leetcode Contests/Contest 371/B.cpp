class Solution {
public:
    int stoi(char c1,char c2)
    {
        int res= ((c1-'0') * 10 )+(c2-'0'); 
        //cout<<res<<endl;
        return res;
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& ac) {
        unordered_map<string,vector<string>> mp;
        for(auto p:ac)
                mp[p[0]].push_back(p[1]);
        vector<string>res;
        for(auto p:mp)
        {
            auto name = p.first;
            vector<string> data = p.second;
            sort(begin(data),end(data));
            for(int i=0;i<data.size();i++)
            {
                if(i+2 >= data.size()) continue;
                //cout<<data[i]<<endl;
                int h1 = stoi(data[i][0],data[i][1]),h2 = stoi(data[i+1][0],data[i+1][1]),h3 = stoi(data[i+2][0],data[i+2][1]);
                int m1 = stoi(data[i][2],data[i][3]),m2 = stoi(data[i+1][2],data[i+1][3]),m3 = stoi(data[i+2][2],data[i+2][3]);
                                cout<<"h "<<h1<<" "<<h2<<" "<<h3<<endl;
                cout<<"m "<<m1<<" "<<m2<<" "<<m3<<endl;
                
                if(h2 - h1 <= 1 && h3 - h1 <=1)
                {
                    if((h2-h1==0 && m2 >= m1 || h2 > h1 && m2 < m1 ) && (h3-h1 == 0 && m3 >= m1 || h3 > h1 && m3 < m1))
                    {
                        res.push_back(name);
                        break;
                    }
                }
            }
        }
        return res;
    }
};