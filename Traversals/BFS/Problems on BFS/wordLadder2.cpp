#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

    list<string> find_neighbours(string word,unordered_set<string> s)
    {
        list<string> ans;
        for(int i=0;i<word.length();i++)
        {
            char ch=word[i];
            for(char c='a';c<='z';c++)
            {
                if(c!=ch){
                word[i]=c;
                if(s.find(word)!=s.end())
                {
                    ans.push_back(word);
                    s.erase(word);
                }
            }
            }
            word[i]=ch;
        }
        return ans;
    }
    unordered_map<string,list<string>> adjList(string beginWord,unordered_set<string> s)
    {
        unordered_map<string,list<string>> g;
        if(s.find(beginWord)==s.end())
            s.insert(beginWord);
        for(auto i=s.begin();i!=s.end();i++){
        list<string> nbrs=find_neighbours(*i,s);
        g[*i]=nbrs;
    }
    return g;
    }
void traverse(string src,string d,unordered_map<string,vector<string>> p,vector<string> &s,vector<vector<string>> &a)
{
	if(src==d)
		a.push_back(s);
	else{
	for(auto i:p[src]){
			s.push_back(i);
			traverse(i,d,p,s,a);
			s.pop_back();
	}
}
	/*for(auto i:p)
		{
			string j=i.second;
			//cout<<i<<": ";
			while(j!=src)
			{
				s.push_back(p[j]);
				traverse(p[j],d,p,vis,s,a);
			}
			//cout<<endl;
		}*/
}

vector<vector<string>> dfs(string src,string des,unordered_map<string,vector<string>> p)
{
	//unordered_map<string,int> visited;
	vector<vector<string>> ans;
	vector<string> op;
	op.push_back(src);
	traverse(src,des,p,op,ans);
	return ans;
}
vector<vector<string>> bfs(string src,string des,unordered_map<string,list<string>> g,unordered_set<string> &s)
    {
        queue<string> q;
        unordered_map<string,int> visited;
        unordered_map<string,vector<string>> parent;//(child,parent)
        q.push(src);
        visited[src]=1;
        //	parent[src].push_back(src);
        string temp;
        while(!q.empty())
        {
        	int n=q.size();
        	while(n--){
            temp=q.front();
            q.pop();
            for(auto child:g[temp])
            {
                if(visited.count(child)==0)
                {
                    //cout<<child<<" "<<temp<<endl;
                    visited[child]=visited[temp]+1;
                    q.push(child);
                    parent[temp].push_back(child);
                    s.erase(child);
                }
                  else
                  {
                  	 if(visited[child]==visited[temp]+1)
                  	 	parent[temp].push_back(child);
                }
            }
        }
    }
         for(auto i:parent){
          	cout<<i.first<<":";
           	for(auto j:parent[i.first])
           		cout<<j<<",";
           	cout<<endl;
          }
        return dfs(src,des, parent);
    }
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
	unordered_set<string> s;
	for(auto i: wordList){
		s.insert(i);
	}
	if(s.find(endWord)==s.end())
		return {};
	unordered_map<string,list<string>> graph=adjList(beginWord,s);
	//  for(auto i:graph)
	//  {
	//  	cout<<i.first<<":";
	//  	for(auto j:i.second)
	//  	{
	//  		cout<<j<<"->";
	//  	}
	//  	cout<<endl;
	// }
	return bfs(beginWord,endWord, graph,s);
}
int main()
{
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
	vector<vector<string>> ans=findLadders(beginWord,endWord,wordList);
	for(auto i:ans)
	{
		for(auto j:i)
		{
			cout<<j<<",";
		}
		cout<<endl;
	}
	return 0;
}

/*
log:cog,
dog:cog,
hit:hot,
dot:dog,
hot:dot,lot,
lot:log,
*/