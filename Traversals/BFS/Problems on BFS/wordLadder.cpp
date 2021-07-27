#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

int bfs(string src,string des,vector<string>& wordList)
{
	unordered_set<string> s;
	for(auto i:wordList)
		s.insert(i);
	if(s.find(des)==s.end())
		return 0;
	queue<string> q;
	int dist=0;
	q.push(src);
	string temp;
	while(!q.empty())
	{
         dist++;
        int n=q.size();
        while(n--){
		temp=q.front();
		q.pop();
        for(int i=0;i<src.length();i++){
            char backUp=temp[i];
            for(char ch='a';ch<='z';ch++)
            {
                if(backUp!=ch){
                    temp[i]=ch;
                    if(temp==des)
                        return dist+1;
                if(s.find(temp)!=s.end())
                {
                    q.push(temp);
                    s.erase(temp);//Once the word is picked in path, we don't need that word again, So remove it from dictionary.
                }
            }
		}
        
            temp[i]=backUp;
        }
        }
	}
	// for(auto i:dist)
	// 	cout<<i.first<<":"<<i.second<<endl;
	return 0;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	return bfs(beginWord,endWord,wordList);
}
int main()
{
	string beginWord = "hot";
	string endWord = "dot";
	vector<string> wordList = {"hot","dog","dot"};
	cout<<ladderLength(beginWord,endWord,wordList)<<endl;
	return 0;
}
