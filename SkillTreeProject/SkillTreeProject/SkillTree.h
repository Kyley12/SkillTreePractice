#pragma once
#include <vector>
#include "Branch.h"



class SkillTree {
public:
	Branch getBranches(const int index);
	void setBranches(Branch branch);
private:
	
	std::vector<Branch> branches;
};