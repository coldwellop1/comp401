#Bipartite Graphs

#### Questions to think about:
  * How would we represent a graph as a data structure?
  * What are some uses of bipartite graphs?

#### Basic Information:
**What is a graph?**
> A graph is a collection of nodes and edges that show the relationship between
> objects in a given set.  Each node is labeled to show which object it represents,
> and each edge connects (a) two nodes to each other or (b) one node to itself.

> ![Image cannot load. See ab.png.](prep/ab.png)

> There are two different kinds of edges:

>   1. **Undirected Edge** - an undirected edge is used to connect two nodes 
>      together, and is shown as a line between the two nodes, as seen above.
>   2. **Directed Edge** - a directed edge is used to connect two nodes together
>      *in one direction*.  A directed edge is shown as an arrow coming out of
>      one node and pointing at the second.  Example c below shows a directed 
>      edge from Node 4 to Node 5.  A directed edge is similar to a one way road.
>      In the example below, this means we can get from Node 4 to Node 5, but not
>      from Node 5 to Node 4.

> ![Immage cannot load. See c.png.](prep/c.png)

**What makes a graph 'bipartite'?**

#### Exercises:

  1. Use the given ordered pairs to connect the graph:

	![Image cannot load. See ex_1.png.](prep/ex_1.png)

  2. Is the above graph bipartite?
  3. Looking at the set of ordered pairs you have been given, is this a directed or undirected graph?



-------------------------------------------
#### Exercise Answers: 

  1. ![Image cannot load. See ans_1.png.](prep/ans_1.png)
  2. No, d connects to both b and g, which means we cannot split the nodes into two groups where no nodes of the same group share an edge.  Similarly, a and b are connected and a is connected to e and f as well.
  3. We cannot fully tell unless it is stated, but this appears to be an undirected graph because a directed graph would need both (a, b) and (b, a) in order to connect a and b fully.
