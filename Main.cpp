#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <thread>
#include <functional>
#include "Renderer.h"
#include "Classes.h"

void beginStory(std::string& BG);
void playDay(int in);

//Put graphics and the story in two functions so they can be put in threads
void graphics_loops(Player& player, Enemy& enemy, std::string& BG);
void story_loop(Player& player, Enemy& enemy, std::string& BG);

int main() {
	srand (time(NULL));
	
	//Original stats: 2,4,4,6,20,0,0
	Player player("player",2,4,4,6,20,0,0);
	Enemy enemy("enemy", 1, 2, 3, 4, "kick", "");
	std::string BG = "images/wakeup.png";
	
	//Run
	//std::ref lets me pass references to a thread
	std::thread gthread(graphics_loops, std::ref(player), std::ref(enemy), std::ref(BG));
	std::thread sthread(story_loop, std::ref(player), std::ref(enemy), std::ref(BG));
	
	sthread.join();
	gthread.join();
}

void beginStory(std::string& BG){
	//A, A, M, J, J, T, F, S, S
	//S, A, M; A, J, J, T, F, S
	std::string in;
	std::cout << "Beep! Beep! Beep! 6:00" << std::endl;
	std::cout << "You wake up and look over at your calendar" << std::endl;
	std::cout << "|-----------------------------------------|" << std::endl;
	std::cout << "|                  March                  |" << std::endl;
	std::cout << "|-----------------------------------------|" << std::endl;
	std::cout << "|  Su |  M  |  T  |  W  |  Th |  F  |  Sa |" << std::endl;
	std::cout << "|-----------------------------------------|" << std::endl;
	std::cout << "|  1  |  2  |  3  |  4  |  5  |  6  |  7  |" << std::endl;
	std::cout << "|-----------------------------------------|" << std::endl;
	std::cout << "|  8  |  X  |  10 |  11 |  12 |  13 |  14 |" << std::endl;
	std::cout << "|-----------------------------------------|" << std::endl;
	std::cout << "|  15 |  16 |  17 |  18 |  19 |  20 |  21 |" << std::endl;
	std::cout << "|-----------------------------------------|" << std::endl;
	std::cout << "|  22 |  23 |  24 |  25 |  26 |  27 |  28 |" << std::endl;
	std::cout << "|-----------------------------------------|" << std::endl;
	std::cout << "|  29 |  30 |  31 |     |     |     |     |" << std::endl;
	std::cout << "|-----------------------------------------|" << std::endl;
	std::cout << "Monday March 9th, the beginning of your new accounting job." << std::endl;
	std::cout << "Press enter to continue..." << std::endl;
	std::getline(std::cin, in);
	system("CLS");
	BG = "images/introdostert.png";
	std::cout << "You quickly get ready, and head out the door too fast to remember your coffee." << std::endl;
	std::cout << "You arive to work very tired, where you meet your new boss" << std::endl;
	std::cout << "Boss: You look tired. Here, take this." << std::endl;
	std::cout << "He hands you a mug of steaming coffee, as if he had expected you to need it." << std::endl;
	std::cout << "You take it willingly, but think to yourself that it was a bit strange. Maybe this new boss was just very nice." << std::endl;
	std::cout << "You are hopeful that this new job will be better than your previous part-time jobs from college." << std::endl;
	std::cout << "Press enter to continue..." << std::endl;
	std::getline(std::cin, in);
	system("CLS");
}


void graphics_loops(Player& player, Enemy& enemy, std::string& BG){
	Renderer graphics(740, 580);

    while (!graphics.Close()) {
        graphics.SetBG(BG);
        graphics.SetEnemy(enemy.getPath());
        graphics.SetItem("");
        graphics.SetHealth(player.getHealth());
        
        graphics.Draw();
    }
}

void story_loop(Player& player, Enemy& enemy, std::string& BG){
	srand (time(NULL));

	Parser parser;
	Enemy testEnemy("Enemy1",3,5,20,20, "enemy attack");
	std::map<std::vector<std::string>,int> wordlist;
	std::vector<std::string> nW = {"north","up","u","n"};
	std::vector<std::string> sW = {"south","down","d","s"};
	std::vector<std::string> wW = {"west","left","l","w"};
	std::vector<std::string> eW = {"east","right","r","e"};
	std::vector<std::string> pW = {"punch"};
	std::vector<std::string> kW = {"kick"};
	std::vector<std::string> aW = {"Ambush","Assault","Beat","Besiege","Bombard","Charge","Harm","Hit","Hurt","Invade","Raid","Stab","Storm","Strike","Bash","Advance","Bat","Clock","Club","Combat","Jump","Mug","Overwhelm","Rush","Wallop","Knock","Lunge"};
	std::vector<std::string> gW = {"Get","Grab","Collect","Take","Gather","Save","Snag","Grip","Grasp","Clutch"};
	std::vector<std::string> rW = {"avoid","depart","disappear","dodge","elude","emerge","evade","flee","leave","run","slip","vanish","circumvent","pass","desert","disband","scramble","disperse"};
	std::vector<std::string> fW = {"count","time"};
	std::vector<std::string> lW = {"look"};
	std::vector<std::string> seW = {"kamehameha","hadouken","uuddlrlrbas"};
	//all of the words for move north
	wordlist.insert(std::pair<std::vector<std::string>,int>(nW,2));
	//all of the words for move south
	wordlist.insert(std::pair<std::vector<std::string>,int>(sW,3));
	//all of the words for move west
	wordlist.insert(std::pair<std::vector<std::string>,int>(wW,4));
	//all of the words for move east
	wordlist.insert(std::pair<std::vector<std::string>,int>(eW,5));
	//all of the words for attack
	wordlist.insert(std::pair<std::vector<std::string>,int>(aW,6));
	//all of the words for run
	wordlist.insert(std::pair<std::vector<std::string>,int>(rW,7));
	//all of the words for grab
	wordlist.insert(std::pair<std::vector<std::string>,int>(gW,8));
	//all of the words for random 69,105 responses
	wordlist.insert(std::pair<std::vector<std::string>,int>(fW,9));
	//words for look
	wordlist.insert(std::pair<std::vector<std::string>,int>(lW,10));
	//words for punch
	wordlist.insert(std::pair<std::vector<std::string>,int>(pW,11));
	//words for kick
	wordlist.insert(std::pair<std::vector<std::string>,int>(kW,12));
	
	Maze m0 = Maze(
        "##s#######n"
        "# B# I   #n"
        "# #BI#  ##n"
        "#B ##   I#n"
        "#I# # # B#n"
        "#B   B # #n"
        "# #I # #I#n"
        "######E###n"
    );
                          
    Maze m1 = Maze(
        "##s#######n"
        "#  I  #I##n"
        "#I##B # B#n"
        "# # B## ##n"
        "# #B##  ##n"
        "# I  I #I#n"
        "#B# ## B #n"
        "######E###n"
    );
    
    Maze m2 = Maze(
        "##s#######n"
        "# B #    #n"
        "# # I ####n"
        "#I# ## I #n"
        "# #B  B# #n"
        "#B##  #I #n"
        "# I#B I#B#n"
        "######E###n"
    );
	Maze theMazes[3] = {m0,m1,m2};
	beginStory(BG);
	player.playDay(player.getNotes(), BG);
    parser.getString(wordlist, player, theMazes, enemy, BG);
}