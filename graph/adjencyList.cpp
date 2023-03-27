#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
	public:
		unordered_map<int,list<int>> adj;
		void makeEdge(int u,int v, bool direction){
			if(!direction){
				adj[v].push_back(u);
			}
			adj[u].push_back(v);
		}
		
		void printList(){
			for(auto i:adj){
				cout<<i.first<<"->";
				for(auto j:i.second){
					cout<<j<<",";
				}
				cout<<endl;
			}
		}
};

int main(){
	int n;
	cin>>n; //number of nodes;
	
	int m;
	cin>>m; //number of edges;
	
	graph g;
	
	for(int i =0;i<m; i++){
		int u , v;
		cin>>u>>v;
		g.makeEdge(u,v,false);
	}
	
	g.printList();
	
	return 0;
}
