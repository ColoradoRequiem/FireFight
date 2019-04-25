#include <vector>
#include <iostream>

#include "Ship.hpp"

using namespace std;

Ship::Ship() // we could do this in the main, but i want the main to be the game, so ship will be defined here
{
  // Starting floor
  addRoom("Cockpit", "The Cockpit has a huge crack across the windsheild that you can hear air slowly leaking out of. Their is a guidence system and two chairs set up to steer the ship. Behind you there are two heavy steel doors leading to the rest of the ship.");
  addRoom("Hall", "A hallway leading from the cockpit to a steel grey elevator. There is a door to one side and a hatch leading into the ground on the other.");
  addRoom("BedroomOne", "A Bedroom that looks in complete dissarray from the crash. You could find anything in this random mix of odds and ends. There is a bed in one corner flipped against the wall, and cracked lamp lying on the floor.");
  addRoom("Storage", "You climb down a ladder and reach a room that looks like it was made to hold food for long trips through space. Lots of canned food is seen rolling around the floor along with bags of flour and barley in stacks in the courner of the room.");
  addRoom("Elevator", "A steel grey elevator that looks old but reliable. There are two buttons to go either up or down.");

  // Bottom floor
  addRoom("ElevatorB", "A steel grey elevator that looks old but reliable. There is one button that goes up.");
  addRoom("Hold", "A large open space that looks to hold most of the cargo in the ship. There are two large bay doors off to the left that seem to be the main point of entry as well as a heavy metal door straight across with a red gleam underneeth and a second smaller door that faces the giant bay doors.");
  addRoom("Engine","A boiling hot room where a massive engine resides that powers the whole ship, you can hear all kinds of noises coming from it and feel the heat singing your eyebrows.");
  addRoom("BedroomTwo","A small room in shambles with all kinds of eingineering tools scattered around that have unknown uses.");

  // Top floor
  addRoom("ElevatorT","A steel grey elevator that looks old but reliable. There is one button that goes down.");
  addRoom("Overlook","A giant sphere shaped dome made of heavy glass looking out into space. There is a heavy aluminum door with a latch and keypad on one side and small white door on the other.");
  addRoom("Airlock","A tight room made for air pressurization. No windows, only a second small hatch in the side of the wall that opens into the deadness of space.");
  addRoom("Suits", "This room has a large dresser hanging upon which are 10 different space suits of varying sizes.");


  // Starting floor Edges
  addEdge("Cockpit","Hall","Open heavy steel doors to rest of ship.");
  addEdge("Hall","Cockpit","Open heavy steel doors to Cockpit");
  addEdge("Hall","BedroomOne","Open door");
  addEdge("BedroomOne","Hall","Go Back");
  addEdge("Hall","Storage","Open latch");
  addEdge("Storage","Hall","Climb back up");
  addEdge("Hall","Elevator","Enter Elevator");
  addEdge("Elevator","Hall","Exit Elevator");

  // Top floor Edges
  addEdge("Elevator","ElevatorB","Go Down");
  addEdge("ElevatorB","Elevator","Go Up");
  addEdge("ElevatorB","Hold","Exit Elevator");
  addEdge("Hold","ElevatorB","Enter Elevator");
  addEdge("Hold","Engine","Enter door with red gleam");
  addEdge("Engine","Hold","Return to Hold");
  addEdge("Hold","BedroomTwo","Enter smaller door");
  addEdge("BedroomTwo","Hold","Return to Hold");

  // Bottom floor Edges
  addEdge("Elevator","ElevatorT","Go Up"); // error
  addEdge("ElevatorT","Elevator","Go Down");
  addEdge("Overlook","Airlock","Try Keypad");
  addEdge("Airlock","Overlook","Go Back");
  addEdge("Overlook","Suits","Enter White Door");
  addEdge("Suits","Overlook","Go Back");

  // Adding tools to certain rooms
  addTool("Code", 0, "BedroomTwo");
  addTool("Crowbar", 5, "BedroomOne");
  addTool("Fire Extinguisher", 10, "Storage");

  // Adding Obsticles
  addObsticle("It feels like heavy boxes have fallen against the other side.", "Crowbar", "Your measly hands have no effect", "you successfully heave the door open and the boxes fall over.","Cockpit","Hall");
  addObsticle("As soon as you open the door flames billow out towards you.","Fire Extinguisher","You need equipment to put out the fire", "You successfully put the flames out with the Extinguisher","Hold","Engine");
  addObsticle("You need a code in order to open this door","Code","You dont know the code","You enter in the correct code","Overlook","Airlock");
  addObsticle("The latch appears to be stuck although could be opened if you had some leverage.","Crowbar","You dont have enough strength.","You manage to wrench it open.","Hall","Storage");

  location = *findVertex("BedroomOne");

  std::cout << "=====================================================================================" << std:: endl;
}
Ship::~Ship()
{
  for (int i = 0; i < (int)map.size(); i++)
  {
    std::cout << "Deleting " << map[i].name << " Edges: " << std:: endl;
    for (int j = 0; j < (int)map[i].Edges.size(); j++)
    {
      std::cout << " -> " << map[i].Edges[j].v->name << std::endl;
      Edge* del = findEdge(map[i].name, map[i].Edges[j].v->name);
      delete del;
    }
  }
  for (int i = (int)map.size() - 1; i >= 0; i--)
  {
    Room* del = findVertex(map[i].name);
    std::cout << "deleting room: " << map[i].name << std::endl;
    delete del;
  }
}

void Ship::addRoom(string n, string d)
{
  Room* r = new Room;
  r->name = n;
  r->description = d;
  map.push_back(*r);

 for(int i = 0; i < (int)map.size();i++){
     std::cout << map[(unsigned)i].name << " ";
 }
 std::cout << " <> End ROOMS" << std::endl;

}

void Ship::addEdge(std::string room1, std::string room2, std::string d)
{
  Room* rOne = findVertex(room1);
  Room* rTwo = findVertex(room2);

  Edge* n = new Edge;
  n->v = rTwo;
  n->description = d;
  // n->access = true;
//  vector<Impediment> temp;
//  n->obsticles = temp;

  rOne->Edges.push_back(*n);

  std::cout << rOne->name << " --> ";

  for(int i = 0; i < (int)rOne->Edges.size();i++){
      std::cout << rOne->Edges[(unsigned)i].v->name << " ";
  }

  std::cout << " <> End EDGE" << std::endl;
}

Room* Ship::findVertex(std::string name)
{
  for (int i = 0; i < (int)map.size(); i++)
  {
    if (map[(unsigned)i].name == name)
    {
      return &(map[(unsigned)i]);
    }
  }
  return nullptr;
}

Edge* Ship::findEdge(string room1, string room2)
{
  bool found = false;
  for (int i = 0; i < (int)map.size(); i++)
  {
    if (map[(unsigned)i].name == room1)
    {
      for (int j = 0; j < (int)(map[(unsigned)i].Edges.size()); j++)
      {
        if (map[(unsigned)i].Edges[(unsigned)j].v->name == room2)
        {
          found = true;
          return (&map[(unsigned)i].Edges[(unsigned)j]);
        }
      }
    }
  }
  if(!found){
      std::cout << "found nothing" << std::endl;
      return nullptr;
  }
}

void Ship::addObsticle(string d, string t, string f, string s, string room1, string room2)
{
  Impediment n;
  n.description = d;
  n.tool = t;
  n.fail = f;
  n.success = s;
  n.active = true;
  n.e = findEdge(room1, room2);
  //std::cout << n.e;

  //n.e->access = false; //?
  n.e->obsticles.push_back(n);
  std::cout << "Added obsticle from " << room1 << " -> " << n.e->v->name << std::endl;
}

void Ship::removeObsticle(string room1, string room2)
{
  Edge* e = findEdge(room1, room2);
  for (int i = 0; i < (int)(e->obsticles).size(); i++)
  {
    if (e->obsticles[(unsigned)i].e->v->name == room2)
    {
      //e->obsticles[(unsigned)i].e->access = true;
      e->obsticles[(unsigned)i].active = false;
    }
  }
}

void Ship::addTool(string n, int w, string room)
{
  Tool t;
  t.name = n;
  t.weight = w;

  Room* rOne = findVertex(room);
  rOne->objects.push_back(t);

  std::cout << rOne->name << " -> ";
  for(int i = 0; i < (int)rOne->objects.size();i++){
      std::cout << rOne->objects[(unsigned)i].name << " ";
  }
  std:: cout << std::endl;

}

// Functions that play with UI

std::string Ship::searchRoom(){
    Room * r = &location;
    if(r->objects.size() != 0){

        bag.push_back(r->objects[0]);
        return r->objects[0].name;
    }else{
        return "nothing";
    }
}

std::string Ship::buttonValue(int b){ // Returns button Text
    if(location.Edges.size()>=(unsigned)b){
        return location.Edges[(unsigned)(b-1)].description;
    }else{
        return "";
    }
}


std::string Ship::roomDescription(){ // Returns button Text
    std::cout << "called description" << std::endl;
    return location.description;
}

void Ship::reset(){
    // Resets Location
    std::cout << "Resetting Location" << std::endl;
    location = *findVertex("Cockpit");

    //Resets Inventory
    std::cout << "Resetting Inventory" << std::endl;
    while(bag.size()!=0){
        bag.pop_back();
    }
}

//std::string Ship::canEnter(int n){
//    // Does
//    return "";
//}

void Ship::moveRoom(int n){
    std::cout << "Trying to move room" << std::endl;
    Edge tempEdge = location.Edges[(unsigned)(n-1)];
    std::cout << "Created tempEdge" << std::endl;
    Room * tempRoom = tempEdge.v;
    std::cout << "Created tempRoom" << std::endl;

    std::cout << n << " " << tempRoom->name << " selected" <<std::endl;
    location = *tempRoom;
}

bool Ship::open(int n){
    bool open = false;
    if(!(location.Edges[(unsigned)(n-1)].obsticles.size()>0)){
        open = true;
    }else{
        for(int i = 0; i < (int)bag.size();i++){
            if(bag[(unsigned)i].name == location.Edges[(unsigned)(n-1)].obsticles[0].tool){
                open = true;
            }
        }
    }
    if(open){
        std::cout << "This Door is Open" << std::endl;
    }else{
        std::cout << "This Door is Closed" << std::endl;
    }
    return open;
}
