//
// Created by tameer on 11/10/19.
//

#include "scheduler.h"
#include <sys/time.h>
#include <unistd.h>

using namespace std;
void Scheduler::runTask() {
    struct timeval start;
    long mtime, seconds, useconds;
    ;
    while(1){
        for(int i = 0 ; i < tasks.size() ; i++) {
            gettimeofday(&start, NULL);
            mtime = ((start.tv_sec) * 1000 + start.tv_usec / 1000.0);
            long ag = tasks[i]->getNextRunPeriod();
            if (mtime - ag >= 0)
                tasks[i]->run();
        }
    }

}