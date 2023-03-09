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
    void start();
    void result();
    int getSand();

private:
    char** _map; // można by było użyć inteligentych wskaźników albo wektorów ale chcialem pokazac że wiem co to lokowanie dynamiczne ;)
    int _startX;
    int _startY;
    int _width;
    int _height;
    int _sand;

};


#endif //INTERNSHIPPROJECT_MAP_H
