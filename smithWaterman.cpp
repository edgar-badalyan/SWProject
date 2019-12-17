#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include "smithWaterman.h"
using namespace std;
using std::string;
using std::ifstream;

#define min(a, b) (a < b? a : b)
#define max(a, b) (a > b? a : b)

smithWaterman::smithWaterman(){
    openPenalty = 11;
    extPenalty = 1;
    blosum_file = "BLOSUM62";
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

int smithWaterman::residues_to_pass(int line_number){
    if (line_number <= 0){
        return 0;
    }else{
        return (24.5 * line_number - (line_number*line_number)/2);
    }
}

int smithWaterman::get_index(int res1, int res2){
    int ind1 = residue_index(res1);
    int ind2 = residue_index(res2);
    return residues_to_pass(min(ind1, ind2)) + max(ind1, ind2) - min(ind1, ind2);
}

void smithWaterman::read_blosum(){
    ifstream file(blosum_file);
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

void smithWaterman::algo(vector<int> seq1, vector<int> seq2) {
    double QPenalty = openPenalty + extPenalty;
    double RPenalty = extPenalty;
    double max = 0.0;

    /*for (int i = 0; i< seq1.size();i++){
        std::cout << seq1[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i< seq2.size();i++){
        std::cout << seq2[i] << " ";
    }
    std::cout << std::endl;*/

    // ne faites pas attention à ces lignes
    //seq1 = "1" + seq1;
    //seq2 = "2" + seq2;
    /*
    for(int x = 1 ; x < seq2.length(); x++){
       cout << " " << seq2[x]  << " ";
    }
    cout <<endl;
    cout <<endl;
    */

    // création de la matrice
    vector<vector <double>> HMatrix(1+seq1.size(), std::vector<double>(1+seq2.size(), 0.0)), EMatrix(1+seq1.size(), std::vector<double>(1+seq2.size(), 0.0)), FMatrix(1+seq1.size(), std::vector<double>(1+seq2.size(), 0.0));
    for(int y = 1; y < seq1.size(); y++){
        //cout << " " << seq1[y]  << "    ";
        for(int x = 1; x < seq2.size(); x++){

            double maxF = max(HMatrix[y][x-1] - QPenalty, FMatrix[y][x-1] - RPenalty);
            FMatrix[y][x] = max(maxF,0);
            double maxE = max(HMatrix[y-1][x] - QPenalty, EMatrix[y-1][x] - RPenalty);
            EMatrix[y][x] = max(maxE,0);
            double maxH_1 = max(HMatrix[y-1][x-1] + residueScores[get_index(seq1[y], seq2[x])] ,0.0); double maxH_2 = max(maxF, maxE);
            HMatrix[y][x] = max(maxH_1, maxH_2);
            if(HMatrix[y][x] > max){
                max = HMatrix[y][x];
            }
        }
    }
    if ( floor((max*0.267 + 3.34)/log(2)) > 2518.0/4){
        cout  << max << "   " << floor((max*0.267 + 3.34)/log(2))<< endl;
    }
}
