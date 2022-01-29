#include "person.hpp"

person::person(unsigned long discord_id)
{
	person_id = discord_id;
}

person::~person()
{
	;
}

unsigned long person::id()
{
	return person_id;
}