#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "../include/catch.hpp"
#include "../../include/duration.h"

TEST_CASE("duration")
{
    Duration d1;
    Duration d2;
    Duration d3;
    d1.attribute(5);
    d2.attribute(10);
    d3.attribute(20);
    int s1 = d1.getDuration();
    int s2 = d2.getDuration();
    int s3 = d3.getDuration();

    REQUIRE(s1 == 5);
    REQUIRE(s2 == 10);
    REQUIRE(s3 == 20);
    
    d1.setAlarm(30);
    d2.setAlarm(30);

    bool status1 = d1.alarmHasBeenSet;
    bool status2 = d2.alarmHasBeenSet;
    bool status3 = d3.alarmHasBeenSet;
    REQUIRE(status1);
    REQUIRE(status2);
    REQUIRE(!status3);

    d3.setAlarm(30);

    d1.tick();
    d2.tick();
    d3.tick();

    s1 = d1.getDuration();
    s2 = d2.getDuration();
    s3 = d3.getDuration();

    REQUIRE(s1 == 6);
    REQUIRE(s2 == 11);
    REQUIRE(s3 == 21);

    d1.tick(23);
    d2.tick(19);
    d3.tick(10);

    s1 = d1.getDuration();
    s2 = d2.getDuration();
    s3 = d3.getDuration();
    REQUIRE(s1 == 29);
    REQUIRE(s2 == 30);
    REQUIRE(s3 == 31);

    REQUIRE(d1.alarmHasBeenSet);
    REQUIRE(d2.alarmHasBeenSet);
    REQUIRE(!d3.alarmHasBeenSet);
}
// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. 