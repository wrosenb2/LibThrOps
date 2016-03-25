//
// Created by William Rosenbloom on 3/25/16.
//

#ifndef THROPS_TIME_H
#define THROPS_TIME_H

#ifdef __cplusplus
extern "C" {
#endif

typedef long long thr_time_t;

typedef enum {
    THROPS_CLOCK_REALTIME,
    THROPS_CLOCK_MONOTONIC,
    THROPS_CLOCK_PROCESS,
    THROPS_CLOCK_THREAD
} thr_clock_t;

thr_time_t thr_clock_gettime(thr_clock_t clock);
thr_time_t thr_clock_gettime_plus(thr_clock_t clock, thr_time_t plus);

#ifdef __cplusplus
}
#endif

#endif
