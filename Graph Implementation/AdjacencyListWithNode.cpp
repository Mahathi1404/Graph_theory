#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<unordered_map>

using namespace std;

class Node{
public:
	string name;
	list<string> nbrs;

	Node(string name)
	{
		this->name=name;
	}
};

class graph{
	unordered_map<string,Node*> m;
public:
	graph(vector<string> cities)
	{
		for(auto city:cities)
		{
			m[city]= new Node(city);
		}
	}

	void addEdge(string s,string t,bool undir=false)
	{
		m[s]->nbrs.push_back(t);
		if(undir)
			m[t]->nbrs.push_back(s);
	}

	void printNodes()
	{
		for(auto i: m)
		{
			cout<<i.first<<"-->";
			Node* temp=i.second;
			for(auto nbr:temp->nbrs)
				cout<< nbr<<",";
			cout<<endl;
		}
	}
};

int main()
{
	vector<string> s;
	s={"Delhi","Bangalore","NY","London"};
	graph g(s);
	g.addEdge("Delhi","Bangalore");
	g.addEdge("Delhi","London");
	g.addEdge("Bangalore","NY");
	g.printNodes();
	return 0;
}