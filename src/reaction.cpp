#include "reaction.hpp"

reaction::reaction(unsigned int react_id)
{
	;
}

reaction::~reaction()
{
	;
}

unsigned int reaction::size()
{
	return num_reacts;
}

unsigned int reaction::id()
{
	return id_react;
}

int reaction::add(unsigned long new_user)
{
	react_entry *to_queue = new react_entry(new_user);
	if (!head) {
		head = to_queue;
	}
	if (!tail) {
		tail = to_queue;
	} else {
		tail->next = to_queue;
		tail = to_queue;
	}
	num_reacts++;
	return 0;
}

int reaction::del(unsigned long target_id)
{
	/* search and return */
	react_entry *current = 0x0, *previous = 0x0, *next;
	bool was_tail = false;
	bool was_head = false;
	/* linear search */
	for (current = head; current; previous = current, 
			current = current->next) {
		if (current->id() == target_id) {
			break;
		}
	}
	if (!current) {
		return -1;
	}

	if (current == tail) {
		was_tail = true;
	}
	if (current == head) {
		was_head = true;
	}

	/* isolate the entry */
	next = current->next;
	num_reacts--;

	delete current;
	if (previous) {
		previous->next = next;
	}

	if (was_tail) {
		tail = previous;
	}
	if (was_head) {
		head = next;
	}
	
	return 0;
}