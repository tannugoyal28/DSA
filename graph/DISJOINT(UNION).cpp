//union by Rank and path compression
#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#include<vector>
using namespace std;

class graph{
	public:
		//path compresion
	int findParent(vector<int> &parent, int node){
		if(parent[node] == node) return node;
		return parent[node] = findParent(parent,parent[node]);
	}
	
	void union(int n,int u,int v,vector<int>& rank,vector<int>& parent){
		u = findParent(parent,u);
		v = findParent(parent,v);
		 
		 if(rank[u] > rank[v]){
		 	parent[v] = u;
		 }else if(rank[u] == rank[v]){
		 	parent[v] = u;
		 	rank[u]++;
		 }else{
		 	parent[v] = u;
		 }
	}
	
};

int main(){
	int n;
	cin>>n; //no of nodes;
	//no edges making bcoz we assuming that all the nodes are disjoint and having themselves as their parent
	graph g;
	vector<int> rank(n+1,0);
	vector<int> parent(n+1);
	for(int i =1;i<=n; i++) parent[i] =i;
	int m;
	cout<<"enter the number of unions you want to do"<<endl;
	cin>>m;
	int u;
	int v;
	for(int i=0; i<m; i++){
		cin >> u >> v;
		g.union(n,u,v,rank,parent);
	}
	for(int i=1; i<=n; i++) cout<<i<<"has parent node"<<parent[i]<<" "<<endl;
	return 0;
}
