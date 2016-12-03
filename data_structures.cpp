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
bool linked_list::add_node(std::string new_word) {
	if (length >= UINT_MAX)
		return false;
	
	node* new_node = new node(new_word);//create new node

	if (head) {
		node  *current_node;
		node *next_node;
		current_node = head;
		next_node = current_node->next;

		while (next_node) {//traverse until the next pointer is null (end of list)
			current_node = next_node;
			next_node = current_node->next;
		}
		#ifndef NDEBUG
			std::cout<<"node \""<<current_node->word<<"\" set to point to node \""<<new_node->word<<'\"'<<std::endl;
		#endif
		current_node->next = new_node;//set the next pointer to the new node
	} 
	else {
		#ifndef NDEBUG
			std::cout<<"head set to point to node \""<<new_node->word<<'\"'<<std::endl;
		#endif
		head = new_node;
	}
	
	length++;

	return true;
}

node linked_list::get_node(unsigned int count) { 
	if (count > length || count < 1) {//check if in domain
		std::cerr<<"error: trying to get a node that doesn't exist\n";
		return *head;
	}

	node *current_node = head, *next_node = head;
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
	next_node = head;
	while (next_node) {
		current_node = next_node;
		next_node = current_node->next;
		if (current_node) {
			#ifndef NDEBUG
				std::cout<<"deleting node \""<<current_node->word<<'\"'<<std::endl;
			#endif

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
	next = NULL;
}
