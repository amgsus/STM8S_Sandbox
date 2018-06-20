## TODOs 

* Add a free-running timer which overflows each 1 ms and raises OVF event (suggesting to use TIM4 as it does not has CAPCOM channels). This timer will be using as base for a task scheduler.
* In addition to an implementation of `delay_ms()` based on a dummy loop (busy-wait loop), add another implementation based on the one of available hardware timer-counter (suggesting to use TIM4). Add a C-definition to switch between both implementations at compile-time.  