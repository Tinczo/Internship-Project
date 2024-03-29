//

#include <iostream>
#include "Map.h"

Map::Map() {
    //std::cout <<"KD Map" << std::endl;
    _height = 7;
    _width = 9;
    _startX = 4;
    _startY = 4;
    _sand = 0;

    createMap(_height, _width);
    createWall(1,2,1,7);
    _map[_startX][_startY] = '+';

}

Map::Map(int aheight, int awidth) {
    //std::cout <<"K Map" << std::endl;
    _height = aheight;
    _width = awidth;
    _startX = 0;
    _startY = 0;
    _sand = 0;

    createMap(aheight, awidth);

    _map[_startX][_startY] = '+';
}

Map::~Map() {
    //std::cout <<"D Map" << std::endl;
    delocMap();
}

Map::Map(const Map &other) {
    //std::cout <<"KK Map" << std::endl;
    _startX = other._startX;
    _startY = other._startY;
    _width = other._width;
    _height = other._height;
    _sand = other._sand;
    createMap(_height, _width);
    copyMap(other);
}

Map& Map::operator=(const Map &rhs) {
    //std::cout <<"OK Map" << std::endl;
    _startX = rhs._startX;
    _startY = rhs._startY;
    if(_map != nullptr) delocMap();

    _width = rhs._width;
    _height = rhs._height;
    _sand = rhs._sand;
    createMap(_height, _width);
    copyMap(rhs);
    return (*this);
}

void Map::createMap(int aheight, int awidth) {
    _map = new char*[_height];

    for(int i = 0; i < aheight; i++){
        _map[i] = new char[awidth];
        for(int j = 0; j < awidth; j++){
            _map[i][j] = '.';
        }
    }

}

void Map::print() {
    for(int i = _height-1; i >= 0; i--){
        for(int j = 0; j < _width; j++){
            std::cout << _map[i][j];
        }
        std::cout << "\n";
    }
}

void Map::start() {

    bool work = true;
    bool falls = true;
    int x = _startX;
    int y = _startY;

    while (work){
        falls = true;
        x = _startX, y = _startY;

        while(falls){
            if(x <= 0 || y <= 0 || y >= _width-1) falls = false;
            else if(_map[x-1][y] == '.')  x = x-1;
            else if(_map[x-1][y+1] == '.') x = x-1, y = y+1;
            else if(_map[x-1][y-1] == '.') x = x-1, y = y-1;
            else falls = false;
        }

        if(x == _startX && y == _startY) work = false;
        else  if(x <= 0 || y <= 0 || y >= _width-1) work = false;
        else {
            _map[x][y] = 'o';
            _sand++;
        }

        //print();
        //std::cout << std::endl;
    }
}

int Map::getSand() {
    return _sand;
}

void Map::result() {
    print();
    std::cout << "Ziarenka: " << _sand << std::endl;
}

void Map::setStart(int ax, int ay) {
    _map[_startX][_startY] = '.';

    _startX = ax;
    _startY = ay;

    _map[_startX][_startY] = '+';
}

void Map::createWall(int ax1, int ay1, int ax2, int ay2) {
    for(int i = ax1; i <= ax2; i++){
        for(int j = ay1; j <= ay2; j++){
            _map[i][j] = '#';
        }
    }
}

void Map::copyMap(const Map &other) {
    for(int i = 0; i < _height; i++){
        for(int j = 0; j < _width; j++){
            _map[i][j] = other._map[i][j];
        }
    }
}

void Map::delocMap() {
    //std::cout << "DELOKACJA" << std::endl;
    for(int i = 0; i < _height; i++){
        delete [] _map[i];
    }
    delete [] _map;
}
