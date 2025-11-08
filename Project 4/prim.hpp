/*
 * CSC-301
 * prim.hpp
 * Fall 2025
 *
 * Partner 1: Alexa Hatcher
 * Partner 2: Medhashree Adhikari
 * Date: November 21, 2025
 */

#ifndef PRIM_HPP_
#define PRIM_HPP_

#include "Vertex.hpp"
#include "Edge.hpp"

/*
 * getMin
 */
int getMin(std::vector<double> &cost, std::vector<bool> &visited);

/*
 * isEmpty
 */
bool isEmpty(std::vector<bool> &visited);

/*
 * prim
 */
std::vector<Edge> prim(std::vector<Vertex> &adjList, 
                       std::vector<double> &adjMat);

#endif  // PRIM_HPP_