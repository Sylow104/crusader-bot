#ifndef _REACTION_
#define _REACTION_
#include "person.hpp"

class react_entry : public person
{
	public:
	react_entry(unsigned long discord_id);
	~react_entry();

	react_entry *next = 0x0, *previous = 0x0;
};

class reaction
{
	public:
	reaction(unsigned int react_id);
	~reaction();

	unsigned int size();
	unsigned int id();

	int add(unsigned long new_user);
	int del(unsigned long target_id);

	private:
	unsigned int num_reacts = 0;
	unsigned int id_react = 0x0;
	
	react_entry *head = 0x0;
	react_entry *tail = 0x0;
};

#endif /* _REACTION_ */