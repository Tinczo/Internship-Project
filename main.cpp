#include <iostream>
#include "Map.h"

Map service();

int main() {
    Map map = service();
    map.start();
    map.result();
    return 0;
}

Map service(){
    int height, width;
    int x1, y1, x2, y2;
    char option = 'w';
    std::cin >> width;
    std::cin >> height;
    Map map(height, width);
    while (option != 's'){
        std::cin >> option;
        if(option == 'r'){
            std::cin >> y1;
            std::cin >> x1;
            std::cin >> y2;
            std::cin >> x2;
            map.createWall(x1,y1,x2,y2);
        }
        if(option == 's'){
            std::cin >> y1;
            std::cin >> x1;
            map.setStart(x1,y1);
        }
    }
    return map;
}
