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
#define NDEBUG
#include <iostream>
#include "data_structures.cpp"

int main(int argc, const char *argv[])
{
	linked_list list;
	binary_tree tree;
	
	tree.add_leaf("Foo");
	tree.add_leaf("Bar");
	tree.add_leaf("Foobar");
	tree.add_leaf("Barb");
	tree.add_leaf("Jordan");
	tree.add_leaf("Sophie");
	tree.add_leaf("Sarah");
	tree.add_leaf("Matthew");
	tree.add_leaf("John");
	tree.add_leaf("Jacob");
	tree.add_leaf("Barb");

	if (tree.search_tree(argv[1])) 
		std::cout<<argv[1]<<" is in the tree\n";
	else
		std::cout<<argv[1]<<" is not in the tree\n";
	
	return 0;
}
