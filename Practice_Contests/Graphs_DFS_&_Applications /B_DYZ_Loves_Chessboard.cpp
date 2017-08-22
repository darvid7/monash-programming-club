// TODO: Use this on linux:
// #include <bits/stdc++.h>
// Use below on osx:

#include "stdc++.h"

// To compile: $ g++ -Wall A_New_Year_Transportation.cpp -o A

using namespace std;
// vector is a dynamic list, lists need space declared.
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpi;

// Variation of two colouring.
// a - is a bad cell (no edge/connection b/w cells).
// a . is a valid cell.

int rows, cols;

vpi getEdges(int row, int col) {
  // Only can go to cells that share a common edge.
  vpi edges;
  // edges.resize(8);
  if (row < rows) {
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
  if (col < cols ) {
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

bool twoColouringDfs(int curRow, int curCol, vvi graph, char lastColour) {
  char currentNodeValue = graph[curRow][curCol];

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

    vpi adjacentCells = getEdges(curRow, curCol);
    for (int i = 0; i < adjacentCells.size(); i++) {
      pair<int, int> p = adjacentCells[i];
      int nextRow = p.first;
      int nextCol = p.second;
      // Bad space.
      if (graph[nextRow][nextCol] == '-') {
        continue;
      }

      if (graph[nextRow][nextCol] == lastColour) {
        // Bad colouring.
        return false;
      }

      if (graph[nextRow][nextCol] == '.') {
        // Do dfs.
        twoColouringDfs(nextRow, nextCol, graph, lastColour);
      } else {
        cout << "WTF MAN" << endl;
      }
    }
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

  string aRow;
  for (int i = 0; i < rows; i++) {
    cin >> aRow;
    for (string::size_type j = 0; j < aRow.size(); j++) {
        adjacencyMatrix[i][j] = aRow[j];
    }


  }

  char lastColour = 'B';

  twoColouringDfs(0, 0, adjacencyMatrix, lastColour);

  // Print matrix.
  for (vi v : adjacencyMatrix) {
    // Note: No type issues by typing it as ints.
    for (char x : v) {

      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}
