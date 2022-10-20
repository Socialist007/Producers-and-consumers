#include "mainwindow.h"
#include <QTimer>
#include <QDebug>
#include <QCoreApplication>
#include <QRandomGenerator>
#include <QTime>       //使用了QTime函数
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initmap();
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));          //设置随机数种子
    connect(this, SIGNAL(change()), this, SLOT(update()));
    //connect(this, SIGNAL(gameover()), this, SLOT(gameOverControl()));

}

MainWindow::~MainWindow()
{
}
/*
 * 地图初始化函数
 * 设置地图大小和标题
 */
void MainWindow::initmap() {
    resize(SCREEN_WIDTH, SCREEN_HEIGHT); // 初始化屏幕高度宽度
    setWindowIconText(QString("生产者与消费者"));
    step[0]=0;
    step[1]=-1;
    step[2]=-1;
    step[3]=-1;
    step[4]=-1;
    snake_step=0;
    snake_pos.p=NUL;
    ok=0;
    pre_pos[0].p = NUL; // 之前的位置
    pre_pos[1].p = NUL; // 之前的位置
    pre_pos[2].p = NUL; // 之前的位置

}
/*
 *  控制函数
 *  输入参数：要前进的方向（UP， DOWN， LEFT， RIGHT）
 */
/*
 * 判断游戏是否结束函数
 * 当地图中所有DES被替换为HIT代表结束
 * 返回值：true为结束， false反之
 */
bool MainWindow::isOver() {
    //    if(map[4][18]==MAN&&map[4][20]==MAN2&&map[4][22]==MAN1)
    //    {
    //        return true;
    //    }
    //    return false;

}
void MainWindow::CreatBox()
{
    int l=0;
    if(g)
    {

        for(int i=1;i<5;i++)
        {
            if(!o[i])
            {
                num=i+1;l=1;
                o[i]=1;
            }

        }

        switch(num)
        {
        case 2:  map[2][3]=BOX2;step[1]=0;break;
        case 3:  map[2][3]=BOX3;step[2]=0;break;
        case 4:  map[2][3]=BOX4;step[3]=0;break;
        case 5:  map[2][3]=BOX5;step[4]=0;break;
        }
        update();
        if(!l)
            num++;
        if(num>5)
            num=6;
    }
}
void MainWindow::snakeGame()
{
    //蛇形走位
    if(k==1)
    {
        if(map[snake.x+1][snake.y]!=FLOOR)
            changeMap(snake.x-1, snake.y, FLOOR);
        int index=qrand() % 2+1;
        if(map[5][16]!=FLOOR)//如果苹果已经落地
        {

            if(snake.y>16&&snake.x==5)//蛇在苹果 右方
            {
                index=1;
                qDebug()<<index<<endl;
            }


        }
        //    index =
        //        index=QRandomGenerator::global()->bounded(1, 4);

        qDebug()<<index<<endl;
        //产生5以内的随机数(1-4)
        switch(index)
        {


        case 1://left

            if (map[snake.x][snake.y-1] !=WALL) {

                changeMap(snake.x, snake.y, FLOOR);
                changeMap(snake.x, snake.y-1, Snake);
                snake_step++;

            }

            break;
        case 2://right

            if (map[snake.x][snake.y+1] !=WALL) {
                changeMap(snake.x, snake.y, FLOOR);
                changeMap(snake.x, snake.y+1, Snake);
                snake_step++;

            }

            break;
        }
    }


}
void MainWindow::game0(){


    ////////////////////////apple

    for(int i=0;i<5;i++)
    {

        if(step[i]==0&&o[i])//o=1 cunzai o=0 buzai
        {
            if (map[box[i].x][box[i].y + 1] == FLOOR ){

                changeMap(box[i].x, box[i].y, FLOOR);
                if(i==0)
                    changeMap(box[i].x, box[i].y + 1, BOX);
                if(i==2)
                    changeMap(box[i].x, box[i].y + 1, BOX3);
                if(i==3)
                    changeMap(box[i].x, box[i].y + 1, BOX4);
                if(i==4)
                    changeMap(box[i].x, box[i].y + 1, BOX5);
                if(i==1)
                    changeMap(box[i].x, box[i].y + 1, BOX2);

            }

            else if(map[box[i].x][box[i].y + 1] == DES)
            {
                changeMap(box[i].x, box[i].y, FLOOR);
                k=1;




                step[i]=1;
                if(i==0)
                    changeMap(box[i].x, box[i].y + 2, BOX);
                if(i==2)
                    changeMap(box[i].x, box[i].y + 2, BOX3);
                if(i==3)
                    changeMap(box[i].x, box[i].y + 2, BOX4);
                if(i==4)
                    changeMap(box[i].x, box[i].y + 2, BOX5);
                if(i==1)
                    changeMap(box[i].x, box[i].y + 2, BOX2);
            }

        }
        else if(step[i]==1&&o[i])
        {
            k=1;
            if(map[box[i].x+1][box[i].y ] ==FLOOR)
            {
                changeMap(box[i].x, box[i].y, FLOOR);

                if(i==0)
                    changeMap(box[i].x+1, box[i].y , BOX);
                if(i==2)
                    changeMap(box[i].x+1, box[i].y , BOX3);
                if(i==3)
                    changeMap(box[i].x+1, box[i].y , BOX4);
                if(i==4)
                    changeMap(box[i].x+1, box[i].y , BOX5);
                if(i==1)
                    changeMap(box[i].x+1, box[i].y , BOX2);
            }
            else if(map[box[i].x+1][box[i].y] ==Snake||map[box[i].x][box[i].y+1] ==Snake)
            {
                //                           k=0;
                changeMap(box[i].x, box[i].y, FLOOR);
                step[i]=0;

                o[i]=0;
            }
        }

    }

}

/*
 * 改变地图参数函数
 * 改变参数同时发出change()信号， 关联update()函数对图进行渲染
 * 输入：改变的行，列，变成的属性（墙，箱子，人等）
 */
void MainWindow::changeMap(int line, int column, enum Map m) {
    map[line][column] = m;
    emit change();
}
// 重写绘图事件
void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, QPixmap(BLACKGROUND_PATH)); // 绘制背景
    QFont font("方正舒体", 30, QFont::ExtraLight, false);
    QPen pen;
    pen.setColor(Qt::white);
    painter.setPen(pen);
    painter.setFont(font);
    for (int i = 0; i < LINE; i++) {
        for (int j = 0; j < COLUMN; j++) {
            switch (map[i][j]) {
            case WALL: {
                painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(WALL_PATH)); // 绘制墙
                break;
            }
            case FLOOR: {
                painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(FLOOR_PATH)); // 绘制空地
                break;
            }
            case DES: {
                painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(DES_PATH)); // 绘制目的地
                break;
            }
            case MAN: {
                painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(MAN_PATH)); // 绘制人
                // 记录3小人位置

                man[0].x = i;
                man[0].y = j;

                break;
            }
            case Tree: {
                painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(tree_PATH)); // 绘制人
                // 记录3小人位置



                break;
            }
            case Snake: {
                painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(Snake_PATH)); // 绘制人
                // 记录snake位置

                snake.x = i;
                snake.y = j;

                break;
            }
            case BOX: {
                painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(BOX_PATH)); // 绘制箱子
                box[0].x=i;
                box[0].y=j;
                break;
            }
            case BOX2: {
                painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(BOX_PATH)); // 绘制箱子
                box[1].x=i;
                box[1].y=j;
                break;
            }
            case BOX3: {
                painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(BOX_PATH)); // 绘制箱子
                box[2].x=i;
                box[2].y=j;
                break;
            }
            case BOX4: {
                painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(BOX_PATH)); // 绘制箱子
                box[3].x=i;
                box[3].y=j;
                break;
            }
            case BOX5: {
                painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(BOX_PATH)); // 绘制箱子
                box[4].x=i;
                box[4].y=j;
                break;
            }
            case HIT: {
                painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(BOX_1_PATH));

                break;

            }
            case department: {
                painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(department_PATH));

                break;

            }

            default:
                break;
            }
        }
    }


    //    if (isOver()) {
    //        painter.drawText((this->width()/2) - 40, this->height()/2, QString(" CPU处理完成！"));
    //        emit gamesuccess();
    //    }

    //开启按钮
    painter.setBrush(QColor(255, 255, 255));
    painter.setOpacity(0.9);
    painter.drawEllipse(QRectF(10.0, 10.0, 50.0, 50.0));
    painter.drawText(0.0, 100.0, "开始");
    //关闭2号小人
    painter.setBrush(QColor(255, 255, 255));
    painter.setOpacity(0.9);
    painter.drawEllipse(QRectF(201.0, 10.0, 50.0, 50.0));
    painter.drawText(201.0, 100.0, "消费者停止进食");
    //关闭3号小人
    painter.setBrush(QColor(255, 255, 255));
    painter.setOpacity(0.9);
    painter.drawEllipse(QRectF(601.0, 10.0, 50.0, 50.0));
    painter.drawText(701.0, 100.0, "生产者停止生产");
    painter.drawText(140, 250.0, "生产者");
    painter.drawText(1050, 590.0, "消费者");
    painter.drawText(500, 450.0, "缓存区");








}
//重写鼠标事件
//鼠标按下事件
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QTimer *timer = new QTimer;

    QTimer *timer1 = new QTimer;
    QTimer *timer2 = new QTimer;
    qDebug()<<event->pos().x()<<" ";
    qDebug()<<event->pos().y()<<endl;
    //    dragPosition=event->globalPos()-frameGeometry().topLeft();
    //shut down noe
    if (event->pos().x() < 60
            && event->pos().y() <33)
    {
        map[2][3]=BOX;
        map[2][15]=DES;
        step[0]=0;
        g=1;
        num=2;
        update();
        //start,snakeGame()
        connect(timer, SIGNAL(timeout()), this, SLOT(game0())); // game0是我们需要执行的响应函数

        timer->start(800);

        connect(timer1, SIGNAL(timeout()), this, SLOT(CreatBox()));
        timer1->start(3000);

        connect(timer2, SIGNAL(timeout()), this, SLOT(snakeGame()));
        timer2->start(1200);
    }
    else if (event->pos().x()<250)
    {

        map[2][15]=WALL;
        k=0;
        timer2->stop();
        update();


    }
    else if (600<event->pos().x())
    {
        // qDebug()<<num<<"33333333333333 ";

        g=0;

    }


    return;
}



void MainWindow::gameOverControl() {
    disconnect(this, SIGNAL(change()), this, SLOT(update()));
}

void MainWindow::gameSuccessControl() {
    disconnect(this, SIGNAL(change()), this, SLOT(update()));
}
//


