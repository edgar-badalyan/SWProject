//
// Created by Raymond Khazoum on 28/11/2019.
//

#include "phrReader.h"
#include <iostream>
#include <fstream>
#include <sstream>
using std::string;
using std::endl;
using std::ifstream;
phrReader::phrReader() {

}

string phrReader::read_header(string file_name, int i){
    ifstream file(file_name, std::ios::in | std::ios::binary);
    if (file.is_open()){
        int len = this->header_offset[i+1] - this->header_offset[i];
        file.seekg(this->header_offset[i]);
		string header;
		for (int i =0;i<len;i++){
			char byte;
			std::stringstream sstream;
			file.read(&byte, 1);
			sstream << std::hex << (int) byte;
			std::string character (sstream.str());
			if (character == "1a"){
				char size_c;
                int size;
				file.read(&size_c, 1);
				i++;
				std::stringstream sstream2;
				sstream2 << std::hex << (int)size_c;
				sstream2 >> size;
				int real_size;
				if (size >= 128){
					string encoding_size (sstream2.str());
					encoding_size = encoding_size.substr(7);
					std::stringstream sstream3;
					for (int k = 0; k<std::stoi(encoding_size);k++){
					    unsigned char encoded_size;
						file.read(reinterpret_cast<char *>(&encoded_size), 1);
						i++;
						sstream3 << std::hex << (int)encoded_size;
					}
					sstream3 >> real_size;
				}else{
                    real_size = size;
				}
                char header_part[real_size+1];
                file.read(header_part, real_size);
                header_part[real_size] = '\0';
                i += real_size;
                header.append(header_part);
			}
		}
        //std::cout << header << endl;
        file.close();
        return header;
    }
}
