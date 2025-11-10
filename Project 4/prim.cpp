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

    for(int i = 0; i < sz; i++) {
        if(visited[i] == false) {
            if(cost[i] < curr_min) {
                curr_min = cost[i];
            } // is less than check
            visited[i] = true;
        } // if not visited check
    } // loop

    return curr_min;
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
    queue<int> q;
    q.push(adjList[0].label);

    while(!q.empty()){
        int current = q.front();
        q.pop();
        visited[current] = true;
        for (int i : adjList[current].neighbors){
            if (visited[adjList[i].label] == false){
                if (adjMat[i] > cost[adjList[current].label]){
                    cost[adjList[i].label] = cost[adjList[current].label];
                    prev[adjList[i].label] = adjList[current].label;
                    q.push(i);
                }
                visited[adjList[i].label] = true;
            }
            Edge newEdge(adjList[prev[adjList[current].label]], adjList[current], adjMat[current*n + i]);
            mst.push_back(newEdge);
        }
    }
    

    return mst;
}