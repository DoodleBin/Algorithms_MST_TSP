/*
 * CSC-301
 * tsp.cpp
 * Fall 2025
 *
 * Partner 1: Alexa Hatcher
 * Partner 2: Medhashree Adhikari
 * Date: November 21, 2025
 */

#include "tsp.hpp"

using namespace std;

/**
 * tsp
 * Input:
 *      vector<Vertex> &adjList: vector of vertices
 *      Vertex &start: the starting vertex
 * Output:
 *      vector<int>: vector of integers 
 * Function:
 *      finds the shortest route 
 */
vector<int> tsp(vector<Vertex> &adjList, Vertex &start) {
    // Create the empty tour.
    vector<int> tour;

    // Create the vector for tracking visited during the DFS.
    int n = adjList.size();
    vector<bool> visited(n, false);

    // visit start and push to stack
    stack<int> s;
    visited[start.label] = true;
    s.push(start.label);

    while(not s.empty()) {
        int curr = s.top();
        s.pop();
        visited[curr] = true; // marking current stop as visited
        tour.push_back(curr); // since visited, put on tour

        for(int i = 0; i < adjList[curr].mstNeighbors.size(); i++){
            if(not visited[adjList[curr].mstNeighbors[i]]) {
                s.push(adjList[curr].mstNeighbors[i]);
            } // for the current vertex in mst, push value
        } // loop through curr mst neighbors
    } // while things to check

    tour.push_back(start.label); // last stop, cyclical
    return tour;
}