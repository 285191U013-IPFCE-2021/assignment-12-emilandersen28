#include <stdbool.h>

#ifndef DURATION_H
#define DURATION_H

class Duration
{
private:
    int time = 0;
    int alarm = 0;
    bool checkAndUpdateAlarm();

public: 
    Duration();
    Duration(int t);
    ~Duration();

bool alarmHasBeenSet = false;

int getDuration();

bool tick();

bool tick(int dt);

void setAlarm(int t);

void attribute(int t);

};

#endif