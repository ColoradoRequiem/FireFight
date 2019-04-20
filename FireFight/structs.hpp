#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include <vector>
#include <iostream>

struct Edge
{
    vertex *v;
    bool access; // will or will not let player pass
};

struct Impediment
{
  vector<Tool> solve; // player will need a copy of said tool to remove impediment
  int time; // time it takes to get rid of the Impediment
  std::vector<Tool> objects; // need to make Tool
  vector<Impediment> obsticles; // will change the "access" of 'Edges'
};

/*this is the struct for each vertex in the graph. */
struct room
{
    std::string description;
    bool visited; // not sure if we need this
    std::vector<Edge> Edges; //stores edges to adjacent vertices

};

class Graph
{
  public:
    Graph();
    ~Graph();
    void addVertex(std::string cityName);
    void addEdge(std::string city1, std::string city2, int distance);
    void displayEdges();
    void printDFT();
    void printBFT();
    void setAllVerticesUnvisited();

  private:
    std::vector<vertex> vertices; //stores vertices

    vertex *findVertex(std::string name);
    void BFT_traversal(vertex *v);
    void DFT_traversal(vertex *v);

};

#endif // GRAPH_HPP
