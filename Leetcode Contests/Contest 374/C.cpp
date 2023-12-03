class Solution {
public:
    vector<vector<int>> vec;
    int func(int x,int k,string s)
    {
        int res=0;
        for(auto &p:vec)
        {
            int cntk=0,st = p[0],e=p[1];
            unordered_map<char,int> mp;
            for(int i=st,j=st;j<=e;j++)
            {
                mp[s[j]]++;
                if(mp[s[j]] == k) cntk++;
                if( j - i+1 > (x*k))
                {
                    mp[s[i]]--;
                    if(mp[s[i]] == k-1)
                        cntk--;
                    if(mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
                if(mp.size() == x && mp.size()  == cntk) res++;
            }
        }
        return res;

    }
    int countCompleteSubstrings(string word, int k) {
        if(word.size()==1 && k == 1) return 1;
        vector<int> tmp;
        auto s = word;
        for(int i=1;i<s.size();i++)
        {
            if(abs(s[i] - s[i-1]) > 2)
            tmp.push_back(i);
        }
        int st = 0,e = s.size()-1;
        for(int i:tmp)
        {
            if(st <= i-1)
                vec.push_back({st,i-1});
            st = i;
        }
        if(st <= e) vec.push_back({st,e});
        int res=0;
        for(int i=1;i<=26 && i * k <= s.size();i++)
            res+=func(i,k,s);
        return res;
    }
};