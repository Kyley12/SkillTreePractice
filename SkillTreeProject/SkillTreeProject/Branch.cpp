#include "Branch.h"
#include "Skills.h"
#include "traits.h"

Skills Branch::getSkills(const int index) {
	return skillStorage.at(index);
}

traits Branch::getTraits(const int index) {
	return traitStorage.at(index);
}

void Branch::setSkills(Skills skill) {
	skill.index = current_skill_index;
	skillStorage.push_back(skill);
	current_skill_index++;
}
void Branch::setTraits(traits trait) {
	trait.index = current_trait_index;
	traitStorage.push_back(trait);
	current_trait_index++;
}
void Branch::setPoints(int point) {
	if (points <= max_points)
	{
		points += point;
		Energy.setPoints(point);
		Energy.upgradeTraits();

	}
	
}
void Branch::upgradeSkills(traits trait, int index, int wanted_conversion_type) {
	skillStorage.at(index).mastery++;
	
	if (dmg_type_conversion)
		skillStorage.at(index).damage_type = wanted_conversion_type;
	if(!skillStorage.empty())
		skillStorage.at(index).dmg += (trait.mastery * 1000) + (Energy.getTraits().mastery * 100) + (skillStorage.at(index).mastery*10);
}
void Branch::upgradeTraits(int point, int index, int skill_index, int wanted_conversion_type) {
	if (!traitStorage.empty()) {
		if (point >= traitStorage.at(index).points_required && max_mastery > traitStorage.at(index).mastery && point <= points)
		{
			traitStorage.at(index).mastery++;
			upgradeSkills(traitStorage.at(index), skill_index, wanted_conversion_type);

			point -= traitStorage.at(index).points_required;
			points -= point;

			traitStorage.at(index).points_required++;
		}
	}
	
}