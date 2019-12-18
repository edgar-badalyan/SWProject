#include <chrono>
#include "databaseReader.h"

int main(int argc, char* argv[]){
    if(argc < 3){
        cout << "missing file path, in order: database, sequence"<< endl;
    }
    else{
        auto start = std::chrono::high_resolution_clock::now();
        int openPenalty=11, extPenalty=1;
        double factor=12;
        std::string blosum_file = "BLOSUM62";

        // Reading coommand-line parameters
        for (int i = 0; i < argc - 1; i++){
            if (std::string(argv[i]) == "-go"){
                openPenalty = strtol(argv[i+1], NULL, 10);
            }else if(std::string(argv[i]) == "-ge"){
                extPenalty = strtol(argv[i+1], NULL, 10);
            }else if(std::string(argv[i]) == "-f"){
                factor = strtod(argv[i+1], NULL);
            }else if(std::string(argv[i]) == "-b"){
                blosum_file = argv[i+1];
            }
        }

        databaseReader * databaseFiles = new databaseReader(argv[1], argv[2], openPenalty, extPenalty, factor, blosum_file);
        delete databaseFiles;

        //measure execution time
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
        std::cout << std::endl << "Execution time: " << duration.count() << " seconds." << std::endl;

    }
}
