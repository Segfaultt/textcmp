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
#include <iostream>

//returns true if successful
bool parse_to_tree(binary_tree &tree, std::istream &stream)
{
	std::string transfer;

	while (stream.peek() != EOF) {
		stream>>transfer;
		if (!tree.add_leaf(transfer))
			return false;
	}

	return true;
}

//returns true if successful
bool parse_to_list(linked_list list, std::istream &stream)
{
	std::string transfer;

	while (stream.peek() != EOF) {
		stream>>transfer;
		if (!list.add_node(transfer))
			return false;
	}

	return true;
}
