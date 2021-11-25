#include <stddef.h>
#include <assert.h>
#include <stdbool.h>

#include "../include/duration.h"

int Duration::getDuration()
{
    return time;
}

Duration::Duration()
{
    time = 0;
}

Duration::Duration(int t)
{
    assert(time >= 0);
    time = t;
}

bool Duration::tick()
{
    ++time;

    if (Duration::checkAndUpdateAlarm() == true)
    {
        return true;
    }
    else 
        return false;
}

bool Duration::tick(int dt)
{
    assert(dt >= 0);

    time = time + dt;

    if (Duration::checkAndUpdateAlarm() == true)
    {
        return true;
    }
    else 
        return false;
}

void Duration::setAlarm(int t)
{
    assert(time < t);
    alarm = t;
    alarmHasBeenSet = true;
}

bool Duration::checkAndUpdateAlarm()
{
    if (time > alarm)
    {
        alarm = 0;
        alarmHasBeenSet = false;
        return true;
    }
    else   
        return false;
}

void Duration::attribute(int t)
{
    assert(time >= 0);
    time = t;
}

Duration::~Duration(){}