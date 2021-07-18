#include <iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class graph{
private:
	int V;
	int **edges;
public:
	graph(int V)
	{
		this->V=V;
		edges = new int *[V];
		for(int i=0;i<V;i++)
		{
			edges[i]= new int[2];
		}
		for(int i=0;i<V;i++)
		{
			edges[i][0]=-1;
			edges[i][1]=-1;
		}
	}

	void addEdges(int src,int dest,bool undir=true)
	{
		for(int i=0;i<V;i++)
		{
			if(edges[i][0]==-1)
			{
				edges[i][0]=src;
				edges[i][1]=dest;
				break;
			}
		}
	}

	void printList()
	{
		for(int i=0;i<V;i++)
		{
			cout<<"["<<edges[i][0]<<","<<edges[i][1]<<"]"<<endl;
		}
	}
};
int main()
{
	cout<<"hello"<<endl;
	graph g(3);

	g.addEdges(0,1);
	g.addEdges(1,2);
	g.addEdges(0,2);
	g.printList();
	return 0;
}