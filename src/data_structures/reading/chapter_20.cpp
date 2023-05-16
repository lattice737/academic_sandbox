using namespace std;

/*
Vocabulary
==========
* Graph (G) - two sets {V, E}, made up of vertices (or nodes) and unique edges that connect them 
* Subgraph - two subsets, made up of a graph's verticies and their edges
* Adjacency - the linking of two vertices in a graph by an edge
* Path - a sequence of edges that begins at one vertex and ends at another vertex
* Simple path - a path that passes through each vertex once
* Cycle - a path that begins and ends at the same vertexx
* Simple cycle - a cycle that does not pass through vertices more than once
* Connected graph - a graph with a path between each pair of distinct vertices
* Disconnected graph - a graph with at least one vertex that has no edges connecting it to other vertices
* Complete graph - a connected graph with an edge between every pair of vertices and therefore the maximum number
  n(n-1)/2 edges
* Dense graph - a graph with almost the maximum number of edges
* Sparse graph - a graph with relatively few, or O(n), edges
* Multigraph - a graph-like structure with duplicate edges (graphs do not have duplicate edges)
* Loop (or self edge) - An edge beginning and ending at the same vertex (graph edges cannot begin and end at the
  same vertex)
* Weighted graph - a graph with numerically-labeled edges
* Undirected graph - a graph with edges that do not indicate direction
* Directed graph (or digraph) - a graph with directed edges
* Directed edge - an edge with a direction specified
* Directed path - a sequence of directed edges between two vertices
* Digraph adjacency - the linking of two vertices by a directed edge where vertex b is adjacent to vertex a if
  there is a directed edge a->b between them
* Successor - the vertex at the head of a directed edge
* Predecessor - the vertex at the tail of a directed edge
* Adjacency matrix - a graph representation of n vertices using an n x n array where any element matrix[i][j] is
  true only when there is an edge from vertex i to vertex j
* Adjacency list - a graph representation of n vertices using n linked chains, where the ith linked chain has a
  node for vertex j if an only if the graph contains an edge from vertex i to vertex j; each node contains some
  indication of the vertex's identity (e.g. vertex j value), and each edge is treated as if it were two directed
  edges in opposite directions
* 

General
=======
~ A graph can be modeled as a mathematical construct, a data structure, or an abstract data type
~ For a weighted graph, matrix[i][j] can be the weight that labels the edge from vertex i to vertex j (inf when
  there is no edge)
~ The adjacency matrix for an undirected graph is symmetrical (matrix[i][j] == matrix[j][i])
~ If values need to be associated with vertices, a second array (e.g. values) can be used to represent the n
  vertex values
~ Checking edge existence between vertices: adjacency matrix is more efficient, requiring only access to matrix[i][j]
  (adjacency list requires traversal of ith linked chain)
~ Find all vertices adjacent to a vertex: adjacency list is more efficient, requiring traversal of ith linked chain
  (adjacency matrix requires ith row, which always has n entries)
~ Adjacency matrices always have n^2 entries; adjacency lists have n nodes where n = number of edges (directed) =
  2 * number of edge (undirected)--the latter often requires less storage than an adjacency matrix, especially when
  a graph is sparse
~ 
*/

int main() {
    return 0;
}