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
            if(x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) std::cout << "Wrong valuse" << std::endl;
            else if(x1 >= height || x2 >= height || y1 >= width || y2 >= width ) std::cout << "Wrong valuse" << std::endl;
            else map.createWall(x1,y1,x2,y2);
        }
        if(option == 's'){
            std::cin >> y1;
            std::cin >> x1;
            if(x1 < 0 || y1 < 0) std::cout << "Wrong valuse" << std::endl;
            else if(x1 >= height || y1 >= width) std::cout << "Wrong valuse" << std::endl;
            else map.setStart(x1,y1);
        }
    }
    return map;
}
