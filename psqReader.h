//
// Created by Raymond Khazoum on 28/11/2019.
//

#ifndef SWIPE_PSQREADER_H
#define SWIPE_PSQREADER_H

#include <fstream>
#include <iostream>

#include <map>

#ifndef TEST_READ_H
#define TEST_READ_H

std::map<int, std::string> conversion = {
        {1,"A"},
        {2,"B"},
        {3,"C"},
        {4,"D"},
        {5,"E"},
        {6,"F"},
        {7,"G"},
        {8,"H"},
        {9,"I"},
        {10,"K"},
        {11,"L"},
        {12,"M"},
        {13,"N"},
        {14,"P"},
        {15,"Q"},
        {16,"R"},
        {17,"S"},
        {18,"T"},
        {19,"V"},
        {20,"W"},
        {21,"X"},
        {22,"Y"},
        {23,"Z"},
        {24,"U"},
        {25,"*"},
        {26,"O"},
        {27,"J"},
};

#endif


using namespace std;

class psqReader {
public:
    psqReader();

    string get_sequence_fasta(string file_name);
    int find_sequence(string file_name, string query_sequence);
};


#endif //SWIPE_PSQREADER_H