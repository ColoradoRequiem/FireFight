#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include <vector>
#include <iostream>

/*
Im going to make all these structs and maps and create a new file where i define all the room
before i start including in chance for dying and how to traverse.
*/

/*
Also what if you dont know who you start off as?
like we set these people up randomly, theres like 3 people
and then you become one at random and have to save the ship
from a whole nother view. In either case the what kinda AI
do we want to give crew that are alive on the ship?
*/

struct Tool
{
  int weight;
  string name;
};

struct Person
{
  int health;
  string name;
  std::vector<Tool> bag; // what can be found on the person
  int maxWeight;
};

struct Edge
{
    vertex *v;
    bool access; // will or will not let player pass
};

struct Impediment
{
  string description; // becuase included in room, this will display have the description of the room
  std::vector<Tool> solve; // will check to see if player has a copy of said tool to remove impediment
  int time; // time it takes to get rid of the Impediment
};



/*this is the struct for each vertex in the graph. */
struct Room
{
    std::string description;
    bool visited; // not sure if we need this
    std::vector<Edge> Edges; //stores edges to adjacent vertices
    std::vector<Impediment> obsticles; // will change the "access" of certain 'Edges' at their address'
    std::vector<Tool> objects; // what can be found in the room
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
