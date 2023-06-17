#include <iostream>

#include "SkillTree.h"

enum damage {core_dmg, true_dmg, phy_dmg, special_dmg};

void addSkills(Skills& skill, int mastery, int damage, int damageType, int level);
void printSkillState(const Skills& skill);
void printTreeState(const SkillTree& t);

int main(void) 
{
	Skills skill1;
	addSkills(skill1, 1, 10, core_dmg, 1);
	SkillTree tree(skill1);

	printTreeState(tree);
	printSkillState(tree.getSkills(skill1.index));

	tree.gainExperience(500);

	tree.upgradeTraits(skill1.index);

	printTreeState(tree);
	printSkillState(tree.getSkills(skill1.index));

	tree.upgradeTraits(skill1.index);
	printTreeState(tree);
	printSkillState(tree.getSkills(skill1.index));

	return 0;
}

void addSkills(Skills& skill, int mastery, int damage, int damageType, int level) 
{
	skill.mastery = mastery;
	skill.damage = damage;
	skill.damageType = damageType;
	skill.trait.level = level;
	skill.trait.requiredPoints = 1;
}

void printSkillState(const Skills& skill) 
{
	int pMastery = skill.mastery;
	int pDamage = skill.damage;
	int pDamageType = skill.damageType;
	int pTraitLevel = skill.trait.level;
	
	std::cout << "<Skill state>" << std::endl;
	std::cout << "Mastery: " << pMastery << std::endl;
	std::cout << "Damage: " << pDamage << std::endl;
	std::cout << "Damage Type: " << pDamageType << std::endl;
	std::cout << "Trait Level: " << pTraitLevel << std::endl;
	std::cout << "---------------" << std::endl;

}

void printTreeState(const SkillTree& t) {
	int pTreeLevel = t.getLevel();
	int pTreeExp = t.getExp();
	int pPoints = t.getPoints();

	std::cout << "<Tree State>" << std::endl;
	std::cout << "Tree Level: " << pTreeLevel << std::endl;
	std::cout << "Tree Exp: " << pTreeExp << std::endl;
	std::cout << "Tree Points: " << pPoints << std::endl;
	std::cout << std::endl;

}