## Class: biGraph
      members:
        * ~~array of vertices~~
        * ~~array of edges~~
        * number of vertices (n)
        * 
        
        
### Create graph
  - insert vertices
  - insert edges (determine if graph is bipartite before officially inserting each edge.)
      - edges will be bidirectional!
  
### Import graph
_Document format requirements for importing graph:_ the first line of the text file must contain the values/names of each vertex to be assigned to the graph with one space between each value, each following line must contain __one and only one__ ordered pair of vertices to represent an edge.  For example: 
      A B C D E F G H J  
      A G  
      A H  
      B J  
      D F  
      C H  
      E F  
      G E  
      C J  

The above file would create the following graph

_A_ ----- G ----- _E_ ----- F ----- _D_  
 I  
 I                  
H ----- _C_ ----- J ----- _B_
      
      
  - import data set from .txt file
  - create a vertex from each peice of data imported
  - connect vertices according to data
  - determine if graph is bipartite.
  - export data set to .txt file
  
### Add vertex
  - create a new vertex
  - create edges to connect vertex to other vertices
    - go to other vertices and record edges
  - determine if graph is bipartite
  
