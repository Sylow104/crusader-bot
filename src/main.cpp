#include "reaction.hpp"
#include <assert.h>
#include <stdio.h>

int main()
{
	reaction *test_reaction = new reaction(0x1444);
	test_reaction->add(0x1111);
	test_reaction->add(0x1111);
	test_reaction->add(0x1132);
	test_reaction->del(0x1122);
	test_reaction->del(0x1111);

	test_reaction->size();

	delete test_reaction;
	return 0;
}