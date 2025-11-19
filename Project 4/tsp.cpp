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

/*
 * tsp
 */
vector<int> tsp(vector<Vertex> &adjList, Vertex &start) {
    // Create the empty tour.
    vector<int> tour;

    // Create the vector for tracking visited during the DFS.
    int n = adjList.size();
    vector<bool> visited(n, false);

    // int current = start.label;
    // visited[current] = true;
    // tour.push_back(current);
    // int current = start.label;
    visited[start.label] = true;
    tour.push_back(start.label);

    for(int j = 1; j < n; j++){
        visited[j] = true;

        for (int i : adjList[j].neighbors){
            if (visited[i] == false){
                tour.push_back(i);
            } // visit all unvisited neighbors
        }
    }

    return tour;
}