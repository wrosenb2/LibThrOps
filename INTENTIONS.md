#LibThrops Intentions

###Introduction

Threading tasks are easily standardized in C++, and yet there is no
open source thread pooling library that does not rely on Boost. This
library attempts to change that. While the principle intention of
LibThrops is to create an interface for thread pooling, it is also
intended to make other threading and synchronization tasks easier as
well. These tasks are explicitly intended to be the ones not covered
in the `std::` namespace.

For example, timers - real, kernel managed timers - are available in
very short supply. In Linux only 2 timers are provided per process.
This library intends to write a basic run-loop implementation capable
of handling any timers the users may register.

For another example, threads may fail when a system is closed, but it
is an intention of this library to make available functions to safely
handle files and memory by deallocating it as part of the thread's
destruction procedure.

For a third example, POSIX semaphores cannot normally be broadcast to.
This means that when the Semaphore is destroyed some complicated and
cumbersome method must be employed to notify all waiting threads that
they should stop waiting. This library will implement a better semaphore
type capable of this sort of broadcast procedure.

Because the library will be POSIX only and depend of `pthread.h`, it will
be available, at its lowest level, in C. However users are expected and
encouraged to use its C++ implementation. There will also be bindings
provided for Objective-C, Java, Swift, Python, and Ruby if the project is
able to come to fruition.

###Functionality

It is important when building a library to have a very clear idea of
what the library will allow users to do. The following is a list of what
LibThrops intends to facilitate.

+ Provide an error handling interface that provides contextual feedback when an error
is thrown instead of simply saying what the system noticed.
+ Provide standardized timing functions to account for systems'
inconsistencies in implementing `time.h`.
+ Create a run-loop interface that may function as an asynchronous dispatch-queue.
+ Create a timer interface that may be scheduled on its own thread or in a run-loop.
+ Create a better semaphore capable of a standard `getcount` method broadcasts.
+ **Provide a highly customizable thread pool implementation that allows
users to distribute and synchronize tasks.
+ Provide an implementation for both `pthread_mutex_unlock` that delivers
the mutex to a specific thread or returns an error if that thread is not
waiting on the mutex.
+ Provide thread safe wrappers for both `malloc` and the `FILE *` type.
+ Provide system information regarding resource availability and limits.
+ Provide a method for registering global resources available to all
threads within a process.