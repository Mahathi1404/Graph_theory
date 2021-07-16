//single source shortest path
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
		V=vertices;
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

	void bfs(int src)
	{
		queue<int> q;
		vector<int> visited(V,0);
		visited[src]=1;
		q.push(src);
		while(q.empty()!=1)
		{
			int temp=q.front();
			cout<<temp<<" ";
			q.pop();
			for(auto child:l[temp]){
				if(visited[child]==0)
				{
					q.push(child);
					visited[child]=1;
				}
			}
		}
	}
	void shortPath(int src)
	{
		queue<int> q;
		vector<int> visited(V,0);
		vector<int> distance(V,0);
		vector<int> parent(V,-1);
		visited[src]=1;
		q.push(src);
		distance[src]=0;
		parent[src]=src;
		while(q.empty()!=1)
		{
			int temp=q.front();
			//cout<<temp<<" ";
			q.pop();
			for(auto child:l[temp]){
				if(visited[child]==0)
				{
					q.push(child);
					visited[child]=1;
					distance[child]=distance[temp]+1;
					parent[child]=temp;
				}
			}
		}
		//print all the distances from given source
		for(int i=0;i<V;i++)
		{
			cout<<src<<"->"<<i<<": "<<distance[i]<<endl;
		}
		cout<<endl;
		//path for each node souce
		for(int i=0;i<V;i++)
		{
			int j=i;
			cout<<i<<": ";
			while(j!=src)
			{
				cout<<parent[j]<<"->";
				j=parent[j];
			}
			cout<<endl;
		}
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
	//g.bfs(1);
	g.shortPath(1);
	return 0;
}