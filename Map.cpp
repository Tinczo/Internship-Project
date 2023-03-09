//
// Created by szymi on 09.03.2023.
//

#include <iostream>
#include "Map.h"

Map::Map() {
    _width = 9;
    _height = 7;
    _startX = 4;
    _startY = 4;
    _map = new char*[_height];


    for(int i = 0; i < _height; i++){
        _map[i] = new char[_width];
        for(int j = 0; j < _width; j++){
            _map[i][j] = '.';
        }
    }

    for(int i = 2; i <= 7 ; i++){
        _map[1][i] = '#';
    }

    _map[_startX][_startY] = '+';

}

void Map::print() {
    for(int i = _height-1; i >= 0; i--){
        for(int j = 0; j < _width; j++){
            std::cout << _map[i][j];
        }
        std::cout << "\n";
    }
}

Map::~Map() {
    for(int i = 0; i < _height; i++){
        delete [] _map[i];
    }
    delete [] _map;
}
