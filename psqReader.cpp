#include "psqReader.h"
#include <fstream>
#include <iostream>
using namespace std;

psqReader::psqReader() {
    sequence_offset = {};
}

char psqReader::decode_int(int code){
    char character;
    if (1<= code  && code <= 9){
        character = code + 64;
    }else if(10<= code && code<= 13){
        character = code + 65;
    }else if(14 <= code && code <=18){
        character = code + 66;
    }else if(19 <= code && code <= 23){
        character = code + 67;
    }else if(code == 24){
        character = 'U';
    }else if(code == 25){
        character = '*';
    }else if(code == 26){
        character = 'O';
    }else if (code == 27){
        character = 'J';
    }else if(code == 0){
        character = 0;
    }
    //string letter(1, character);
    return character;
}

string psqReader::get_sequence_fasta(string file_name) {
    //reads a single protein sequence from a .fasta file
    query_file_name = file_name;
    ifstream file(file_name, std::ios::in);
    if(file.is_open()){
        string line;
        int i = 0;
        string sequence = "";
        while(getline(file, line)){
            if (i != 0){ //we don't want the first line
                sequence.append(line);
            }
            i++;
        }
        file.close();
        return sequence;
    }
    exit (1);
}

int psqReader::find_sequence(string file_name, string query_sequence) {
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
    //scans the .psq file and finds the sequence that is identical to
    //the query sequence and return its index
    ifstream file(file_name, std::ios::in | std::ios::binary);
    if (file.is_open()){
        int i = 0;
        while (file.good()){
<<<<<<< HEAD
            int len = this->sequence_offset[i+1] - this->sequence_offset[i];
            char *code = new char[len];
            char char_seq[len];
            file.read(code, len);
            for (int j = 1; j< len;j++){
                char_seq[j-1] = decode_int(code[j]);
            }
            char_seq[len-1] = '\0';
            string sequence(char_seq);
            delete[] code;
            if (sequence == query_sequence){
                cout << "Query file name:   " << query_file_name << endl;
                cout << "Query length:      " << sequence.size() << " residues" <<endl;
                return i;
=======
            file.read(&lettre, 1);
            code = (int) lettre;
            sequence.append(conversion[code]);
            if (code == 0){ //sequences end with a NULL byte.
                if (sequence == query_sequence){
                    std::cout << "sequence: " << "Searching..................................................done" << endl << "Index : " << i <<endl;
                    return i;
                }
                else{ //reset sequence to read the next one
                    sequence = "";
                }
                i++;
>>>>>>> 5d4bb6846ba04b2eaeb8bcfeb68614386f8bafe5
            }
            i++;
        }
        std::cout << "sequence not found" <<endl;
        file.close();
    }
}
