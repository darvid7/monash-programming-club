// TODO: Use this on linux:
#include <bits/stdc++.h>
// Use below on osx:

// #include "stdc++.h"

// To compile: $ g++ -std=c++11 -Wall file.cpp -o F

using namespace std;
// vector is a dynamic list, lists need space declared.
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpi;

// Variation of two colouring.
// a - is a bad cell (no edge/connection b/w cells).
// a . is a valid cell.

int rows, cols;

vpi getEdges(int row, int col, vvi graph) {
  // Only can go to cells that share a common edge.
  vpi edges;
  // edges.resize(8);
  if (row < rows - 1) {
    // Check below.
    // Add directly below.
    pair<int, int> p = {row + 1, col};
    edges.push_back(p);
  }
  if (row > 0) {
    // Check above.
    // Add directly above.
    pair<int, int> p = {row - 1, col};
    edges.push_back(p);
  }
  // Check to the right.
  if (col < cols -1 ) {
    // Can go to the right.
    pair<int, int> p = {row, col + 1};
    edges.push_back(p);
  }

  if (col > 0) {
    // Check to the left.
    pair<int, int> p = {row, col - 1};
    edges.push_back(p);
  }
  return edges;
}

bool twoColouringDfs(int curRow, int curCol, vvi& graph, char lastColour) {
  char currentNodeValue = graph[curRow][curCol];
  // cout << "Current coords: (" << curRow << ", " << curCol << ")" << endl;
  if (currentNodeValue == '.') {
    char oldColor = lastColour;
    // Set this value to a colour.
    if (lastColour == 'B') {
      lastColour = 'W';
    } else {
      lastColour = 'B';
    }
    // Set this dot to some colour.
    graph[curRow][curCol] = lastColour;

    // cout << ">>a graph>>" << endl;
    for (vi v : graph) {
      // Note: No type issues by typing it as ints.
      for (char x : v) {

        // cout << x << " ";
      }
      // cout << endl;
    }
    // cout << "<<end graph"<< endl;

    vpi adjacentCells = getEdges(curRow, curCol, graph);
    // For each adjacent cell, explore as far as possible.
    for (int i = 0; i < adjacentCells.size(); i++) {
      pair<int, int> p = adjacentCells[i];
      int nextRow = p.first;
      int nextCol = p.second;
      // cout << "adj coord: (" << nextRow << ", " << nextCol << ")" << endl;
      char c = graph[nextRow][nextCol];

      // Bad space.
      if (c == '-') {
        continue;
      }

      if (c == oldColor) {
        // Bad colouring.
        continue;
      }

      if (c == '.') {
        // Do dfs.
        // cout << "exploring: (" << nextRow << ", " << nextCol << ")" << endl;
        twoColouringDfs(nextRow, nextCol, graph, lastColour);
      } else {
        // cout << "WTF MAN: " << c << endl;
      }
    }
    // // cout << "b graph" << endl;
    // for (vi v : graph) {
    //   // Note: No type issues by typing it as ints.
    //   for (char x : v) {
    //
    //     // cout << x << " ";
    //   }
    //   // cout << endl;
    // }

    return true;
  }
  return true;
}


int main() {
  cin >> rows >> cols;

  vvi adjacencyMatrix;

  adjacencyMatrix.resize(rows);

  for (int i = 0; i < adjacencyMatrix.size(); i++) {
    adjacencyMatrix[i].resize(cols);
  }

  vpi dots;

  string aRow;
  for (int i = 0; i < rows; i++) {
    cin >> aRow;
    for (string::size_type j = 0; j < aRow.size(); j++) {
        adjacencyMatrix[i][j] = aRow[j];
        if (aRow[j] == '.') {
          pair<int, int> p = {i, j};
          dots.push_back(p);
        }
    }
  }

  char lastColour = 'B';

  for (int i = 0; i < dots.size(); i++) {
    // // cout << "dots value of i: " << i << " is (" << dots[i].first << ", " << dots[i].second << ")" << endl;
    twoColouringDfs(dots[i].first, dots[i].second, adjacencyMatrix, lastColour);

  }

  // Print matrix.
  for (vi v : adjacencyMatrix) {
    // Note: No type issues by typing it as ints.
    for (char x : v) {

      cout << x;
    }
    cout << endl;
  }

  return 0;
}
