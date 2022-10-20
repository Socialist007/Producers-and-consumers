#include "map.h"

int map[LINE][COLUMN] = { // µÿÕº√ËªÊ

                          {W,W,W,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,W,W,W,WALL},
                          {W,W,Tree,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,WALL,FLOOR,FLOOR,FLOOR,WALL},
                          {W,W,Tree,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,DES,FLOOR,FLOOR,FLOOR,WALL},
                          {W,W,W,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,FLOOR,FLOOR,FLOOR,WALL},
                          {W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,WALL,FLOOR,FLOOR,FLOOR,WALL},
                           {W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,WALL,Snake,FLOOR,FLOOR,WALL},
                           {W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,WALL,WALL,WALL,WALL,WALL}
                        };
