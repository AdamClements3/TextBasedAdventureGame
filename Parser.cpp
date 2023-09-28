#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include "Classes.h"

Parser::Parser(){
	int iinct = 0;
}

void Parser::getString(std::map<std::vector<std::string>,int>& wordlist, Player& player, Maze theMazes[3], Enemy& enemy, std::string& BG){
/*	if(player.getNotes() == 3){
		Enemy Bosstert("Bosstert",2,10,30,0, "Heavy Constructive Criticism");
		player.fight(Bosstert);
	}*/
	if(oldNotes != player.getNotes()){
        player.inHub = true;
        oldNotes = player.getNotes();
    }
	
	std::vector<std::string> temp;
	//code that takes in a string
	std::string tempS;
	std::cout << ">";
	std::getline(std::cin,tempS);
	//code that separates strings into separate words
	std::istringstream iss(tempS); 
    do{ 
        std::string tempS2;
        iss >> tempS2; 
        temp.push_back(tempS2);
    } while (iss);
	
	int command = parse(wordlist, temp);
	std::vector<std::string> inW = {"multiple inputs recognized, please enter just 1",
												"multiple inputs recognized, please enter just 1",
												"multiple inputs recognized, please enter just 1",
												"I thought I already told you not to enter 2 commands at once...",
												"Are you going to keep doing 2 commands?",
												"STOP",
												"thats 2 inputs again",
												"IF YOU INPUT 2 COMMANDS 1 MORE TIME...",
												"AAAAGHGHHHGHAHGHH",
												"Next time i will crash your computer",
												"Here goes..."};
	
	
	switch(command){
		case 0: std::cout << "invalid command" << std::endl;
				break;
				
		case 1: //command for multiple inputs
				std::cout << inW.at(iinct) << std::endl;
				if(iinct == 10){
				}
				else{
					iinct += 1;
				}
				break;
				
				
				
		case 2: //command for move north
				if(player.inHub && player.getNotes() == 1){
					currentMaze = 1;
					std::cout << "You moved north" << std::endl;
					player.inHub = false;
					theMazes[currentMaze].beginMaze();
				}
				else if(!player.inHub){
					theMazes[currentMaze].goNorth();
					player.chooseFunctionFromMap(theMazes[currentMaze].checkRoomType(BG), theMazes[currentMaze], enemy, BG);
				}
				else{
					std::cout << "You cannot move north" << std::endl;
				}
				break;
				
		case 3: //command for move south
				if(player.inHub && player.getNotes() == 3){
					std::cout << "You moved South" << std::endl;
					player.inHub = false;
					enemy = Enemy("Bosstert",2,10,100,0, "Heavy Constructive Criticism", "images/bosstert.png");
					Parser p2;
					BG = "images/boss_office.png";
					player.fight(enemy, theMazes[currentMaze], p2, BG);
				}
				else if(!player.inHub){
					//std::cout << currentMaze.playerPos.size();
					//std::cout << currentMaze.playerPos.front() << std::endl;
					//std::cout << currentMaze.playerPos.back() << std::endl;
					//std::cout << "MADE IT";
					theMazes[currentMaze].goSouth();
					player.chooseFunctionFromMap(theMazes[currentMaze].checkRoomType(BG), theMazes[currentMaze], enemy, BG);
				}
				else{
					std::cout << "You cannot move south" << std::endl;
				}
				break;
				
		case 4: //command for move west
				if(player.inHub && player.getNotes() == 0){
					currentMaze=0;
					std::cout << "You moved west" << std::endl;
					player.inHub = false;
					theMazes[currentMaze].beginMaze();
				}
				else if(!player.inHub){
					theMazes[currentMaze].goWest();
					player.chooseFunctionFromMap(theMazes[currentMaze].checkRoomType(BG), theMazes[currentMaze], enemy, BG);
				}
				else{
					std::cout << "You cannot move west" << std::endl;
				}
				break;
				
		case 5: //command for move east
				if(player.inHub && player.getNotes() == 2){
					currentMaze=2;
					std::cout << "You moved east" << std::endl;
					player.inHub = false;
					theMazes[currentMaze].beginMaze();
				}
				else if(!player.inHub){
					theMazes[currentMaze].goEast();
					player.chooseFunctionFromMap(theMazes[currentMaze].checkRoomType(BG), theMazes[currentMaze], enemy, BG);
				}
				else{
					std::cout << "You cannot move east" << std::endl;
				}
				break;
				
				
				
		case 6: //command for attack
				std::cout << "You attacked" << std::endl;
				break;
		case 7: //command for run away/dodge
				std::cout << "You ran away... (little sissy)" << std::endl;
				break;
		case 8: //command for grab items
				std::cout << "You grabbed an item" << std::endl;
				break;
		case 9: //command for 69,105 items
				std::cout << "exactly 69,105" << std::endl;
				break;
		case 10: //command for show the room
				std::cout << "room description here" << std::endl;
				break;
		case 11: //command for punch
				std::cout << "punch?" << std::endl;
				break;
		case 12: //command for kick
				std::cout << "kick?" << std::endl;
				break;
	}
	getString(wordlist, player, theMazes,  enemy, BG);
	
}

int Parser::parse(std::map<std::vector<std::string>, int> wordlist, std::vector<std::string> in){
	int temp = 0;
	in.erase(in.end()-1);
	for(auto i:in){
		for (auto j: wordlist){
			for(auto k:std::get<0>(j)){
				std::transform(k.begin(), k.end(), k.begin(), ::tolower);
				std::transform(i.begin(), i.end(), i.begin(), ::tolower);
				if(i == k && temp == 0)
					temp = std::get<1>(j);
				else if(i == k && temp != 0)
					temp = 1;
			}
		}
	}
	
	return temp;
}

int Parser::getAttack(){
	std::map<std::vector<std::string>,int> wordlistA;
	std::vector<std::string> pW = {"punch","p"};
	std::vector<std::string> kW = {"kick", "k"};
	wordlistA.insert(std::pair<std::vector<std::string>,int>(pW,1));
	wordlistA.insert(std::pair<std::vector<std::string>,int>(kW,2));
	int command = 0;
	std::string tempS;
	do{
		std::cout << "Attacks: Punch or Kick" << std::endl;
		std::cout << ">";
		std::getline(std::cin,tempS);
		//code that separates strings into separate words
		std::istringstream iss(tempS); 
		std::vector<std::string> temp;
		do{ 
			std::string tempS2;
			iss >> tempS2; 
			temp.push_back(tempS2);
		} while (iss);
		//gives vector temp, and wordlistA map
		command = parse(wordlistA,temp);
		if(command != 1 && command != 2){
			std::cout << "invalid command" << std::endl;
		}
	}while(command != 1 && command != 2);
	return command;
}
