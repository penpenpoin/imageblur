#include <iostream>
#include <vector>
#include <string>

#include "header.hpp"

using namespace std;

vector<vector<unsigned int>> Blur(const vector<vector<unsigned int>>,int);

int main(){

    string filename = "lennaASCII.pgm";

    // サンプル画像の作成
    vector<vector<unsigned int>> image = pgm_to_vector(filename);
    int M = 20; // ブラーの半径

    // ブラー処理
    vector<vector<unsigned int>> blurredImage = Blur(image, M);


    // 結果の表示debug用
    // cout << "ブラー後の画像:" << endl;
    // for(const auto& row : image){
    //     for(const auto& pixel : row){
    //         cout << pixel << "\t";
    //     }
    //     cout << endl;
    // }

    vector_to_pgm(blurredImage);


    return 0;
}

//Mピクセルでぼかす
vector<vector<unsigned int>> Blur(const vector<vector<unsigned int>> image,int M){
    vector<vector<unsigned int>> after_blur(image.size(),vector<unsigned int>(image[0].size()));

    //Mを奇数にする
    if(M % 2 == 0){
        M--;
    }
    if(image.size() < M){
        cout << "M > image size";
    }
    //半径
    int R = M/2;

    //二重ループによる移動
    for(unsigned int i = R ;  i < image.size() - R; i++){
        for(unsigned int j = R ; j< image[i].size() - R ; j++){

            //平均を求める
            long long sum = 0;
            for(unsigned int row = i - R ; row <= i + R ; row++){
                for(unsigned int column = j - R ; column <= j + R ; column++){
                    sum += image[row][column];
                }
            }
            after_blur[i][j] = sum/(M*M);
        }
    }
    return after_blur;
}


