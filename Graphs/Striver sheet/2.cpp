#include<bits/stdc++.h>
using namespace std;
int wordLadder(string begin, string e, vector<string> &dict) 
{
	unordered_set<string> st;
	for(auto s:dict) st.insert(s);
	int t = 1 ;
	set<string> vis;
	queue<string>q;
	q.push(begin);
	while(q.size())
	{
		int sz = q.size();
		t++;
		while(sz--)
		{
			string cur = q.front();
			q.pop();
			for(int i=0;i<cur.size();i++)
			{
				char ch = cur[i];
				string tmp = cur;
				//cout<<"Current is "<<tmp<<endl;
				for(char c = 'a'; c<='z';c++)
				{
					if(c== ch ) continue;
					tmp[i] = c;
					//cout<<"After replacing "<<i<<" is "<<tmp<<endl;
					if(tmp == e) return t;
					if(vis.count(tmp) == 0 && st.count(tmp) == 1)
					{
						//cout<<"Cur to "<<tmp<<endl;
						q.push(tmp);
						vis.insert(tmp);
					}
				}
			}
		}
	}
	return -1;

}