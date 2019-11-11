//
// Created by tameer on 11/10/19.
//

#ifndef SCHEDULER_SCHEDULER_H
#define SCHEDULER_SCHEDULER_H

#include <iostream>
#include <vector>
#include "itask.h"

class Scheduler{
public:
    Scheduler(){}
    void addTask(ITask*);
    void runTask();
private:
    std::vector<ITask*> tasks;
};

inline void Scheduler::addTask(ITask* new_task) {
    tasks.push_back(new_task);
}

#endif //SCHEDULER_SCHEDULER_H
