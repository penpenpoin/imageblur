#include <fstream>
#include <vector>
#include <string>
#include <iostream>


void vector_to_pgm(std::vector<std::vector<unsigned int>> image,std::string filename = "output.pgm"){
    std::ofstream pgm(filename);

    std::string comment = "#this file was created by cpp";

    unsigned int max = 0;
    for(const auto& row : image){
        for(const auto& pixel : row){
            max = pixel>max ? pixel:max;
        }
    }

    pgm << "P2" << std::endl << comment << std::endl << image.size() << " " << image[0].size()  << std::endl << max << std::endl;

    for(const auto& row : image){
        for(const auto& pixel : row){
            pgm << pixel << std::endl;
        }
    }
    std::cout << "pgmファイルへの書き込み終了\n";
}
