// Use this on linux: #include <bits/stdc++.h>
// Use below on osx:
// #include "stdc++.h"
#include <bits/stdc++.h>

// To compile: $ g++ -Wall A_New_Year_Transportation.cpp -o A

using namespace std;

// vector is a dynamic list, lists need space declared.
typedef vector<int> vectorOfInts;
// typedef vector<vector<int> > vectorOfVectorsOfInts;

vectorOfInts portals;
vectorOfInts visited;
vectorOfInts adjacencyList;
// vectorOfVectorsOfInts adjacencyList;

int target;

bool depthFirstSearch(int currentNode) {
  // cout << "Current node: " << currentNode << endl;
  if (currentNode == target) {
    visited[currentNode] = 1;
    return true;
  }

  if (visited[currentNode] == 1) {
    return false;
  }
  visited[currentNode] = 1;
  int next = adjacencyList[currentNode];
  if (visited[next] != 1) {
    if (depthFirstSearch(next)) {
      return true;
    }
  }
  return false;

}

int main() {
  int n;
  // cin reads
  cin >> n;
  cin >> target;

  // Resize arrays.
  portals.resize(n + 1);
  visited.resize(n + 1);
  adjacencyList.resize(n + 1);

  // Fill vector of 0s.
  fill(visited.begin(), visited.end(), 0);

  // Resize Adjacency List.
  // adjacencyList.resize(n + 1);
  // for(int i = 1; i < n + 1; i++) {
  //   adjacencyList[i].resize(1);
  // }

  // Read in portals.
  for(int i = 1; i < n; i++) {
    int tmp;
    cin >> tmp;
    portals[i] = tmp;
  }

  for (int k = 1; k < n + 1; k++) {
    int value = k + portals[k];
    adjacencyList[k] = value;
    // cout << "adjacencyList index: " << k << " has edge " << value << endl;

  }

  bool result;
  result = depthFirstSearch(1);

  if (result) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }


  // for (int j = 0; j < visited.size(); j++) {
  //   cout << "index: " <<  j << ", value: " << visited[j] << endl;
  // }

  return 0;
}
