#ifndef MAP_H
#define MAP_H

#define LINE 7// 地图行数
#define COLUMN 20 // 地图列数

enum Map { // 地图属性
    WALL, // 墙
    FLOOR, // 空地
    DES, // 目的地
    MAN, // 1
    MAN1,//2
    Snake,//3
    BOX, // 箱子
    BOX2,
    BOX3,
    BOX4,
    BOX5,
    HIT, // 箱子到达目的地
    W,
    Tree,
    department,
    NUL = -1 // 记录上一个位置


};

#endif // MAP_H
