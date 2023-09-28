#include "Classes.h"
#include <time.h>
#include <cmath>

void outputWin();

//constructor
Player::Player(std::string str_name, int int_probability_1, int int_hit_strength_1, int int_probability_2, int int_hit_strength_2, int int_health, int int_health_level, int int_attack_level){
	strName = str_name;
	intProbability1 = int_probability_1;
	intHitStrength1 = int_hit_strength_1; 
	intProbability2 = int_probability_2;
	intHitStrength2 = int_hit_strength_2;
	intHealth = int_health;
	intHealthLevel = int_health_level;
	intAttackLevel = int_attack_level;
}

//contains entire fight loop, calls other battle/related functions, outputs play by play of battle, outputs updated stats, resets player health to full
void Player::fight(Enemy& enemyPractice, Maze& maze, Parser parser){
	std::cout << strName << ", you have encountered " << enemyPractice.getName() << ", a feirce beast that you must kill to continue.\n" << std::endl;
	bool playerWin;
	int rememberedHealth = intHealth;
	bool playerAttack;
	bool enemyAttack;
	//while true
	while (intHealth > 0 && enemyPractice.getHealth() > 0){
		//player make attack
		int int_attack;
		int_attack = parser.getAttack();
		playerAttack = makeAttack(int_attack);
		if (playerAttack == true){
			enemyPractice.updateHealth(getHitStrength(int_attack));
			if (enemyPractice.getHealth() <= 0){
				playerWin = true;
				enemyPractice.die();
				levelUpAttackLevel(enemyPractice.getLevelUpValue());
				levelUpHitStrength();
				std::cout << "\nCONGRADULATIONS! You have defeated " << enemyPractice.getName() << "!" << std::endl;
				//std::cout << "Your attack level is " << intAttackLevel << ". Hit strength 1 is " << intHitStrength1 << ". Hit strenght 2 is " << intHitStrength2 << std::endl;	//troubleshooting
				maze.playerBeatEnemy();
                break;
			}
			else if (enemyPractice.getHealth() > 0){
				std::cout << "You have sucessfully attacked " << enemyPractice.getName() << ". Good job! " << enemyPractice.getName() << "'s health is now " << enemyPractice.getHealth() << "." << std::endl;
			}
		}
		else if (playerAttack == false){
			std::cout << "Your attack on " << enemyPractice.getName() << " has failed." << std::endl;
		}
		//enemy make attack
		enemyAttack = enemyPractice.makeAttack();
		if (enemyAttack == true){
			updateHealth(enemyPractice.getHitStrength());
			if (intHealth <= 0){
				playerWin = false;
				std::cout << "\nOH NO! The enemy has killed you." << std::endl;
				break;
			}
			else
				std::cout << "\nThe enemy has attacked you using " << enemyPractice.getAttackName() << "! Your health is now " << intHealth << std::endl;
		}
		else if (enemyAttack == false){
			std::cout << "\nThe enemy's attack failed! Your health is still " << intHealth << "." << std::endl;
		}
	}
	//reset player health to  full
	intHealth = rememberedHealth;
	//if player wins:
	if (playerWin == true){
		if(enemyPractice.getName() == "Bosstert"){
			outputWin();
			exit(0);
		}
		//call player attack level up function
		//output new level
		levelUpAttackLevel(enemyPractice.getLevelUpValue());
		maze.printMaze();
	}
	//else:
	else{
		//take in thingy from maps that exits map and enters real world again
		std::cout << "WAKE UP" << std::endl;
		inHub = true;
		maze.playerPos[0] = maze.xS;
		maze.playerPos[1] = maze.yS;
		playDay(intNotes);
	}
}

//player chooses attack, then this runs the random generator to determine whether or not the attack hit
bool Player::makeAttack(int int_attack){
	int probability;
	if (int_attack == 1){
		probability = intProbability1;
	}
	else if (int_attack == 2){
		probability = intProbability2;
	}
	int randNum = rand() % probability + 1;
	if (randNum % probability == 0){
		return true;
	}
	else{
		return false;
	}
}

//this is called as input to updateHealth, just returns the hitStrength
int Player::getHitStrength(int int_attack){
	int hitStrength;
	if (int_attack == 1)
		hitStrength = intHitStrength1;
	else if (int_attack == 2)
		hitStrength = intHitStrength2;
	return hitStrength;
}

//returns health of player
int Player::getHealth(){
	return intHealth;
}

//takes off points from player's health as result of enemy's attack
void Player::updateHealth(int enemy_attack_strength){
	intHealth -= enemy_attack_strength;
}

//contains all events when an item is found, outputs updated stats
void Player::findItem(Item found_item, Maze& maze){
	levelUpHealthLevel(found_item.getLevelUpValue());
	std::cout << "\nYou found a(n) " << found_item.getName() << "! " <<std::endl;
	//std::cout << "Your health level is at " << intHealthLevel << " and you have " << intHealth << " hp!" << std::endl;	//troubleshooting
	maze.playerGotItem();
}

//increase the health level by the amount of points gotten from item
void Player::levelUpHealthLevel(int level_up_value){
	intHealthLevel += level_up_value;
}

//increase the attack level by the amount of points gotten from winning the fight
void Player::levelUpAttackLevel(int level_up_value){
	intAttackLevel += level_up_value;
}


//if the health level has increased by 100 points, add one health point to the player's health
void Player::levelUpHealth(){
	int int_new_health = 20 + intHealthLevel % 100;
	if (int_new_health != intHealth){
		intHealth = int_new_health;
		std::cout << "Leveled up your health! You how have " << intHealth << " hp!" << std::endl;
	}
}

//if the attack level has increased by 100 points, add one health point to the player's health
void Player::levelUpHitStrength(){
	int int_new_hit_strength = intHitStrength1 + round(intAttackLevel/100);
	if (int_new_hit_strength != intHitStrength1){
		intHitStrength1 = int_new_hit_strength;
	}
	int_new_hit_strength = intHitStrength2 + round(intAttackLevel/100);
	if (int_new_hit_strength != intHitStrength2){
		intHitStrength2 = int_new_hit_strength;
		std::cout << "Leveled up hit strength!" << std::endl;
	}
}

void Player::chooseFunctionFromMap(int int_room_type, Maze& maze, Enemy& enemy){
	int randNum = rand() % 3;
    randNum = rand() % 3; // From Matthew - I decided to throw away the first random number because it wasn
    // t very random TLDR: rand() sucks

	// if it's a battle room, randomly deside which enemy
	if(int_room_type == 1){
		if(randNum == 1){
			if(intNotes == 0){
				enemy = Enemy("Giresse", 3, 5, 15, 15, "Lick", "images/jesseGiraffe.png");
			}
			else if(intNotes == 1){
				enemy = Enemy("Ravril", 2, 5, 20, 20, "Death Glare", "images/avrilFrank.png");
			}
			else{
				enemy = Enemy("Hamerhadam", 2, 7, 22, 30, "Head Hammer", "images/AdamFurry.png");
			}
		}
		else if(randNum == 2){
			if(intNotes == 0){
				enemy = Enemy("Ferrminotaur", 3, 5, 15, 15, "Charge", "images/fermin_itaur.png");
			}
			else if(intNotes == 1){
				enemy = Enemy("Timtaur", 2, 5, 20, 20, "Wrench Hit", "images/timTaur.png");
			}
			else{
				enemy = Enemy("Sethicorn", 2, 7, 22, 30, "Horn Poke", "images/seth_icorn.png");
			}
		}
		else{
			if(intNotes == 0){
				enemy = Enemy("Squirrelney", 3, 5, 15, 15, "Nibble", "images/sydSq.png");
			}
			else if(intNotes == 1){
				enemy = Enemy("Jaclalope", 2, 5, 20, 20, "Antler Bash", "images/jackALope.png");
			}
			else{
				enemy = Enemy("Mattdusa", 2, 7, 22, 30, "Stone", "images/matthew.png");
			}
		}
		Parser p2;
		fight(enemy, maze, p2);
	}
	else if(int_room_type == 2){
			if(intNotes == 0){
				Item bean1("Coffee bean", 20);
				findItem(bean1, maze);
			}
			else if(intNotes == 1){
				Item bean2("Coffee bean", 25);
				findItem(bean2, maze);
			}
			else{
				Item bean3("Coffee bean", 30);
				findItem(bean3, maze);
			}
	}
	else if(int_room_type == 3){
		if(intNotes == 0){
				std::cout << "The note reads: \"Bosstert has always been so generous with coffee in the morning. Man, am I lucky to work for him or what?\"" << std::endl;
				intNotes += 1;
			}
			else if(intNotes == 1){
				std::cout << "The note reads: \" This morning, I drank coffee before work, so I turned down Bostert’s coffee. He got so angry with me! How strange... \"" <<std::endl;
				intNotes += 1;
			}
			else{
				std::cout << "The note reads: \"THE COFFEE IS LACED WITH ACID THE COFFEE IS LACED WITH ACID THE COFFEE IS LACED WITH ACID THE COF \"" <<std::endl;
				intNotes +=1;
			}
		std::cout << "WAKE UP" << std::endl;
		playDay(intNotes);
	}
}

void Player::playDay(int in){
	std::cout << "You get to your desk and begin work, filing taxes for the upcoming tax date on April 15." << std::endl;
	std::cout << "You take a sip of the coffee. There is a strange sour quality, but before you can question it..." << std::endl;
	std::cout << "Thump!... zzzzz" << std::endl;
	std::cout << "You fall asleep" << std::endl;
	std::cout << "Press enter to continue..." << std::endl;
	std::string heyDostert;
	std::getline(std::cin, heyDostert);
	system("CLS");
	
	if(in == 0){
		std::cout << "You awake, and are no longer in your office... or are you?" << std::endl;
		std::cout << "You realize quickly that you are dreaming and are picturing the inside of your mind." << std::endl;
		std::cout << "You realize that your coffee was drugged, and you need proof that your boss did it, but you know you won't remember it was him when you are awake." << std::endl;
		std::cout << "You have to find all 3 pieces of the memory to prove that it was him." << std::endl;
		std::cout << "To the west is an unlocked door, and in the other 3 directions are locked doors." << std::endl;
		std::cout << "What do you do?" << std::endl;
	}
	else if(in == 1){
		std::cout << "You fall asleep, and are back in your mind." << std::endl;
		std::cout << "You were starting to remember parts of the note you found at the end of the previous maze." << std::endl;
		std::cout << "You realize that a new door has unlocked to the north, and you can now enter, but the previous door to the west has jammed shut." << std::endl;
		std::cout << "Hope you battled enough in that last maze. It gets more difficult now." << std::endl;
		std::cout << "To the north is an unlocked door, and in the other 3 directions are locked doors." << std::endl;
		std::cout << "What do you do?" << std::endl;
	}
	else if(in == 2){
		std::cout << "You fall asleep, and are back in your mind." << std::endl;
		std::cout << "You almost have the whole note back intact. all of the proof you need to get him fired." << std::endl;
		std::cout << "You realize that a new door has unlocked to the east, and you can now enter, but the previous door to the north has jammed shut just like the one to the west." << std::endl;
		std::cout << "Hope you battled enough in that last maze. It gets even more difficult now." << std::endl;
		std::cout << "To the east is an unlocked door, and in the other 3 directions are locked doors." << std::endl;
		std::cout << "What do you do?" << std::endl;
	}
	else if(in == 3){
		std::cout << "You fall asleep, and are back in your mind." << std::endl;
		std::cout << "You have the whole note together, and now have everything you need to get your boss fired." << std::endl;
		std::cout << "The only way to escape the dream knowing what the note said: Fight your boss in your mind." << std::endl;
		std::cout << "Hope you battled enough in that last maze. This is going to be hard" << std::endl;
		std::cout << "To the south is the final unlocked door, and behind it is the sound of a rumbling monster. it's Bosstert!" << std::endl;
		std::cout << "What do you do?" << std::endl;
	}
}

void outputWin(){
	std::cout << "You defeat your boss, Dr. Bosstert, and escape your dream with all of the evidence you need to get him fired and arrested." << std::endl;
	std::cout << "The next day, you go to the police instead of to work, and have him taken away for having an unlimited supply of acid " << std::endl;
	std::cout << "that he has been doping your coffee with daily. " << std::endl;
	std::cout << "With your new found wisdom and abilities, you become the new boss, appointed directly by the CEO himself." << std::endl;
	std::cout << std::endl;
	std::cout << "Congratulations!" << std::endl;
}