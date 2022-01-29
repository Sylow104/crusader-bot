#include "reaction.hpp"
#include <stdio.h>

react_entry::react_entry(unsigned long discord_id) :
	person(discord_id)
{
	;
}

react_entry::~react_entry()
{
	;
}

reaction::reaction(unsigned int react_id)
{
	id_react = react_id;
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
	react_entry *to_queue;
	if (search(new_user)) {
		fprintf(stderr, "No need to add user %ld\n", new_user);
		return -1;
	}
	
	to_queue = new react_entry(new_user);
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
	fprintf(stderr, "Added user id %ld\n", new_user);
	return 0;
}

int reaction::del(unsigned long target_id)
{
	react_entry *current = 0x0, *previous = 0x0, *next;
	current = search(target_id, &previous);
	if (!current) {
		fprintf(stderr, "Cannot find user id %ld\n", target_id);
		return -1;
	}

	next = current->next;
	if (current == head) {
		head = next;
	}
	if (current == tail) {
		tail = previous;
	}

	previous->next = next;
	delete current;
	fprintf(stderr, "Deleted user id %ld\n", target_id);
	num_reacts--;
	
	return 0;
}

react_entry *reaction::search(unsigned long target_id)
{
	react_entry *placeholder;
	return search(target_id, &placeholder);
}

react_entry *reaction::search(unsigned long target_id, react_entry **previous)
{
	react_entry *current = 0x0;
	for (current = head; current;
			*previous = current, current = current->next) {
		if (current->id() == target_id) {
			break;
		}
	}
	if (current) {
		fprintf(stderr, "Found user id %ld\n", 
			target_id);
	}

	return current;
}