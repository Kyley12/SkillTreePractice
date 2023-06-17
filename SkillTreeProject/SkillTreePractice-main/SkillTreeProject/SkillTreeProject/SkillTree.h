#include <vector>

#include "Skills.h"

class SkillTree 
{
public:
	SkillTree(Skills skills);

	void gainExperience(int amount);

	void checkLevelUp();

	void upgradeTraits(int skillIndex);

	void upgradeSkills(int skillIndex);

	Skills getSkills(int skillIndex);

	int getLevel() const;

	int getExp() const;

	int getPoints() const;

private:
	int level;
	int exp;
	int requiredExp;
	int points;
	int maxMastery;
	int currentIndex = 0;
	std::vector<Skills> skill;
};