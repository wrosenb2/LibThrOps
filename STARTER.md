#LibThrops Plans

Working with threads, as might be expected, requires some
very platform dependent code, as well as platform dependent
workarounds for non-standard library functions. It is the
intention of LibThrops to make things easier - for POSIX
at least.

The fundamental idea behind LibThrops is that the functions
necessary to create and synchronize threaded applications - from
everything to timing functions to IPC - should have a coordinated interface.
This is not entirely a new idea. ***In fact, LibThrops has a fair
amount of competition.***

This implementation may be POSIX specific, and probably less broad
than the competition's projects, but LibThrops will bring far more
functionality to its users. LibThrops will facilitate synchronization,
timing, run-loops, alarms, thread pools, ITC, and even IPC **in a native and
clean way.**

###Competition and Core Functionality

LibThrops will become better than the competition by implementing
what has worked for others.

**There are 3 Principal Sources of Competition for LibThrops**

1. [The std::* threading libraries in C++](http://en.cppreference.com/w/cpp/thread/thread)
2. [The boost threading library](http://www.boost.org/doc/libs/1_60_0/doc/html/thread.html)
3. [The Cocoa(-Touch) GCD API](https://developer.apple.com/library/ios/documentation/Performance/Reference/GCD_libdispatch_Ref/)

From these libraries we may learn is essential for a comprehensive
threading library.

####Error Handling

Errors should be handled extremely diligently and should provide
contextually relevant information rather than just stock errors.

####Timing Functions

`time_t`: unit of time defined by the implementation

`clock_gettime`: gets the current system time according to one of the following clocks.

 1. real-time clock
 1. monotonic clock
 1. process clock
 1. thread clock

 `clock_gettime_plus`: creates a time_t at some point in the future

 `clock_time_since`: finds the distance to some other time.

 ####Synchronization

 There should be a `promise` entity, `mutex`, `conditional_variable`,
 `semaphore`, `latch`, `rwlock`, and IPC mutex/cond all defined by this implementation.

 ####IPC/TPC

 There should also be sockets that may connect threads, sockets that connect
 processes, and info dictionary sockets available to both.

 ####Thread Pooling

 I think you know what you want to do about thread pooling. Make sure this
 is the first part of the project that gets finished.

 ####Dispatch Queues and Run-Loops

 These wil be very similar to a thread pool except that it
 will be a single thread servicing a queue. Queue items may choose to be repeated
 or executed only once. This will be vital for facilitating timers.

 ####Timers and Alarms

 Timers should be available to react after a certain amount of time has passed.
 While I do intend to make it possible to schedule a timer on its own thread,
 they will more generally be added to run-loops that will poll them to see if they are ready.

 ####Implementation Language

 It might be wise to implement this library in C++. It would
 make many things very much easier for me and really would not
 hurt the overall functionality of the library.

 Alternatively I could use Objective-C but I think that would hurt
 the overall functionality of the library.

