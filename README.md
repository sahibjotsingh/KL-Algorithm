# KL-Algorithm
Implementation of Kernighan–Lin algorithm to divide the graph into k partitions.

# Explanation 
Store the edges in a map with edge(u, v) and weight(w) as key value pair. Initially N and K are the total nodes and expected partitions respectively.
1. Randomly divide N nodes into 2 partitions of sizes N/K AND N - N/K. Also, D value is calculated for each node.
2. Further steps of KL algorithm are performed, which tells the nodes that need to be swapped in-order to get min edges across those 2 partitions. 
3. In this step the swaps take place (if any).
4. D values are updated.
5. The nodes of partition with size N/K are locked. They will not be considered further. Only their effect will be considered.
6. Change N to N - (N/K) and K to K - 1. If K is 1 it means we have obtained all partitions and break. Otherwise, go to step 1.

