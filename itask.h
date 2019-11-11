//
// Created by tameer on 11/10/19.
//

#ifndef SCHEDULER_ITASK_H
#define SCHEDULER_ITASK_H


#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <unistd.h>

struct ITask
{
    virtual void run() = 0;
    virtual unsigned long getNextRunPeriod() = 0; // in milliseconds
};

struct HelloTask : ITask {
    HelloTask(int number_of_iteration=15, int time=5);
    void run();
    unsigned long getNextRunPeriod();
    int getNumberOfExe();
private:
    int m_num_of_iteration;
    unsigned long m_time;
    struct timeval m_next_iteration;
};

inline HelloTask ::HelloTask(int number_of_iteration, int time): m_num_of_iteration(number_of_iteration),
                                                                 m_time(time){
    gettimeofday(&m_next_iteration, NULL);
}

inline void HelloTask::run() {
    std::cout<<" Hello "<<std::endl;
    gettimeofday(&m_next_iteration, NULL);;
    m_num_of_iteration--;
}

inline unsigned long HelloTask::getNextRunPeriod() {

    return ((m_next_iteration.tv_sec+m_time)*1000 + m_next_iteration.tv_usec/1000);
}

inline int HelloTask::getNumberOfExe() {
    return m_num_of_iteration;
}


struct CounterTask : ITask {
    CounterTask(int number_of_exe, int time);
    void run();
    unsigned long getNextRunPeriod();
    int getNumberOfExe();
private:
    int m_num_of_iteration;
    int m_time;
    struct timeval m_next_iteration;
    static int m_counter;
};

inline CounterTask::CounterTask(int number_of_exe, int time): m_num_of_iteration(number_of_exe), m_time(time){
    gettimeofday(&m_next_iteration, NULL);
}
inline void CounterTask::run() {
    if(m_counter == 60)
        m_counter = 0;
    std::cout<<++m_counter<<std::endl;
    gettimeofday(&m_next_iteration, NULL);;
    m_num_of_iteration--;


}
inline unsigned long CounterTask::getNextRunPeriod() {
    return ((m_next_iteration.tv_sec+1)*1000 + m_next_iteration.tv_usec/1000);
}
inline int CounterTask::getNumberOfExe() {
    return m_num_of_iteration;
}
#endif //SCHEDULER_ITASK_H
