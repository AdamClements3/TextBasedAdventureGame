#include "Classes.h"

//constructor
Item::Item(std::string str_name, int int_level_up_value, std::string path_in){
	strName = str_name;
	intLevelUpValue = int_level_up_value;
	path = path_in;
}

//returns intLevelUpValue, called in Player::levelUpHealthLevel in Player::findItem
int Item::getLevelUpValue(){
	return intLevelUpValue;
}

//returns name for output to player in Player::findItem
std::string Item::getName(){
	return strName;
}
//returns path for graphics
std::string Item::getPath(){
	return path;
}
