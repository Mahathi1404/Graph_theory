//keys and rooms problem
//based on dfs
//input: 2D array ,0 index based
//output: true if all rooms are reachable else false otherwise

#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

class graph{
	int V;
	list<int> *l;
public:
	graph(int V=0)
	{
		this->V=V;
		l=new list<int>[V];
	}

	void addEdge(int src,int des,bool undir=false)
	{
		l[src].push_back(des);
		if(undir)
		{
			l[des].push_back(src);
		}
	}

	void printGraph()
	{
		for(int i=0;i<V;i++)
		{
			cout<<i<<":";
			for(auto j:l[i])
			{
				cout<<j<<",";
			}
			cout<<endl;
		}
	}

	void dfsHelper(int src,vector<int> &vis,int &cnt)
	{
		vis[src]=1;
		cnt++;
		for(auto i:l[src])
		{

			if(vis[i]==0)
				dfsHelper(i,vis,cnt);
		}
	}
	bool dfs(int src)
	{
		vector<int> visited(V,0);
		int count=0;
		dfsHelper(src,visited,count);
		cout<<"count:"<<count<<endl;
		if(count==V)
			return true;
		return false;
		
	}
};

int main()
{
	vector<vector<int>> rooms={{1,3},{0,3,1},{2},{0}};
	int n=rooms.size();
	graph g(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<rooms[i].size();j++)
			g.addEdge(i,rooms[i][j]);
	}

	g.printGraph();
	cout<<g.dfs(0)<<endl;
}