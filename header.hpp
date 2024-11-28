#pragma once

#include <vector>
#include <string>

//img2vec
std::vector<std::vector<unsigned int>> pgm_to_vector(std::string filename);




//vec2img
void vector_to_pgm(std::vector<std::vector<unsigned int>> image,std::string filename = "output.pgm");
