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

#include <string>

namespace list {
	struct node {
		node();
		node(std::string);//string contstructor
		node* next;
		std::string word;
	};

	class linked_list {
	public:
		linked_list();
		virtual ~linked_list();

		bool add_node(std::string);//append a node to the list
		node get_node(unsigned int);
	
	private:
		node * head;
		unsigned int length;
	};
}
