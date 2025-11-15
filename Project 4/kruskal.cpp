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

/*
 * find
 * given the vertex we check the vectopr pi to find where it is
 * returns the index of the set that v belongs to
 */
int find(int v, vector<int> &pi)
{
    int sz = pi.size();// get size
    for (int i = 0; i < sz; i++)
    {
        if (pi[i] == v)
        {
            return i;
        }
    }
    return -1; //if its not in pi
}

/*
 * union_by_rank
 */
void union_by_rank(int u, int v, vector<int> &rank, vector<int> &pi)
{
    // int root1 = find(u, pi);
    // int root2 = find(v, pi);
    // if()
    //  //connect both roots

    return;
}

/*
 * kruskal
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
    // for (int i = 0; i < pi.size(); i++)
    // {
    //     pi[i] = i;
    // }

    return mst;
}