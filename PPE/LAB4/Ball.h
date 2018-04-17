#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include <windows.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <mmsystem.h>
#include <math.h>


class Ball{

private:
 int x_old_pos;
 int y_old_pos;

 int x_new_pos;
 int y_new_pos;

 int angle;
 int velocity;
 int radius;

 int color[3];

 int index;

protected:
    void randColor();
    int checkQuadran();

public:
    int _livingTime = 0;
    int TIMER;
    Ball();
    Ball(int timer_time);

    static const int RADIUS_LIMIT_MIN = 7;
    static const int RADIUS_LIMIT_MAX = 30;

    static const int VELOCITY_CRITIC_LIMIT_MIN = 5;
    static const int VELOCITY_CRITIC_LIMIT_MAX = 150;
    static const int VELOCITY_LIMIT_MIN = 2;
    static const int VELOCITY_LIMIT_MAX = 5;

    static const int LIMIT_LEFT = 10;
    static const int LIMIT_TOP = 190;
    static const int LIMIT_RIGHT = 1340;
    static const int LIMIT_BOTTOM = 690;

    static const int QUADRAN_1 = 1;
    static const int QUADRAN_2 = 1;
    static const int QUADRAN_3 = 1;
    static const int QUADRAN_4 = 1;

    void newPos();
    void reshapeBoundaries();
    void reshapeInteractions();
    void drawBall(HDC hdc);
    void drawGhost(HDC hdc);
    int ballsAngle(int xPos, int yPos);
    bool interactBall(Ball &ball);

    static double toRadian(int degrees);



};



    static std::vector<Ball*>balls;
#endif
