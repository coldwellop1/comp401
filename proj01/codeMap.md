## Class: biGraph
      members:
        value held by vertex (name of vertex)
        color of vertex
        array of edges (since a vertex on a bipartite graph can have any number of edges)
        
### Create graph
  - insert vertex
  - determine if graph is bipartite graph
  - loop until user requests to end creation
  
### Import graph
_Document format requirements for importing graph:_ the first line of the text file must contain the values/names of each vertex to be assigned to the graph with one space between each value, each following line must contain __one and only one__ ordered pair of vertices to represent an edge.  For example: 
      A B C D E F G H I
      A G
      A H
      B I
      D F
      C H
      E F
      G E
      C I

The above file would create the following graph

_A_ ----- G ----- _E_ ----- F ----- _D_

|                  
H ----- _C_ ----- I ----- _B_
      
      
  - import data set from .txt file
  - create a vertex from each peice of data imported
  - connect vertices according to data
  - determine if graph is bipartite.
  
### Add vertex
  - create a new vertex
  - create edges to connect vertex to other vertices
    - go to other vertices and record edges
  - determine if graph is bipartite
  