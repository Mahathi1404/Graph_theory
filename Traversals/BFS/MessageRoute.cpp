#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;


class graph{
public:
	int V;
	list<int> *l;
	graph(int V)
	{
		this->V=V+1;
		l=new list<int> [V+1];
	}

	void addEdge(int src,int des,bool undir=true)
	{
		l[src].push_back(des);
		if(undir)
		{
			l[des].push_back(src);
		}
	}

	void printGraph()
	{
		for(int i=1;i<V;i++)
		{
			cout<<i<<":";
			for(auto nbr:l[i])
			{
				cout<<nbr<<",";
			}
			cout<<endl;
		}
	}
};
int messageRoute(int n,vector<vector<int>> edges)
{
	graph g(n);
	for(auto i:edges)
	{
		g.addEdge(i[0],i[1]);
	}
	//g.printGraph();
	queue<int> q;
	vector<int> visited(n+1,0);
	vector<int> distance(n+1,0);
	int src=1;
	visited[src]=1;
	q.push(src);
	distance[src]=0;
	while(q.empty()!=1)
	{
		int temp=q.front();//parent node
		//cout<<temp<<" ";
		q.pop();
		for(auto nbr:g.l[temp]){
			if(visited[nbr]==0)
			{
				visited[nbr]=1;
				distance[nbr]=distance[temp]+1;
				q.push(nbr);
			}
		}
	}

	for(int i:distance)
		cout<<i<<" ";
	cout<<endl;
	return distance[distance.size()-1];
}

int main()
{
	vector<vector<int>> edges={{1,2},{1,3},{2,4},{2,5},{3,6}};
	int n=6;
	cout<<messageRoute(n,edges)<<endl;

	return 0;
}