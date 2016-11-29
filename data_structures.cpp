/*
Copyright (C) 2016  Luca Pengelly

This file is part of textcmp.

textcmp is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

textcmp is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with textcmp.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "data_structures.h"
#include <iostream>

using namespace list;

linked_list::linked_list() {
	head = NULL;
	length = 0;
}

//append a node to the list
bool linked_list::add_node(node *new_node) {
	if (length >= UINT_MAX) {
		
		return false;
	}

	node  *current_node;
	node *next_node;
	current_node = head;
	next_node = head;

	if (head) {
		while (next_node) {//traverse until the next pointer is null (end of list)
			current_node = next_node;
			next_node = current_node->next;
		}
		current_node->next = new_node;//set the next pointer to the new node
		next_node = current_node->next;
	} 
	else {
		head = new_node;
		std::cout<<head->word<<std::endl;
	}
	
	length++;

	return true;
}

node linked_list::get_node(unsigned int count) { 
	if (count > length) 
	return *head;

	node  *current_node = head;
	node *next_node = head;
	for (int i = 0; i < count; i++) {
		current_node = next_node;
		next_node = current_node->next;
	}

	return *current_node;
}

//transverse through nodes while deleting them
linked_list::~linked_list() {
	node *current_node;
	node *next_node;
	next_node = head->next;
	while (next_node) {
		current_node = next_node;
		next_node = current_node->next;
		if (next_node) {
			std::cout<<current_node->word;
			delete current_node;
		}
	}
}

node::node() {
	word = "[EMPTY]";
	next = NULL;
}
node::node(std::string a) {
	word = a;
}
