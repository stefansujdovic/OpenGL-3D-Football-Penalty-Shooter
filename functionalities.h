//
// Created by kunal on 3/3/18.
//

#ifndef FOOTBALL_PENALTY_SHOOTER_FUNCTIONALITIES_H
#define FOOTBALL_PENALTY_SHOOTER_FUNCTIONALITIES_H


#include <bits/stdc++.h>
#include <GL/glut.h>
#include "constants.h"
#include "SOIL.h"

#define DEG2GRAD(x) ((x) * PI/180.0)

#define GRAD2DEG(x) ((x) * 180.0/PI)

using namespace std;

void handleResize(int w, int h);


struct axes {
    double x, y, z;

    double &operator[](int);
};

double distanceBW(axes axes1, axes axes2);

struct PhysicalState {
    axes positionInitial;
    axes velocityInitial;

    axes positionCurrent;
    axes velocityCurrent;
    axes accelerationCurrent;

    double elasticity;
    double timePassed;

    PhysicalState();
};


int LoadGLTexture(char *filename);


void initialiseEverything();

void drawGoalPost();

void cameraPosition(axes point, double distance, double xAngle, double zAngle);

struct camera {
    double xAngle, yAngle;
    double distance;

    camera();
};

extern camera sphereCamera;

void myShear();

void drawHUD();


enum mode {
    ADJUSTING, AIMING, POWERING, SHOOTING, REPLAY, NONE
};

extern double powerMeter;

void drawPowerMeter();

extern mode currentMode;

extern bool currentlyWaiting;

extern bool downKeys[127];

#endif //FOOTBALL_PENALTY_SHOOTER_FUNCTIONALITIES_H
