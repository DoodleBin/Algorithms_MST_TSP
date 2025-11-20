/*
 * CSC-301
 * kruskal.cpp
 * Fall 2025
 *
 * Partner 1: Alexa Hatcher
 * Partner 2: Medhashree Adhikari
 * Date: November 21, 2025
 */

#include "kruskal.hpp"

using namespace std;

/**
 * find
 * Input:
 *      int v: vertex label
 *      vector<int> &pi: vector of pointers to parents
 * Output: 
 *      int: root of the set the given vertex belongs to
 * Function:
 *      given the vertex we check the vectopr pi to find where it is
 *      returns root of the set the given vertex belongs to
 */
int find(int v, vector<int> &pi) {
    int root = v;
    while(pi[root] != root) {
        root = pi[root];
    } // while v doesn't point to itself, point to the parent

    int curr = v;
    while(pi[curr] != curr) {
        int temp = pi[curr];
        pi[curr] = root;
        curr = temp;
    } // repoint pointer 

    return root;
}

/**
 * union_by_rank
 * Input:
 *      int u: vertex label
 *      int v: vertex label
 *      vector<int> &rank: rank vector
 *      vector<int> &pi: vector of pointers to parents
 * Output: n/a
 * Function:
 *      finds two roots, unionizes based on height of trees
 */
void union_by_rank(int u, int v, vector<int> &rank, vector<int> &pi) {
    int root1 = find(u, pi);
    int root2 = find(v, pi);

    //connect both roots
    if(rank[root1] == rank[root2]) {
        // make root2 point root1 root
        pi[root1] = root2;
        rank[root2] += 1;
    } else if(rank[root1] > rank[root2]) {
        // make root2 point at root1 root
        pi[root2] = root1;
    } else if(rank[root1] < rank[root2]) {
        // make root1 point at root2 root
        pi[root1] = root2;
    }

    return;
}

/**
 * kruskal
 * Input:
 *      vector<Vertex> &adjList: vector of vertices
 *      vector<Edge> &edgeList: vector of edges
 * Output:
 *      vector<Edge>: vector of edges
 * Function:
 *      finds the minimum spanning tree
 */
vector<Edge> kruskal(vector<Vertex> &adjList, vector<Edge> &edgeList)
{
    // Initialize the empty MST.
    vector<Edge> mst;

    // For each vertex, we need rank values and pi pointers (ints) for the
    // Disjoint Sets. Initialize the rank to 0 and pi to be the vertex labels.
    int n = adjList.size();
    vector<int> rank(n, 0);
    vector<int> pi(n);

    for(int i = 0; i < pi.size(); i++) {
        pi[i] = i;
    } // init pi pointers (points to itself)

    for (Edge e : edgeList) {
        // given that two vertices don't have same root
        if(find(e.first.label, pi) != find(e.second.label, pi)) {
            // repoint the two labels
            union_by_rank(e.first.label, e.second.label, rank, pi);
            // connect as neighbors on mstNeighbors
            adjList[e.first.label].mstNeighbors.push_back(e.second.label);
            adjList[e.second.label].mstNeighbors.push_back(e.first.label);

            mst.push_back(e); // place on mst
        }
    } // for all edges

    return mst;
}