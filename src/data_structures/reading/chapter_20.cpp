using namespace std;

/*
Vocabulary
==========
* Graph (G) - two sets {V, E}, made up of vertices (or nodes) and unique edges that connect them 
* Subgraph - two subsets, made up of a graph's verticies and their edges
* Adjacency - the linking of two vertices in a graph by an edge
* Path - a sequence of edges that begins at one vertex and ends at another vertex
* Simple path - a path that passes through each vertex once
* Cycle - a path that begins and ends at the same vertex
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
* Graph traversal algorithm - a traversal procedure that visits all the vertices for which there is a path connected
  to a given vertex or all vertices for a connected graph
* Connected component - the subset of traversed vertices for a given starting vertex with the graph-traversal
  algorithm, including the starting vertex
* Depth-first search (DFS) - a graph-traversal strategy that goes deeply into the graph as possible from a vertex
  before backing up, visiting adjacent, unvisited vertices after visiting a vertex
* Breadth-first search (BFS) - a graph-traversal strategy that visits every adjacent vertex from a given vertex
  before visiting other vertices, implemented using a queue
* Topological order - the linear order of vertices in a directed graph without cycles, where vertex x precedes vertex
  y if there exists a directed edge from x to y in a graph
* Topological sorting - arrangement of vertices in topological order
* Spanning tree - a subgraph of a connected undirected graph G that contains all of G's vertices and enough of its
  edges to form a tree
* Depth-first search (DFS) spanning tree - a spanning tree generated from a connected undirected graph by traversing
  vertices with a DFS, marking the followed edges
* Breadth-first search (BFS) spanning tree - a spanning tree generated from a connected undirected graph by traversing
  vertices with a BFS, marking the followed edges
* Spanning tree cost - the sum of costs associated with the edges in a spanning tree
* Minimum spanning tree - spanning trees for which the spanning tree cost is minimal
* Prim's algorithm - a procedure that determines the minimum spanning tree beginning at any given vertex by
  iteratively selecting a least-cost edge from the edges starting at a tree's vertex and ending with a vetex outside
  the tree, adding the latter vertex and the least-cost edge to the tree
* (Weighted graph) shortest path - the path that has the smallest sum of its edge weights
* Length (or weight or cost) - the sum of the weights of the edges of a path in a weighted graph
* Circuit - another name for a type of cycle; usually, circuits either visit every vertex once or visit every edge
  once
* Euler circuit - an undirected connected graph path that begins at a given vertex, passes through every edge in the
  graph exactly once and terminates at the starting vertex; it exists if an only if each vertex touches an even number
  of edges on the graph
* Hamilton circuit - a graph path that begins at a given vertex, passes through every vertex exactly once, and terminates
  at the starting vertex; the traveling salesperson problem is a well-known variation
* Planar graph - a graph that can be represented in a plane without any crossing edges

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
~ All the connected components of a graph can be determined by repeatedly starting a traversal at an unvisited
  index
~ If a graph contains a cycle, a graph-traversal algorithm can loop indefinitely unless each visited vertex is
  marked during traversal and no vertex is visited visited more than once
~ The DFS algorithm does not completely specify the order which adjacent vertices should be visited; one possibility
  is to visit in sorted (i.e. alphabetical, ascending, etc) order
~ The vertex from which a DFS traversal embarks is the vertex that it visited most recently, implementing a last
  visited, first explored strategy with a vertex stack
~ If the vertices of a directed graph are arranted linearly in topological order, the edges will all point in one
  direction
~ Topological sorting algorithms:
  a) Iterative removal of vertices with no successor and the edges leading to them, adding them to a list of
     vertices until the graph is empty
  b) Iterative pushing of vertices without a predecessor onto a stack, then popping each vertex and adding it to a
     list of vertices
~ A tree is a special kind of undirected graph--one that is connected but has no cycles; all trees are graphs, but
  not all graphs are trees, where the nodes (vertices) of a tree have a hierarchical arrangement not required of all
  graphs
~ If edges are removed from a connected undirected graph with cycles until there are no more cycles, the result is
  that graph's spanning tree
~ Cycle detection:
  a) A connected undirected graph with n vertices must have at least n-1 edges
  b) n-1 edges: cannot contain a cycle
  c) more than n-1 edges: contains at least 1 cycle
~ The Dijkstra algorithm finds the shortest paths between a given origin and all other vertices by using a set of
  selected vertices, an array with the weights of the single-edge paths from vertex 0 to all the other vertices,
  and an adjacency matrix where the arrays are rows in the matrix
~ Identifying a Hamilton circuit in a graph can be difficult; the traveling salesman problem has worst-case
  efficiency O(n!) when checking every round-trip path--real-world applications approximate the solution
*/

int main() {
    return 0;
}