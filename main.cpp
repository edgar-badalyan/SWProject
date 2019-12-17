#include "databaseReader.h"

int main(int argc, char* argv[]){
    if(argc < 3){
        cout << "missing file path, in order: database, sequence"<< endl;
    }
    else{
        databaseReader * databaseFiles = new databaseReader(argv[1], argv[2]);
        delete databaseFiles;
    }
}
