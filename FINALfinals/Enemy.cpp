#include "Classes.h"
//constructor
Enemy::Enemy(std::string str_name, int int_probability, int int_hit_strength, int int_health, int int_level_up_value, std::string str_attack_name, std::string path_in){
	strName = str_name;
	strAttackName = str_attack_name;
	intProbability = int_probability;
	intHitStrength = int_hit_strength;
	intHealth = int_health;
	intLevelUpValue = int_level_up_value;
	path = path_in;
}

//returns name for output to player in Player::fight
std::string Enemy::getName(){
	return strName;
}

//run random generator to determine whether or not the attack hit
bool Enemy::makeAttack(){
	int randNum = rand() % intProbability + 1;
	if (randNum % intProbability == 0){
		return true;
	}
	else{
		return false;
	}
}

//this is called as input to updateHealth, just returns the hitStrength
int Enemy::getHitStrength(){
	return intHitStrength;
}

//takes off points from enemy's health as result of player's attack
void Enemy::updateHealth(int player_attack_strength){
	intHealth -= player_attack_strength;
}

//returns intLevelUpValue, called in Player::levelUpAttackLevel in Player::fight
int Enemy::getLevelUpValue(){
	return intLevelUpValue;
}

int Enemy::getHealth(){
	return intHealth;
}

//returns path for graphics
std::string Enemy::getPath(){
	return path;
}

void Enemy::die(){
	path = "";
}