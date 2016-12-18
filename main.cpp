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
#include <fstream>
#include "data_structures.cpp"
#include "parse.cpp"

int main(int argc, const char *argv[])
{
	
	//========================Preparations========================
	#define USAGE std::cout<<"USAGE: "<<argv[0]<<" <options> <file1> <file2>\n"\
	<<"OPTIONS:\n\t-u\tdisplay all words unique to file2\n\t-c\tdisplay all words common to both files\n"\
	<<"EXAMPLES\n\t"<<argv[0]<<" -uc example1.txt example2.txt\n";
	
	//check arguments
	if (argc != 4) {
		USAGE
		return -1;
	}

	//check options
	bool u, c;
	if ((std::string)argv[1] == "-uc" | (std::string)argv[1] == "-cu") {
		u = true;
		c = true;
	} else if ((std::string)argv[1] == "-u") {
		u = true;
		c = false;
	} else if ((std::string)argv[1] == "-c") {
		u = false;
		c = true;
	} else {
		std::cerr<<"unknown option(s) \""<<argv[1]<<"\"\n\n";
		USAGE
		return -2;
	}

	std::fstream file1(argv[2]), file2(argv[3]);//open files

	//check if files were opened 
	if (!file1.is_open()) {
		std::cerr<<"error opening \""<<argv[2]<<"\"\n";
		return -3;
	}
	if (!file2.is_open()) {
		std::cerr<<"error opening \""<<argv[3]<<"\"\n";
		return -3;
	}

	//parse file into binary tree
	binary_tree tree;
	parse_to_tree(tree, file1);

	//========================Processing========================
	std::string read;
	linked_list common, unique;

	while (file2>>read) {//sort words in file2
		if (tree.search_tree(read))
			common.add_node(read);
		else
			unique.add_node(read);
	}

	//========================Output========================
	if (c) {
		std::cout<<"\nCommon words in both files\n";

		for (unsigned int count = 1; count < common.get_length(); count++) {
			std::cout<<'\t'<<common.get_node(count).word<<std::endl;
		}
	}
	
	if (u) {
		std::cout<<"\nUnique words in "<<argv[3]<<std::endl;

		for (unsigned int count = 1; count < unique.get_length(); count++) {
			std::cout<<'\t'<<unique.get_node(count).word<<std::endl;
		}
	}

	return 0;
}
