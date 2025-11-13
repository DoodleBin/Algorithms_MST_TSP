/*
 * CSC-301
 * prim.cpp
 * Fall 2025
 *
 * Partner 1: Alexa Hatcher
 * Partner 2: Medhashree Adhikari
 * Date: November 21, 2025
 */

#include "prim.hpp"

using namespace std;

/*
 * getMin
 * Input:
 *      vector<double> &cost: vector of double cost values
 *      vector<bool> &visited: vector of booleans indicating visited status
 * Output: 
 *      int: minimum cost value
 * Function: Performs a linear search to find vertex with the minimum cost.
 */
int getMin(vector<double> &cost, vector<bool> &visited) {
    int sz = visited.size(); // get size
    double curr_min = 1.0/0.0; // init to infinity
    // track index
    int min_index = -1;

    for(int i = 0; i < sz; i++) {
        if(visited[i] == false) {
            if(cost[i] < curr_min) {
                curr_min = cost[i];
                min_index = i;
            } // is less than check
        } // if not visited check
    } // loop

    return min_index;
}

/*
 * isEmpty
 * Input:
 *      vector<bool> &visited: vector of booleans indicating visited status
 * Output:
 *      bool: returns a true or false
 * Function: Finds if the vector of visited are empty or not
 */
bool isEmpty(vector<bool> &visited) {
    int sz = visited.size(); // get size

    for(int i = 0; i < sz; i++) {
        if(visited[i] == false) {
            return false;
        } // if any false, return
    } // loop to find if vector empty

    return true;
}

/*
 * prim
 * Input:
 *      vector<Vertex> &adjList: Vector of the vertices
 *      vector<double> &adjMat: Vector of edge costs
 * Output:
 *      vector<Edge>: A vector of edes in the MST
 * Function: Finds the minimum path and returns vector
 */
vector<Edge> prim(vector<Vertex> &adjList, vector<double> &adjMat) {
    // Initialize the empty MST.
    vector<Edge> mst;
    
    // For each vertex, we need a visited flag, a 'cost' for Prim's, and the
    // prev values to track the MST. Store these in seperate vectors.
    int n = adjList.size();
    vector<bool> visited(n, false);
    vector<double> cost(n, numeric_limits<double>::infinity());
    vector<int> prev(n, -1);

    // Prim's alg
    cost[0] = 0; // vertex w label 0

    while(not isEmpty(visited)){
        int current = getMin(cost, visited);
        visited[current] = true;

        for (int i : adjList[current].neighbors){
            if (visited[i] == false){
                if (cost[i] > adjMat[current*n + i]) {
                    cost[i] = adjMat[current*n + i];
                    prev[i] = current;
                }
            }
        }
        // update curr mst neighbors, prev neighbors
    } // while stack not empty

    // loop through
    for(int current = 1; current < n; current++) {
        adjList[current].mstNeighbors.push_back(prev[current]); // label of neighbor
        adjList[prev[current]].mstNeighbors.push_back(current); // label of neighbor
        Edge newEdge(adjList[current], adjList[prev[current]], adjMat[prev[current]*n + current]);
        mst.push_back(newEdge);
    }

    return mst;
}