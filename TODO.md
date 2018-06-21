## TODOs 

* In addition to an implementation of `delay_ms()` based on a dummy loop (busy-wait loop), add another implementation based on the one of available hardware timer-counter (suggesting to use TIM4). Add a C-definition to switch between both implementations at compile-time.  