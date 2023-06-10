#pragma once
#include <vector>
#include "traits.h"
class EnergyBranch {
public:
	traits getTraits();
	void upgradeTraits();
	void setPoints(int point);
private:
	int default_energy;
	int max_mastery = 4;
	int points;
	traits EnergyManipulation = {1, 0, 1};
};