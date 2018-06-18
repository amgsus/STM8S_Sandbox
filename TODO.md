* "Blink"
  * add a procedure `delay_ms()` for synchronous delay. Implement it in two ways (described below). Also add an option C-definition to switch between them at compile-time.
    * The 1st one uses one of available hardware timers (suggest to use TIM4);
    * The 2nd one uses a "classic" dummy loop.
  * add macros for setting up GPIOs (pin mode, slope control, EXTI, etc.). 