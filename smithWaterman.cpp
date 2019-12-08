#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <sstream>

using std::string;
using std::ifstream;

#define min(a, b) (a < b? a : b)
#define max(a, b) (a > b? a : b)

int residueScores[300];
std::map<char, int> residues = {
    {'A', 0},
    {'R', 1},
    {'N', 2},
    {'D', 3},
    {'C', 4},
    {'Q', 5},
    {'E', 6},
    {'G', 7},
    {'H', 8},
    {'I', 9},
    {'L', 10},
    {'K', 11},
    {'M', 12},
    {'F', 13},
    {'P', 14},
    {'S', 15},
    {'T', 16},
    {'W', 17},
    {'Y', 18},
    {'V', 19},
    {'B', 20},
    {'Z', 21},
    {'X', 22},
    {'*', 23},
};

int residues_to_pass(int line_number){
    if (line_number <= 0){
        return 0;
    }else{
        return (24.5 * line_number - (line_number*line_number)/2);
    }
}

int get_index(char res1, char res2){
    int ind1 = residues[res1];
    int ind2 = residues[res2];
    return residues_to_pass(min(ind1, ind2)) + max(ind1, ind2) - min(ind1, ind2);
}

void read_blosum(string file_name){
    ifstream file(file_name);
    if(file.is_open()){
        string line;
        int index=0;
        int line_number = 0;
        while(getline(file, line)){
            if(line[0] != '#' && line[0] != ' '){
                int read = 0;
                line.erase(line.begin());
                std::stringstream sstream(line);
                int score;
                while(sstream >> score){
                    if(read >= line_number){
                        residueScores[index++] = score;
                    }
                    read++;
                }
                line_number++;
            }
        }
        file.close();
    }
}

int main(){
    read_blosum("BLOSUM62");
    std::cout << residueScores[get_index('A', 'A')]<<std::endl;
    std::cout << residueScores[get_index('T', 'M')]<<std::endl;
    std::cout << residueScores[get_index('X', 'Y')]<<std::endl;
    std::cout << residueScores[get_index('G', 'H')]<<std::endl;
    std::cout << residueScores[get_index('M', 'N')]<<std::endl;


}
