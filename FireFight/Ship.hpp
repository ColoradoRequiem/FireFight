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
  string use; // a string to say "the fire extriguisher blows out foam and covers the fire" a generic statement that can be said in any room.
  bool used; // more for singular stuff like a distress signal if we choose to do that; can be removed if you want
};

struct Edge
{
  vertex *v;
  bool access; // will or will not let player pass
};

struct Impediment
{
  string description; // becuase included in room, this will display have the description of the room
  std::string tool; // will check to see if player has a copy of said tool to remove impediment
  int time; // time it takes to get rid of the Impediment
  bool active;
  Edge *e;
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

class Player
{
public:
  void moveRoom();

  void addItem();
  void dropItem();
private:
  std::vector<Tool> bag;
  int maxWeight;
  string name;
  int health;
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
    void addEdge(std::string room1, std::string room2); // some are only one way and some wont be

    void addObsticle(std::string description, std::string tool, int time, std::string room1, std::string room2); // will be simialr to addEdge i think
    void removeObsticle(std::string room1, std::string room2);

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
