#pragma once
// types:: Core_dmg = 1, True = 2, Special = 3, Physical = 4

struct Skills {
	int dmg;
	int damage_type;
	int mastery;
	int possible_damage_type;
	int index = 0;
};