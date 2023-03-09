//
// Created by szymi on 09.03.2023.
//

#ifndef INTERNSHIPPROJECT_MAP_H
#define INTERNSHIPPROJECT_MAP_H


#include <vector>

class Map {
public:
    Map();
    Map(int aheight, int awidth);
    ~Map();
    void print();
    void start();
    void result();
    int getSand();
    void setStart(int ax, int ay);
    void createWall(int ax1, int ay1, int ax2, int ay2);

private:
    char** _map; // można by było użyć inteligentych wskaźników albo wektorów ale chcialem pokazac że wiem co to lokowanie dynamiczne ;)
    int _startX;
    int _startY;
    int _width;
    int _height;
    int _sand;

    void createMap(int aheight, int awidth);
};


#endif //INTERNSHIPPROJECT_MAP_H
