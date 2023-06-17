#include "SkillTree.h"

SkillTree::SkillTree(Skills skills)
	: level(1)
	, requiredExp(100)
	, maxMastery(10)
{
	skill.push_back(skills);
	skill[currentIndex].index = currentIndex;
	currentIndex++;
}

void SkillTree::gainExperience(int amount)
{
	exp += amount;
	checkLevelUp();
}

void SkillTree::checkLevelUp()
{
	while (exp >= requiredExp) {
		level++;
		points++;
		exp -= requiredExp;
		requiredExp += 100;
	}
}

void SkillTree::upgradeTraits(int skillIndex)
{
	if (skillIndex < skill.size() && points >= skill[skillIndex].trait.requiredPoints && points > 0)
	{
		skill[skillIndex].trait.level++;
		points-= skill[skillIndex].trait.requiredPoints;

		upgradeSkills(skillIndex);
	}
}

void SkillTree::upgradeSkills(int skillIndex)
{
	if (skillIndex < skill.size() && skill[skillIndex].mastery <= maxMastery)
	{
		skill[skillIndex].mastery++;
		skill[skillIndex].damage += skill[skillIndex].mastery * 10;
	}
}

Skills SkillTree::getSkills(int skillIndex) 
{
	return skill[skillIndex];
}

int SkillTree::getLevel() const 
{
	return level;
}

int SkillTree::getExp() const 
{
	return exp;
}

int SkillTree::getPoints() const
{
	return points;
}