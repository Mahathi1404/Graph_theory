#include<iostream>
#include<list>
#include<vector>

using namespace std;


class graph{
	int V;
	list<int> *l;//pointer to an array of list
public:
	graph(int v=0)
	{
		V=v;
		l=new list<int>[V];
	}

	void addEdge(int i,int j,bool undir=true)
	{	
		l[i].push_back(j);
		if(undir)
			l[j].push_back(i);
	}

	void printGraph()
	{	//iterate over array i.e nodes
		for(int i=0;i<V;i++)
		{
			cout<<i<<"-->";
			//for each node's linkedlist
			for(auto node:l[i]) 
				cout<<node<<",";
			cout<<endl;

		}
	}
};
int main()
{
	graph g(6);

	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(4,3);
	g.addEdge(4,5);
	g.addEdge(3,2);
	//g.addEdge(2,1);
	g.addEdge(3,4);
	g.addEdge(3,5);
	g.printGraph();

	return 0;
}


