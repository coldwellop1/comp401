## Initial data found on bipartite graphs
- A bipartite graph, also called a bigraph, is a set of graph vertices decomposed into two disjoint sets such that no two graph vertices within the same set are adjacent. A bipartite graph is a special case of a k-partite graph with k=2. The illustration above shows some bipartite graphs, with vertices in each graph colored based on to which of the two disjoint sets they belong. (Weisstein, Eric W. "Bipartite Graph." From MathWorld--A Wolfram Web Resource. http://mathworld.wolfram.com/BipartiteGraph.html)

- A graph can be defined as a bipartite graph so long as the set of vertices can be colored using two different colors such that there are no two adjacent vertices that have the same color.  Each of these colors then represents a set of data. (my summary of above)

- A _complete bipartite graph_ is a graph G whose vertex set V can be partitioned into two non empty sets V1 and V2 in such a way that every vertex in V1 is adjacent to every vertex in V2, no vertex in V1 is adjacent to a vertex in V1, and no vertex in V2 is adjacent to a vertex in V2. If V1 has r vertices and V2 has s vertices then the complete bipartite graph is written as Kr, s .

## Coding Bipartite Graphs
- Following is a simple algorithm to find out whether a given graph is Birpartite or not using Breadth First Search (BFS).
  1.	Assign RED color to the source vertex (putting into set U).
  2.	Color all the neighbors with BLUE color (putting into set V).
  3.	Color all neighbor’s neighbor with RED color (putting into set U).
  4.	This way, assign color to all vertices such that it satisfies all the constraints of m way coloring problem where m = 2.
  5. While assigning colors, if we find a neighbor which is colored with same color as current vertex, then the graph cannot be colored with 2 vertices (or graph is not Bipartite)
  (http://www.geeksforgeeks.org/bipartite-graph/)
