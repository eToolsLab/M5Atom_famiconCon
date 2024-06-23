#ifndef MYTASK_HPP
#define MYTASK_HPP

#include <stdint.h>
#include <M5ATOM.h>

#define INTERVAL_TASK 30

extern void setupTask(void);
extern void my_task(void *arg);
#endif