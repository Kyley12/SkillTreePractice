#include "traits.h"
#include "EnergyBranch.h"

traits EnergyBranch:: getTraits() {
	return EnergyManipulation;
}
void EnergyBranch::upgradeTraits() {
	if (points >= EnergyManipulation.points_required && EnergyManipulation.mastery < max_mastery) {
		EnergyManipulation.mastery++;
		points -= EnergyManipulation.points_required;
		EnergyManipulation.points_required++;
	}
}
void EnergyBranch::setPoints(int point) {
	points += point;
}