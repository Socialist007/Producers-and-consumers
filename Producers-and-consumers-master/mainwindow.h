#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "map.h"
#include "person.h"
#include "postion.h"
#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>
#include <QFont>
#include <QPen>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#define SCREEN_WIDTH 2000 // 屏幕宽度
#define SCREEN_HEIGHT 768 // 屏幕高度
#define LINE 7 // 地图行数
#define COLUMN 20 // 地图列数
#define SIZE 61 // 格子（地图上墙，箱子...）尺寸
#define X_SHIFT 110 // x偏移量
#define Y_SHIFT 130 // y偏移量
#define BLACKGROUND_PATH ":/images/blackground" // 背景图片
#define WALL_PATH ":/images/WALL" // 墙图片
#define FLOOR_PATH ":/images/floor" // 空地图片
#define DES_PATH ":/images/des" // 目的图片
#define MAN_PATH ":/images/man" // 人图片
#define Snake_PATH ":/images/snake" // 人图片
#define BOX_PATH ":/images/Apple" // apple图片
#define BOX_1_PATH ":/images/Apple" //  apple图片
#define tree_PATH ":/images/tree"
#define department_PATH ":/images/department"


extern int map[LINE][COLUMN];

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    struct Person man[3]; // 3人的位置
    struct Postion pre_pos[3];// 之前的位置
    struct Person snake; // 蛇的位置
    struct Person box[5]; // 苹果的位置
    struct Postion snake_pos; ////蛇的位置
    int step[5];
    int snake_step;//蛇的步数
    int num=2;
    int k=0;
    int o[5]={1,1,1,1,1};
    int g=1;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initmap();
    void changeMap(int line, int column, enum Map);
    bool isOver();
    int ok=0;
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
public slots:
    void gameOverControl();
    void gameSuccessControl();
    void game0();
    void snakeGame();
    void CreatBox();

signals:
    void change();
    void gamesuccess();
};
#endif // MAINWINDOW_H
