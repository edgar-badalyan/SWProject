#include "smithWaterman.h"
<<<<<<< HEAD

=======
>>>>>>> master2
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;

#define min(a, b) (a < b? a : b)
#define max(a, b) (a > b? a : b)

<<<<<<< HEAD
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
=======
smithWaterman::smithWaterman(){
    openPenalty = 11;
    extPenalty = 1;
    blosum_file = "BLOSUM62";
    cout << "Score matrix:      " << blosum_file << endl;
    cout << "Gap penalty:       " << openPenalty << "+" << extPenalty << "k" << endl;
}

int smithWaterman::residue_index(int residue){
    int index;
    switch (residue){
        case 1: index = 0;break;
        case 2: index = 20;break;
        case 3: index = 4;break;
        case 4: index = 3;break;
        case 5: index = 6;break;
        case 6: index = 13;break;
        case 7: index = 7;break;
        case 8: index = 8;break;
        case 9: index = 9;break;
        case 10: index = 11;break;
        case 11: index = 10;break;
        case 12: index = 12;break;
        case 13: index = 2;break;
        case 14: index = 14;break;
        case 15: index = 5;break;
        case 16: index = 1;break;
        case 17: index = 15;break;
        case 18: index = 16;break;
        case 19: index = 19;break;
        case 20: index = 17;break;
        case 21: index = 22;break;
        case 22: index = 18;break;
        case 23: index = 21;break;
        default: index = 23;break;
    }
    return index;
}
>>>>>>> master2

int smithWaterman::residues_to_pass(int line_number){
    if (line_number <= 0){
        return 0;
    }else{
        return (24.5 * line_number - (line_number*line_number)/2);
    }
}

<<<<<<< HEAD
int smithWaterman::get_index(char res1, char res2){
    int ind1 = residues[res1];
    int ind2 = residues[res2];
    return residues_to_pass(min(ind1, ind2)) + max(ind1, ind2) - min(ind1, ind2);
}

void smithWaterman::read_blosum(string file_name){
    ifstream file(file_name);
=======
int smithWaterman::get_index(int res1, int res2){
    int ind1 = residue_index(res1);
    int ind2 = residue_index(res2);
    return residues_to_pass(min(ind1, ind2)) + max(ind1, ind2) - min(ind1, ind2);
}

void smithWaterman::read_blosum(){
    ifstream file(blosum_file);
>>>>>>> master2
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
    else{
        cout << " Error : blosum file" << endl;
    }
}

<<<<<<< HEAD
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
=======
int smithWaterman::algo(const vector<int> & seq1, const vector<int> & seq2) {
    double QPenalty = openPenalty + extPenalty,
           RPenalty = extPenalty;
    double max = 0.0, maxF = 0.0 , maxE = 0.0, maxH_1 = 0.0, maxH_2 = 0.0;

    vector<vector <double>> HMatrix(1+seq1.size(), std::vector<double>(1+seq2.size(), 0.0)),
                            EMatrix(1+seq1.size(), std::vector<double>(1+seq2.size(), 0.0)),
                            FMatrix(1+seq1.size(), std::vector<double>(1+seq2.size(), 0.0));

    if( seq1 == seq2){
        for(int i = 1; i < seq1.size() ; i++){
            HMatrix[i][i] += HMatrix[i-1][i-1] + residueScores[get_index(seq1[i], seq2[i])];
        }
        max = HMatrix[seq1.size()-1][seq1.size()-1];
        return  floor((max*0.267 + 3.34)/log(2));
    }
    else{
        for(int y = 1; y < seq1.size(); y++){
            for(int x = 1; x < seq2.size(); x++){

                maxF = max(HMatrix[y][x-1] - QPenalty, FMatrix[y][x-1] - RPenalty);   FMatrix[y][x] = max(maxF,0);
                maxE = max(HMatrix[y-1][x] - QPenalty, EMatrix[y-1][x] - RPenalty);   EMatrix[y][x] = max(maxE,0);

                maxH_1 = max(HMatrix[y-1][x-1] + residueScores[get_index(seq1[y], seq2[x])] ,0.0);
                maxH_2 = max(maxF, maxE);
                HMatrix[y][x] =  max(maxH_1, maxH_2);

                if(HMatrix[y][x] > max){ max = HMatrix[y][x];}
            }
        }
        return  floor((max*0.267 + 3.34)/log(2));
    }

>>>>>>> master2
}
