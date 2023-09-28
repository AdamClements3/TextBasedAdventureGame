#include <iostream>
#include <string>
#include <map>
#include <vector>

class Enemy;
class Player;
class Item;
class Maze;
class Room;
class Parser;

class Player{
private:
	std::string strName;
	
	int intProbability1;
	int intHitStrength1;
	
	int intProbability2;
	int intHitStrength2;
	
	int intHealth;
	int intHealthLevel;
	int intAttackLevel;
	
	int intNotes=0;

public:	
	//constructor
	Player(std::string str_name, int int_probability_1, int int_hit_strength_1, int int_probability_2, int int_hit_strength_2, int int_health, int int_health_level, int int_attack_level);
	//deconstructor(empty)
	~Player(){}
	
	void playDay(int in, std::string& BG);
	
	int getNotes(){
		return intNotes;
	}
	//contains entire fight loop, calls other battle/related functions, outputs play by play of battle, outputs updated stats, resets player health to full
	void fight(Enemy& enemyPractice, Maze& maze, Parser parser, std::string& BG);
	
	//player chooses attack, then this runs the random generator to determine whether or not the attack hit
	bool makeAttack(int int_attack);
	//this is called as input to updateHealth, just returns the hitStrength
	int getHitStrength(int int_attack);
	//retruns player health
	int getHealth();
	//takes off points from player's health as result of enemy's attack
	void updateHealth(int enemy_attack_strength);
	
	
	//contains all events when an item is found, outputs updated stats
	void findItem(Item found_item, Maze& maze);
	
	
	//increase the health level by the amount of points gotten from item
	void levelUpHealthLevel(int level_up_value);
	//increase the attack level by the amount of points gotten from winning the fight
	void levelUpAttackLevel(int level_up_value);
	
	
	//if the health level has increased by 100 points, add one health point to the player's health
	void levelUpHealth();
	//if the attack level has increased by 100 points, add one health point to the player's health
	void levelUpHitStrength();
	
	
	void chooseFunctionFromMap(int int_room_type, Maze& maze, Enemy& enemy, std::string& BG);
	
	bool inHub = true;
};

class Enemy{
private:
	std::string strName;
	//This is for the graphics, it's the image used to represent it onscreen
	std::string path;

	int intProbability;
	int intHitStrength;
	int intHealth;
	std::string strAttackName;

	int intLevelUpValue;
	
public: 
	//constructor
	Enemy(std::string str_name, int int_probability, int int_hit_strength, int int_health, int int_level_up_value, std::string str_attack_name, std::string path_in="");
	//deconstructor (empty)
	~Enemy(){}
	
	//returns name for output to player in Player::fight
	std::string getName();
	
	std::string getPath();
	
	std::string getAttackName(){
		return strAttackName;
	}
	
	//run random generator to determine whether or not the attack hit
	bool makeAttack();
	
	//this is called as input to updateHealth, just returns the hitStrength
	int getHitStrength();
	
	//takes off points from enemy's health as result of player's attack
	void updateHealth(int player_attack_strenght);
	
	//returns intLevelUpValue, called in Player::levelUpAttackLevel in Player::fight
	int getLevelUpValue();
	
	//return hitStrength of enemy
	int getHealth();
	
	//Death function for graphics
	void die();
};

class Item{
private:
	std::string strName;
	int intLevelUpValue;
	//This is for the graphics, it's the image used to represent it onscreen
	std::string path;
public:
	//constructor
	Item(std::string str_name, int int_level_up_value, std::string path_in="");
	//deconstructor(empty)
	~Item(){}
	
	//returns intLevelUpValue, called in Player::levelUpHealthLevel in Player::findItem
	int getLevelUpValue();
	
	//returns name for output to player in Player::findItem
	std::string getName();
	
	//returns path
	std::string getPath();
};

// Class for the room
class Room{
public:
	Room(char r, std::string path_in="");
	~Room(){};
    void changeType(char t);
    char getType();
	//returns path
	std::string getPath();
private:
	char typeOfRoom;
	//This is for the graphics, it's the image used to represent it onscreen
	std::string path;
};

/*
#=wall
b=battle room
i=item room
E = end room
*/
class Maze{
public:
    Maze(std::string mazeString);
	Maze(const Maze &aMaze);
    void goWest();
    void goEast();
    void goNorth();
    void goSouth();
    int checkRoomType(std::string& BG);
    void playerBeatEnemy();
	void playerGotItem();
    void beginMaze();
	void printMaze();
//private:
    std::vector<std::vector<char>> currentState;
    int playerPos[2] = {0,0};
	int xS = 2;
	int yS = 0;
	int currentMaze=0;
};

class Parser{
private:
    int iinct;
    int oldNotes=0; 
public:
	Parser();
	~Parser(){};
	void getString(std::map<std::vector<std::string>,int>& wordlist, Player& player, Maze theMazes[3], Enemy& enemy, std::string& BG);
	int parse(std::map<std::vector<std::string>, int> wordlist, std::vector<std::string> in);
	int currentMaze =  0; // Yes, I know this doesn't make sense to be in parser
	int getAttack();
};
