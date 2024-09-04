// Adjacency Matrix representation in C++

#include <iostream>
using namespace std;

//Taken from programiz site But it's a inneficient way to initialise the graph
class Graph
{
private:
  // pointer of pointer because we need a matrix of array
  bool **adjMatrix;
  int numVertices;

public:
  // Initialize the matrix to zero
  Graph(int vertices)
  {
    numVertices = vertices;
    // Declare array of bool* pointers array of size numVertices
    adjMatrix = new bool *[numVertices];

    for (int i = 0; i < numVertices; i++)
    {
      // initialising that pointers array with array
      adjMatrix[i] = new bool[numVertices];
      for (int j = 0; j < numVertices; j++)
        adjMatrix[i][j] = false;
    }
  }

  // Add edges
  void addEdge(int i, int j)
  {
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
  }

  // Remove edges
  void removeEdge(int i, int j)
  { //Undirected
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
  }

  // Print the martix
  void PrintMatrix()
  {
    for (int i = 0; i < numVertices; i++)
    {
      cout << i << " : ";
      for (int j = 0; j < numVertices; j++)
        cout << adjMatrix[i][j] << " ";
      cout << "\n";
    }
  }

  // Destructor
  ~Graph()
  {
    for (int i = 0; i < numVertices; i++)
      delete[] adjMatrix[i];
    delete[] adjMatrix;
  }
};

int main()
{
  Graph g(4);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);

  g.PrintMatrix();
}