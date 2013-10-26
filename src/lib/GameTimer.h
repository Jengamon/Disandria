#ifndef GAMETIMER_H
#define GAMETIMER_H

#include <Thor/Time.hpp>
#include "RenderWindow.h"
#include "FontManager.h"
#include "../helplib/stringh.h"

class GameTimer
{
public:
    static void setTimer(int);
    static void addListener(thor::CallbackTimer::Listener);
    static void reset();
    static void start();
    static void stop();
    static bool isRunning();
    static bool isExpired();
    static double getRemainingTime();
    static void renderTime(RenderWindow*);
    static void update();
private:
    static thor::CallbackTimer timer;
};

#endif // GAMETIMER_H
