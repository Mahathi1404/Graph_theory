/*
The BFS algorithm is defined as follows.

Consider an undirected graph with vertices numbered from 1 to n. Initialize q as a new queue containing only vertex 1, mark the vertex 1 as used.
Extract a vertex v from the head of the queue q.
Print the index of vertex v.
Iterate in arbitrary order through all such vertices u that u is a neighbor of v and is not marked yet as used. Mark the vertex u as used and insert it into the tail of the queue q.
If the queue is not empty, continue from step 2.
Otherwise finish.
Since the order of choosing neighbors of each vertex can vary, it turns out that there may be multiple sequences which BFS can print.

In this problem you need to check whether a given sequence corresponds to some valid BFS traversal of the given tree starting from vertex 1. The tree is an undirected graph, such that there is exactly one simple path between any two vertices.

Input
The first line contains a single integer n (1≤n≤2⋅105) which denotes the number of nodes in the tree.

The following n−1 lines describe the edges of the tree. Each of them contains two integers x and y (1≤x,y≤n) — the endpoints of the corresponding edge of the tree. It is guaranteed that the given graph is a tree.

The last line contains n distinct integers a1,a2,…,an (1≤ai≤n) — the sequence to check.

Output
Print "Yes" (quotes for clarity) if the sequence corresponds to some valid BFS traversal of the given tree and "No" (quotes for clarity) otherwise.

You can print each letter in any case (upper or lower).
*/
#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;
class graph
{
public:
    int V;
    list<int> *l;
public:
    graph(int V=0)
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
            for(int j:l[i])
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

    vector<int> bfs(int src)
    {
        vector<int> vis(V,0);
        queue<int> q;
        vis[src]=1;
        q.push(src);
        vector<int> traversal;
        while(q.empty()!=1)
        {
            int temp=q.front();
            traversal.push_back(temp);
            q.pop();
            for(auto child:l[temp])
            {
                if(vis[child]==0)
                {
                    vis[child]=1;
                    q.push(child);
                }
            }
        }
        return traversal;
    }
    
};

bool validBfs(int n, vector<int> &sequence , vector<vector<int>> v)
{
    graph g(n);
    for(auto i:v)
    {
        g.addEdge(i[0],i[1]);
    }
    for(int i=1;i<n+1;i++)
    {
        g.l[i].sort([&sequence](int a,int b) {return find(sequence.begin(),sequence.end(),a)-sequence.begin()<find(sequence.begin(),sequence.end(),b)-sequence.begin();});
    }
    //g.printGraph();
    vector<int> required;
    required=g.bfs(sequence[0]);
    for(auto i:required)
        cout<<i<<" ";
    for(int i=0;i<n;i++)
    {
        if(required[i]!=sequence[i])
            return false;
    }
    return true;
}
int main()
{
	vector<vector<int>> v={{1,2},{1,5},{2,3},{2,4},{5,6}};
	int n=6;
	vector<int> seq={1,5,2,3,4,6};
    if(validBfs(n,seq,v))
	   cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
	return 0;
}
/*
6 -> Number of nodes
1 2
1 5
2 3
2 4
5 6
1 5 2 3 4 6 
*/