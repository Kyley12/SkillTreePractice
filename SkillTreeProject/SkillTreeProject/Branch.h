#pragma once
#include <vector>
#include "Skills.h"
#include "traits.h"
#include "EnergyBranch.h"

class Branch {
public:
	Skills getSkills(const int index);
	traits getTraits(const int index);
	void setSkills(Skills skill);
	void setTraits(traits trait);
	void setPoints(int point);
	void upgradeSkills(traits trait, int index, int wanted_conversion_type);
	void upgradeTraits(int point, int index, int skill_index, int wanted_conversion_type);
private:
	EnergyBranch Energy;
	bool dmg_type_conversion = false;
	int max_points = 100;
	int points = 0;
	int max_mastery = 4;
	int current_skill_index = 0;
	int current_trait_index = 0;
	std::vector<Skills> skillStorage;
	std::vector<traits> traitStorage;

};