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

// item check function in room

struct Tool
{
  int weight;
  string name;
};

struct Edge
{
  vertex *v;
  string description;
  bool access; // will or will not let player pass
  std::vector<Impediment> obsticles; // will change the "access" of certain 'Edges'
};

struct Impediment
{
  string description; // becuase included in room, this will display have the description of the room
  string fail;
  string success;
  std::string tool; // will check to see if player has a copy of said tool to remove impediment
  bool active;
  Edge *e;
};


struct Room
{
  string name;
  std::string description;
  bool visited; // not sure if we need this
  std::vector<Edge> Edges; //stores edges to adjacent vertices
  std::vector<Tool> objects; // what can be found in the room
  std::vector<Person> occupied;
};

struct Player
{
  std::vector<Tool> bag;
};

class Ship // Graph
{
  public:

    //// Ship SETUP ////

    /*
    since during the game we will be changing things about the rooms and their coniditions
    it should be okay to make the ship in main too vs a  constructor, this is like
    in our past assignments
    */

    Ship();
    ~Ship();

    void addRoom(std::string name, std::string description);
    void addEdge(std::string room1, std::string room2, std::string description); // some are only one way and some wont be

    void addObsticle(std::string description, std::string tool, std::string fail, std::string success, std::string room1, std::string room2); // will be simialr to addEdge i think
    void removeObsticle(std::string room1, std::string room2);

    void addTool(string name, string room);

    void displayEdges(); // would be cool if we had a map to show user on each level, just a thought
    void printDFT();
    void printBFT();
    void setAllVerticesUnvisited();

  private:
    std::vector<vertex> vertices; //stores vertices

    Room *findVertex(std::string name);
    Edge *findEdge(string room1, string room2)
    void BFT_traversal(vertex *v);
    void DFT_traversal(vertex *v);

};

#endif // GRAPH_HPP
