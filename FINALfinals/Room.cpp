#pragma once
#include "Classes.h"

Room::Room(char r, std::string path_in){
    typeOfRoom=r;
    path = path_in;
}

char Room::getType(){
    return typeOfRoom;
}

void Room::changeType(char t){
    typeOfRoom=t;
}

//returns path for graphics
std::string Room::getPath(){
	return path;
}
