# KL-Algorithm
Implementation of Kernighan–Lin algorithm to divide the graph into k partitions.

# Explanation 
The edges are stored in a map with edge(u, v) and weight(w) as key value pair. Initially N and K are the total nodes and expected partitions respectively.
1. N nodes are divided into 2 partitions of sizes N/K and N - N/K. 
2. D value is calculated for each node.
3. Further steps of KL algorithm are performed, which tells the nodes that need to be swapped in-order to get min edges across those 2 partitions. 
4. In this step the swaps take place (if any).
5. If max value of g found is less than or equal to 0 ie. no swap has taken place, then go to step 2.
6. The nodes of partition with size N/K are locked. They will not be considered further. Only their effect will be considered.
7. Change N to N - (N/K) and K to K - 1. If K is 1 it means we have obtained all partitions and break. Otherwise, go to step 1.

# Steps to run
1. Store the u and v of each edge in from.txt and to.txt, number of nodes in vertices.txt. If the graph is weighted then store the weights else store 1 corrosponding to each edge in weight.txt.
2. Change the path of all .txt files in buildEdgeSet method in Graph.cpp

# Sample Run
Input Graph             |  Output Graph
:-----------------------------:|:-------------------------:
![1](https://user-images.githubusercontent.com/22634590/36088073-9bb9655a-0ffb-11e8-8a0f-9cb5d24ea81d.GIF)   | ![2](https://user-images.githubusercontent.com/22634590/36088109-bcb6f1b4-0ffb-11e8-9b00-b6165159d17f.GIF)

