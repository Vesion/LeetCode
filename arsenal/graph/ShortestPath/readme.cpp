//
// In the  Single-Source Shortest Paths (SSSP) problem, we aim to find the shortest paths from a source vertex.
// Generally, there are 5 kinds of algortithms which solve different problem variants repectively.
//
// 1. Bellman Ford's algorithm, O(VE)
//      Can solve: all kinds of valid SSSP problem variants, but with a rather slow running time.
//      Can be used to detect if the graph contains at least one `negative weight cycle` reachable from the source vertex.
//
// 1.1 SPFA (Shortest Path Faster Algorithm), O(kE)
//      Maintain a queue to record nodes has been relaxed
//      More suitable for 'edges-sparse-graph'
//
// 2. Dijkstra's algorithm, O(V^2) --> O((V+E)logV)
//      Can only solve: directed weighted graph that has no negative weight edge at all.
//      More suitable for 'edges-dense-graph'
//
// 3. BFS, O(V+E)
//      Can only solve: graph is unweighted (all edges have unit weight 1) or constant weighted (all edges have the same constant weight).
//
// 4. DFS, O(V+E)
//      Can only solve: graph is a tree thus any path that connects the source vertex to another vertex is the shortest path.
//
// 5. DP, O(V+E)
//      Can solve two problems : 
//          DAG : When graph is a Directed Acyclic Graph (DAG) thus we can find at least one topological order of the DAG and do relaxation in order.
//          APSP (All-Pairs Shortest Paths)
//
//
