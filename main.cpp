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
#include "data_structures.cpp"

int main(int argc, const char *argv[])
{
	list::linked_list l;
	list::node *A = new list::node("word1");
	list::node *B = new list::node("alf");

	l.add_node(A);
	l.add_node(B);

	return 0;
}
