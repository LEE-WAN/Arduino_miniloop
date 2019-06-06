#include <Arduino.h>

#include "miniLoop.h"

miniLoop::miniLoop(unsigned long (*func)()){
    this->func = func;
    this->enable = true;
}

void miniLoop::loop(){
    unsigned long timePassed = millis() - this->lastTime;
    if (timePassed >= delay && this->enable)
    {
        this->delay = this->func();
        if(this->delay == 0) this->enable = false;
        lastTime = millis();
    }    
}
void miniLoop::doNow(){
    this->delay = this->func();
    lastTime = millis();
}