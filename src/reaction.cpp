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
		to_queue->previous = tail;
		tail = to_queue;
	}
	return 0;
}

int reaction::del(unsigned long target_id)
{
	/* search and return */
	react_entry *current = 0x0, *previous, *next;
	bool was_tail = false;
	bool was_head = false;
	/* linear search */
	for (current = tail; current; current = current->next) {
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
	previous = current->previous;
	next = current->next;
	num_reacts--;

	delete current;

	/* case of singleton */
	if (!next && !previous) {
		tail = 0x0;
		head = 0x0;
		return 1; /* list is now empty */
	}

	/* find out algorithm for deleting from linked lists */
	
	/* case of popping from the tail */
	if (was_tail) {
		previous->next = 0x0;
		tail = previous;
	}
	/* case of popping from the head */
	if (was_head) {
		next->previous = 0x0;
		head = next;
	}
	
	return 0;
}