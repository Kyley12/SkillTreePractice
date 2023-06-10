#include "SkillTree.h"

Branch SkillTree::getBranches(const int index) {
	return branches.at(index);
}
void SkillTree::setBranches(Branch branch) {
	branches.push_back(branch);
}