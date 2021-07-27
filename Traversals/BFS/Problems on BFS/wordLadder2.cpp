#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

class node{
public:
	string name;
	list<string> l;
	node(string name)
	{
		this->name=name;
	}
};
class graph{
public:
	unordered_map<string,node*> m;
	graph(vector<string> dictionary)
	{
		//create node for each string
		for(auto word:dictionary)
		{
			m[word]=new node(word);
		}
	}

	void addEdge(string src,string des,bool undir=false)
	{
		m[src]->l.push_back(des);
		if(undir)
		{
			m[des]->l.push_back(src);
		}
	}

	void printGraph()
	{
		for(auto i:m)
		{
			cout<<i.first<<":";
			node* temp=i.second;
			for(auto j:temp->l)
				cout<<j<<",";
			cout<<endl;
		}
	}

	int bfs(string src,string des)
	{
		queue<string> q;
		unordered_map<string,int> visited;
		unordered_map<string,int> distance;
		q.push(src);
		string temp;
		visited[src]=1;
		distance[src]=0;
		while(q.empty()!=1)
		{
			temp=q.front();
			q.pop();
			if(temp==des)
				return distance[temp]+1;
			for(auto i:m[temp]->l){
			if(visited.find(i)==visited.end())
			{
				visited[i]=1;
				q.push(i);
				distance[i]=distance[temp]+1;
			}
		}
		}

		if(temp==des)
			return distance[des]+1;
		return 0;
	}
};

vector<vector<int>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
	unordered_set<string> s;
	unordered_map<string,int> visited;
	for(auto i: wordList){
		s.insert(i);
		visited[i]=0;
	}
	if(s.find(endWord)==s.end())
		return {};
	if(s.find(beginWord)==s.end())
		wordList.push_back(beginWord);
	graph g(wordList);
	queue<string> q;
	visited[beginWord]=1;
	q.push(beginWord);
		while(q.empty()!=1){
			string temp=q.front();
			q.pop();
			string parent=temp;
			for(int i=0;i<beginWord.length();i++)
			{
			char ch=temp[i];//backup
			for(char x='a';x<='z';x++)
			{
				if(x!=ch)
				{
					temp[i]=x;
					if(s.find(temp)!=s.end()){
						if(visited[temp]==0){
							g.addEdge(parent,temp);
							q.push(temp);
							visited[temp]=1;
					}
					}
				}
			}
		temp[i]=ch;
	}
	}
	g.printGraph();
	return {{g.bfs(beginWord,endWord)}};
}
int main()
{
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
	vector<vector<int>> ans=findLadders(beginWord,endWord,wordList);
	return 0;
}