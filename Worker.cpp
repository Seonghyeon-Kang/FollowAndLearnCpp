#pragma once

#include "Worker.h"
#include "Timer.h" // 의존적인 관계

void Worker::doSomething(){
    Timer timer;        // start timer

    // do some work here

    timer.elapsed();    // end timer and report elapsed time
}