#include "Ship.hpp"

#include <iostream>
#include <vector>


using namespace std;


Ship::Ship() // we could do this in the main, but i want the main to be the game, so ship will be defined here
{
  // Cockpit floor
  addRoom("Cockpit", "The Cockpit has a huge crack across the windsheild that you can hear air slowly leaking out of. Their is a guidence system and two chairs set up to steer the ship.");
  addRoom("Hall", "A hallway leading from the cockpit to a steel grey elevator. There is a door to one side and a hatch leading into the ground on the other.");
  addRoom("BedroomOne", "A Bedroom that looks in complete dissarray from the crash. You could find anything in this random mix of odds and ends. There is a bed in one corner flipped against the wall, and cracked lamp lying on the floor.");
  addRoom("Storage", "This room looks like it was made to hold food for long trips through space. Lots of canned food is seen rolling around the floor along with bags of flour and barley in stacks in the courner of the room.");
  addRoom("Elevator", "A steel grey elevator that looks old but reliable. There are two buttons to go either up or down.");

  addEdge("Cockpit","Hall");
  addEdge("Hall","Cockpit");
  addEdge("Hall","BedroomOne");
  addEdge("BedroomOne","Hall");
  addEdge("Hall","Storage");
  addEdge("Storage","Hall");
  addEdge("Hall","Elevator");
  addEdge("Elevator","Hall");

  // Bottom floor

  addRoom("ElevatorB", "A steel grey elevator that looks old but reliable. There are two buttons to go either up or down.");
  addRoom("Hold", "A large open space that looks to hold most of the cargo in the ship. There are two large bay doors off to the left that seem to be the main point of entry as well as a heavy metal door straight across with a red gleam underneeth and a second smaller door that faces the bay doors.");
  addRoom("Engine","A boiling hot room where a massive engine resides that powers the whole ship, you can hear all kinds of noises coming from it and feel the heat singing your eyebrows.");

  addEdge("Elevator","ElevatorB");
  addEdge("ElevatorB","Elevator");
  addEdge("ElevatorB","Hold");
  addEdge("Hold","ElevatorB");
  addEdge("Hold","Engine");
  addEdge("Engine","Hold");
  addEdge("Hold","BedroomTwo");
  addEdge("BedroomTwo","Hold");

  // Top floor

  addRoom("ElevatorT","A steel grey elevator that looks old but reliable. There are two buttons to go either up or down.");
  addRoom("Overlook","A giant sphere shaped dome made of heavy glass looking out into space. There is a heavy door with a latch and keypad on one side and smaller door on the other.");
  addRoom("Airlock","A tight room made for air pressurization. No windows, only a second small hatch in the side of the wall that opens into the deadness of space.");
  addRoom("Suits", "This room has a large dresser hanging upon which are 10 different space suits of varying sizes.");

  addEdge("Elevator", "ElevatorT");
  addEdge("ElevatorT", "Elevator");
  addEdge("Overlook","Airlock");
  addEdge("Airlock","Overlook");
  addEdge("Overlook","Suits");
  addEdge("Suits","Overlook");



}
Ship::~Ship()
{

}

void Ship::addRoom(string n, string d)
{
  Room* n = new Room;
  n->name = n;
  n->description = d;
  vertices.push_back(*n);
}

void Ship::addEdge(std::string room1, std::string room2)
{
  Room* rOne = findVertex(room1);
  Room* rTwo = findVertex(room2);

  Edge* n = new Edge;
  n->v = rTwo;
  n->access = true;
  rOne->Edges.push_back(*n);
}

Room* Ship::findVertex(std::string name)
{
  for (int i = 0; i < vertices.size(); i++)
  {
    if (vertices[i].name == name)
    {
      return &(vertices[i]);
    }
  }
  return nullptr;
}

Edge* Ship::findEdge(string room1, string room2)
{
  for (int i = 0; i < vertices.size(); i++)
  {
    if (vertices[i].name == room1)
    {
      for (int j = 0; j < (vertices[i]->Edges).length()); j++)
      {
        if (vertices[i]->Edges[j]->v->name == room2)
        {
          return (vertices[i]->Edges[j]);
        }
      }
    }
  }
  return nullptr;
}

void Ship::addObsticle(string d, string t, int time, string room1, string room2)
{
  Impediment new;
  new->description = d;
  new->tool = t;
  new->time = time;
  new->active = true;

  (findEdge(room1, room2))->access = false;
  new->e = findEdge(room1, room2);


  Room* rOne = findVertex(room1);
  Room* rTwo = findVertex(room2);

  rOne->obsticles.push_back(new);
}

void Ship::removeObsticle(string room1, string room2)
{
  Room* rOne = findVertex(room1);
  for (int i = 0; i < (rOne->obsticles).length(); i++)
  {
    if (rOne->obsticles[i]->e->v->n == room2)
    {
      rOne->obsticles[i]->e->access = true;
      rOne->obsticles[i]->active = false;
    }
  }
}

void Ship::addTool(string name)
{

}
