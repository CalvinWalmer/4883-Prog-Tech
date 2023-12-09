#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <bits/stdc++.h> 
#include <iomanip>

using namespace std;

// DSU data structure 
// path compression + rank by union 
class DSU { 
	int* parent; 
	int* rank; 

public: 
	DSU(int n) 
	{ 
		parent = new int[n]; 
		rank = new int[n]; 

		for (int i = 0; i < n; i++) { 
			parent[i] = -1; 
			rank[i] = 1; 
		} 
	} 

	// Find function 
	int find(int i) 
	{ 
		if (parent[i] == -1) 
			return i; 

		return parent[i] = find(parent[i]); 
	} 

	// Union function 
	void unite(int x, int y) 
	{ 
		int s1 = find(x); 
		int s2 = find(y); 

		if (s1 != s2) { 
			if (rank[s1] < rank[s2]) { 
				parent[s1] = s2; 
			} 
			else if (rank[s1] > rank[s2]) { 
				parent[s2] = s1; 
			} 
			else { 
				parent[s2] = s1; 
				rank[s1] += 1; 
			} 
		} 
	} 
}; 

class Graph { 
	vector<vector<float> > edgelist; 
	int V; 

public: 
	Graph(int V) { this->V = V; } 

	// Function to add edge in a graph 
	void addEdge(float x, float y, float w) 
	{ 
		edgelist.push_back({ w, x, y }); 
	} 

	float kruskals_mst() 
	{ 
		// Sort all edges 
		sort(edgelist.begin(), edgelist.end()); 

		// Initialize the DSU 
		DSU s(V); 
		float ans = 0; 
		for (auto edge : edgelist) { 
			float w = edge[0]; 
			int x = edge[1]; 
			int y = edge[2]; 

			// Take this edge in MST if it does 
			// not forms a cycle 
			if (s.find(x) != s.find(y)) { 
				s.unite(x, y); 
				ans += w;
			} 
		} 
		return ans;
	} 
}; 


float distance(pair<float, float> from, pair<float, float> to){
    return(sqrt(pow(to.first - from.first, 2) + pow(to.second - from.second, 2)));

}


int main(){
    int numCases, numF;
    float x, y;
    vector<pair<float, float>> nodes;
    float dist;

    cin >> numCases;

    for(int c = 0; c < numCases; c++){
        cin >> numF;
        Graph g(numF);
        
        for(int i = 0; i < numF; i++){
            cin >> x;
            cin >> y;
            nodes.push_back(make_pair(x, y));
        }

        for(int i = 0; i < numF; i++){
            for(int j = 0; j < numF; j++){
                if(i != j){
                    g.addEdge(i, j, distance(nodes[i], nodes[j]));
                }
            }
        }
        cout << fixed << setprecision(2) << g.kruskals_mst() << endl;
        nodes.clear();
        if(c != numCases - 1){
            cout << endl;
        }
    }

    return(0);
}