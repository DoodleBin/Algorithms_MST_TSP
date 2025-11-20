/*
 * CSC-301
 * tsp.hpp
 * Fall 2025
 *
 * Partner 1: Alexa Hatcher
 * Partner 2: Medhashree Adhikari
 * Date: November 21, 2025
 * Acknowledgements: Professor Eric Autry
 */

#ifndef TSP_HPP_
#define TSP_HPP_

#include <stack>

#include "Vertex.hpp"

/*
 * tsp
 */
std::vector<int> tsp(std::vector<Vertex> &adjList, Vertex &start);

#endif  // TSP_HPP_