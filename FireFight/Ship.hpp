#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include <iostream>


// Game Struct Definitions
struct Room;
struct Impediment;

struct Edge
{
  Room *v;
  std::string description;
  //bool access; // will or will not let player pass
  std::vector<Impediment> obsticles; // will change the "access" of certain 'Edges'
};

struct Tool
{
  int weight;
  std::string name;
};

struct Room
    {
      std::string name;
      std::string description;
      bool visited; // not sure if we need this
      std::vector<Edge> Edges; //stores edges to adjacent vertices
      std::vector<Tool> objects; // what can be found in the room
    };

struct Impediment
    {
      std::string description; // becauase included in room, this will display have the description of the room
      std::string fail;
      std::string success;
      std::string tool; // will check to see if player has a copy of said tool to remove impediment
      bool active;
      Edge *e;
    };




class Ship
{
public:

  Ship();
  ~Ship();

  void addRoom(std::string name, std::string description);
  void addEdge(std::string room1, std::string room2, std::string description);

  void addObsticle(std::string description, std::string tool, std::string fail, std::string success, std::string room1, std::string room2);
  void removeObsticle(std::string room1, std::string room2);

  void addTool(std::string n, int w, std::string room);

  // Plays with UI

  std::string searchRoom();
  std::string buttonValue(int b); // Returns button Text
  std::string roomDescription(); // Returns Room description text

  std::string canEnter(int n); // Returns if selected room can be entered
  void moveRoom(int n); //Changes room based on option selected

  void reset(); // Resets inventory and location


private:
  std::vector<Room> map; //stores vertices (room)
  std::vector<Tool> bag;

  Room location; // Stores your current location (starts at Cockpit)

  Room *findVertex(std::string name);
  Edge *findEdge(std::string room1, std::string room2);



};

#endif // SHIP_H
