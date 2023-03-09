//
// Created by szymi on 09.03.2023.
//

#ifndef INTERNSHIPPROJECT_MAP_H
#define INTERNSHIPPROJECT_MAP_H


#include <vector>

class Map {
public:
    Map();
    ~Map();
    void print();

private:
    char** _map;
    int _startX;
    int _startY;
    int _width;
    int _height;

};


#endif //INTERNSHIPPROJECT_MAP_H
