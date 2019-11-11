#include <iostream>
#include <unistd.h>
#include <sys/time.h>
#include "scheduler.h"
#include "itask.h"
#include "time.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    Scheduler scheduler;
    HelloTask pr1(15, 5);
    scheduler.addTask(&pr1);
    CounterTask pr2(60, 1);
    scheduler.addTask(&pr2);
    scheduler.runTask();
    return 0;
}