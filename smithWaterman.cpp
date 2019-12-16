#include "smithWaterman.h"

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;
using std::string;
using std::ifstream;

#define min(a, b) (a < b? a : b)
#define max(a, b) (a > b? a : b)

smithWaterman::smithWaterman(string file_name) {
        read_blosum(file_name);
}

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

int smithWaterman::residues_to_pass(int line_number){
    if (line_number <= 0){
        return 0;
    }else{
        return (24.5 * line_number - (line_number*line_number)/2);
    }
}

int smithWaterman::get_index(char res1, char res2){
    int ind1 = residues[res1];
    int ind2 = residues[res2];
    return residues_to_pass(min(ind1, ind2)) + max(ind1, ind2) - min(ind1, ind2);
}

void smithWaterman::read_blosum(string file_name){
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

void smithWaterman::run(string seq1, string seq2, double openPenalty, double extPenalty) {

    double QPenalty = openPenalty + extPenalty,
           RPenalty = extPenalty;
    double maxScore = 0.0;

    seq1 = "0" + seq1;
    seq2 = "0" + seq2;

    // création de la matrice
    vector<vector <double>> HMatrix(1+seq1.length(), std::vector<double>(1+seq2.length(), 0.0)),
                            EMatrix(1+seq1.length(), std::vector<double>(1+seq2.length(), 0.0)),
                            FMatrix(1+seq1.length(), std::vector<double>(1+seq2.length(), 0.0));

    for(int y = 1; y < seq1.length(); y++){
        for(int x = 1; x < seq2.length(); x++){
            double maxF = max(HMatrix[y][x-1] - QPenalty, FMatrix[y][x-1] - RPenalty);
            FMatrix[y][x] = max(maxF,0);
            double maxE = max(HMatrix[y-1][x] - QPenalty, EMatrix[y-1][x] - RPenalty);
            EMatrix[y][x] = max(maxE,0);
            double maxH_1 = max(HMatrix[y-1][x-1] + residueScores[get_index(seq1[y], seq2[x])] ,0.0); double maxH_2 = max(maxF, maxE);
            HMatrix[y][x] = max(maxH_1, maxH_2);
            if(HMatrix[y][x] > maxScore){
                maxScore = HMatrix[y][x];
            }
        }
    }
    cout  << floor((maxScore*0.267 + 3.34)/log(2))<< endl;
}
