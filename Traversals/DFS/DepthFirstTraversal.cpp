#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;
//adjacency list
class graph{
private:
	int V;
	list<int> *l;
public:
	graph(int vertices=0)
	{
		int V=vertices;
		l = new list<int>[V];
	}

	void addEdge(int src,int dst,bool undir=true)
	{
		l[src].push_back(dst);
		if(undir)
			l[dst].push_back(src);
	}

	void printGraph()
	{
		for(int i=0;i<V;i++)
		{
			cout<<i<<"->";
			for(auto j:l[i])
			{
				cout<<j<<",";
			}
			cout<<endl;
		}
	}
	void defsHelper(int src,vector<bool> & vis)
	{
		vis[src]=true;
		cout<<src<<",";
		//call dfs for all childeren of node
		for(int child: l[src])
		{	if(vis[child]==false)
				defsHelper(child,vis);
		}
		return;
	}

	void dfs(int src)
	{
		vector<bool> visited(V,false);
		defsHelper(src,visited);
	}
};
int main()
{
	graph g(7);

	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(4,3);
	g.addEdge(4,5);
	g.addEdge(5,6);
	//g.printGraph();
	g.dfs(1);
	return 0;
}