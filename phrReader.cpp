#include "phrReader.h"

phrReader::phrReader() {
    header_length = 0;
    header_offset = {};
}

string phrReader::read_header(string file_name, int index){
    header= "gnl|BL_ORD_ID|" + std::to_string(index) + " ";
    header_length = header_offset[index+1] - header_offset[index];
    ifstream file(file_name, ios::in | ios::binary);
    if (file.is_open()){
        file.seekg(header_offset[index]);
		for (int i =0; i<header_length ;i++){
			char byte;
			stringstream sstream;
			file.read(&byte, 1);
			sstream << hex << int(byte);
			string character = sstream.str();
            i = convert_header(file, character, i);
		}
        file.close();
		// we don't want the output to be too long
        return header.substr(0, 110);
    }
    else{
        cout << " Error : phr file" << endl;
        exit(1);
    }
    exit(1);
}

int phrReader::convert_header(ifstream &file, string character, int i){
    if (character == "1a"){
        char size_c;
        int size;
        file.read(&size_c, 1);
        i++;
        stringstream sstream2;
        sstream2 << hex << (int)size_c;
        sstream2 >> size;
        int real_size;
        // if bigger than 128, it's just the size on which the real size is encoded
        if (size >= 128){
            string encoding_size (sstream2.str());
            encoding_size = encoding_size.substr(7);
            stringstream sstream3;
            for (int k = 0; k< stoi(encoding_size) ;k++){
                unsigned char encoded_size;
                file.read(reinterpret_cast<char *>(&encoded_size), 1);
                i++;
                sstream3 << hex << (int)encoded_size;
            }
            sstream3 >> real_size;
        }
        else{
            real_size = size;
        }
        char header_part[real_size+1];
        file.read(header_part, real_size);
        header_part[real_size] = '\0';
        i += real_size;
        header.append(header_part);
    }
    return i;
}
