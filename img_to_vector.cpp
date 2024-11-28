#include <fstream>
#include <vector>
#include <string>
#include <iostream>

std::vector<std::vector<unsigned int>> pgm_to_vector(std::string filename){
    std::ifstream pgm(filename);

    if(!pgm){
        std::cout << "ファイルが見つかりません.\n";
    }


    std::string P2;
    std::getline(pgm,P2);
    std::string comment,maximumsize;
    std::getline(pgm,comment);

    unsigned int row,column;
    pgm >> column >> row;

    //縦横逆?
    std::vector<std::vector<unsigned int>> image(column, std::vector<unsigned int>(row));

    for(int i = 0; i < column * row; i++){
        pgm >> image[i/column][i%column];
    }
    return image;

}
