// TODO: Use this on linux:
#include <bits/stdc++.h>
// Use below on osx:
// #include "../stdc++.h"
// To compile: $ g++ -std=c++11 -Wall file.cpp -o F
using namespace std;

// Problem:
// - undirected weighted graph.
// - shortest path from vertex 1 to vertext n (1 based indexing).

typedef vector<vector<pair<int, int> > > vvpii;

// Comparison for elements in pq, this implements a min heap.
struct compare {
  bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first > p2.first;
  }
};

priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq; // Min heap due to compare, default is max.
vvpii adjacencyList;
vector<int> distances; // Represents distances from node 0, 1, ... n.
vector<int> parents; // Parent (where you were before this node) of nodes.
int n, m;

int main() {
  cin >> n;
  cin >> m;

  distances.resize(n + 1);
  adjacencyList.resize(n + 1);
  parents.resize(n + 1);

  for (int i = 0; i < distances.size(); i++) {
    distances[i] = -1;  // Use -1 to reprsent not seen yet.
    parents[i] = -1;
  }

  // Read in edges.
  for (int i = 0; i < m; i++) {
    int src, dest, weight;
    cin >> src;
    cin >> dest;
    cin >> weight;
    // cout << src << " " << dest << " " << weight << endl;
    adjacencyList[src].push_back({dest, weight});
    adjacencyList[dest].push_back({src, weight});
  }

  // Init node 1 (start node) with distance 0.
  int startNode = 1;
  int startDist = 0;
  pq.push({startDist, startNode});

  while ( !pq.empty() ) {
    pair<int, int> current = pq.top();
    pq.pop();

    int distToCurrent = current.first;
    int currentNode = current.second;
    // cout << "looking at node: " << currentNode << " with distance " << distToCurrent << endl;
    // Relax edge.
    if (distToCurrent > distances[currentNode] && distances[currentNode] != -1) {
      // if current distance is > than distance we know, and what we know
      // is not -1 (haven't visited yet), no point doing this.
      continue;
    }

    // If get to here, distToCurrent is the best way we know to get to current.
    distances[currentNode] = distToCurrent;

    vector<pair<int, int> > edgeList = adjacencyList[currentNode];

    for (pair<int, int> p : edgeList) {
      int weight = p.second;
      int connectedNode = p.first;

      // cout << "edges to node: " << currentNode << ", next node: " << connectedNode << ", weight " << weight << endl;

      if (distances[connectedNode] != -1 && distToCurrent + weight >= distances[connectedNode]) {
        continue;
      }
      distances[connectedNode] = distances[currentNode] + weight;
      // cout << "pushed edge: " << connectedNode << ", " << weight + distToCurrent << endl;
      parents[connectedNode] = currentNode;
      pq.push({weight + distToCurrent, connectedNode});
    }
  }
  // cout << "indexes:    ";
  // for (int j = 0; j < distances.size(); j++) {
  //   cout << j << " ";
  // }
  // cout << endl;
  //
  // cout << "distances: ";
  // for (int d: distances) {
  //   cout << d << " ";
  // }
  // cout << endl;
  // cout << "parents:   ";
  // for (int p: parents) {
  //   cout << p << " ";
  // }
  // cout << endl;
  //
  // cout << "goal is node " << n << ", dist: " << distances[n] << endl;

  if (distances[n] == -1) {
    cout << -1 << endl;
    return 0;
  }
  int parentNode = n;

  vector<int> path;

  while ((parentNode != -1)) {
    // cout << "parent node is: " << parentNode << endl;
    path.push_back(parentNode);
    parentNode = parents[parentNode];
  }

  for (int i = path.size() - 1; i >= 0; i--) {
    cout << path[i] << " ";
  }
  cout << endl;
  return 0;
}

/*
Sample input:
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1

graph, weights not in (), nodes in ():

  (1)--2-(2)-5-(5)
   |      |     |
   1      4     |
   |      |     |
  (4)-3-(3)-----1


*/
