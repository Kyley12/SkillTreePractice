#include <iostream>
#include "SkillTree.h"
Branch Core;
enum damage_type {core_dmg = 1, True_dmg, Special_dmg, Physical_dmg};
SkillTree mainTree;

Skills Cleve = {100, core_dmg, 0, True_dmg};
traits Destruction = {0, 1, 1};


int main(void) {
	Core.setSkills(Cleve);
	Core.setTraits(Destruction);
	Core.setPoints(1);
	Core.upgradeTraits(1, Destruction.index, Cleve.index, Cleve.possible_damage_type);
	mainTree.setBranches(Core);
	
	
	std::cout << "damage type: " << Cleve.damage_type << '\n' 
		<< "damage: " << Cleve.dmg <<'\n' 
		<< "index: " << Cleve.index << '\n' 
		<< "mastery: " << Cleve.mastery << '\n' 
		<< "possible damage type: " << Cleve.possible_damage_type 
		<< std::endl;

	return 0;
}