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
  string used; // a string to say "the fire extriguisher blows out foam and covers the fire" a generic statement that can be said in any room.
  bool used; // more for singular stuff like a distress signal if we choose to do that; can be removed if you want
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
    string type; // this will be referenced if its a door or hole or something
};

struct Impediment
{
  string description; // becuase included in room, this will display have the description of the room
  std::vector<Tool> solve; // will check to see if player has a copy of said tool to remove impediment
  std::vector<Person> solve2; // in case we want to have say the engineer needed to fix the engine. can get rid of if you want
  int time; // time it takes to get rid of the Impediment
};


struct Room
{
  string name;
  std::string description;
  bool visited; // not sure if we need this
  std::vector<Edge> Edges; //stores edges to adjacent vertices
  std::vector<Impediment> obsticles; // will change the "access" of certain 'Edges' at their address'
  std::vector<Tool> objects; // what can be found in the room
  std::vector<Person> occupied;
};

class Ship // Graph
{
  public:
    Ship(); // will be our classic loadup
    ~Ship();
    void addVertex(std::string cityName);
    void addEdge(std::string city1, std::string city2, int distance);
    void displayEdges(); // would be cool if we had a map to show user on each level, just a thought
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
