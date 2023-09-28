#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include "Classes.h"
Maze::Maze(const Maze &aMaze){
	currentState = aMaze.currentState;
	playerPos[0] = aMaze.playerPos[0];
	playerPos[1] = aMaze.playerPos[1];

}

Maze::Maze(std::string mazeString){
    int x=0,y=0;
    bool top=true;
    std::vector<char> tempVec; //Each room of the maze is an object of class Room
    for(auto r:mazeString){
		tempVec.push_back(r);
        if(r=='s'){//then that room is the starting position of the player
			playerPos[0] = x;
			playerPos[1] = y;
        }
        else if(r=='n'){//then the row is finished
			tempVec.pop_back();
            currentState.push_back(tempVec);
            tempVec.clear();
			y++;
			x = 0;
        }
		x++;
	}
}

void Maze::goWest(){
    if(currentState.at(playerPos[1]).at(playerPos[0] - 1) != '#'){
        playerPos[0] = playerPos[0] - 1;
    }
    else{
        std::cout<<"Can't move into a wall buddy"<<std::endl;
    }
	printMaze();
}

void Maze::goSouth(){
	//std::cout << "made it this far" << std::endl;
	//std::cout << playerPos.front();
	//std::cout << " " << playerPos.back() << std::endl;
	//std::cout << "check in" << std::endl;
	//std::cout << "currentState.size() = " << currentState.size() << std::endl;
	//std::cout << "currentState.at(0).size() = " << currentState.at(0).size() << std::endl;
    if((currentState.at((playerPos[1] + 1))).at(playerPos[0]) != '#'){
		std::cout << "Moving S..." << std::endl;
        playerPos[1] = playerPos[1] + 1;
		//std::cout << "actually made it" << std::endl;
    }
    else{
        std::cout<<"Can't move into a wall buddy"<<std::endl;
    }
	printMaze();
}

void Maze::goEast(){
    if(currentState.at(playerPos[1]).at(playerPos[0] + 1) != '#'){
        playerPos[0] = playerPos[0] + 1;
    }
    else{
        std::cout<<"Can't move into a wall buddy"<<std::endl;
    }
	printMaze();
}

void Maze::goNorth(){
    if(currentState.at(playerPos[1] - 1).at(playerPos[0]) != '#'){
        playerPos[1] = playerPos[1] - 1;
    }
    else{
        std::cout<<"Can't move into a wall buddy"<<std::endl;
    }
	printMaze();
}

//Fermin Note: I added a string reference so that it changes rooms
int Maze::checkRoomType(std::string& BG){ // Adam, call this function every time the player moves, to see if they get into a battle room
	//return 1 to refer to battle room
    if(currentState.at(playerPos[1]).at(playerPos[0]) == 'B'){
		//Randomly generate battle room
		int randBG = rand() % 4;
		switch(randBG){
			case 0:
				BG = "images/dover.png";
				break;
			case 1:
				BG = "images/centaurLab.png";
				break;
			case 2:
				BG = "images/giygasvoid.png";
				break;
			case 3:
				BG = "images/lakers.png";
				break;
		}
        return 1;
    }
	//return 2 to refer to an item room
    else if(currentState.at(playerPos[1]).at(playerPos[0]) == 'I'){
		BG = "images/coffee_bean.png";
		return 2;
    }
	else if(currentState.at(playerPos[1]).at(playerPos[0]) == 'E'){
		std::cout << "You've found the exit to the maze! Here, you find a note..." << std::endl;
		BG = "images/note.png";
		return 3;
	}
	else{
		std::cout << "Just an empty room!" << std::endl;
		BG = "images/empty.png";
		return 0;
	}
}

void Maze::playerBeatEnemy(){ // Adam, call this function whenever the player beats the enemy in a room
    currentState.at(playerPos[1]).at(playerPos[0]) = ' ';
}

void Maze::playerGotItem(){ // Adam, call this function whenever the player beats the enemy in a room
    currentState.at(playerPos[1]).at(playerPos[0]) = ' ';
}

void Maze::printMaze(){
	auto theMazeState = currentState;
     std::cout<<std::endl;
	 // Loop through each element and print
    for(auto i = 0; i< currentState.size(); i++){
        for(auto j = 0; j< currentState.at(0).size(); j++){
			if(j==playerPos[0] and i==playerPos[1]){
				std::cout << 'P';
			}
			else{
				std::cout << currentState[i][j];
			}
        }
        std::cout<<std::endl;
    }
	//std::cout <<"Player position: " << playerPos[0] << " " << playerPos[1] << std::endl;	//troubleshooting
}

void Maze::beginMaze(){
	printMaze();
	//std::cout << playerPos[0] << " " << playerPos[1];	//troubleshooting
	//std::cout << "maze has begun" << std::endl;	//troubleshooting
}
