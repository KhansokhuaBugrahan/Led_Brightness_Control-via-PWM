# Led_Brightness_Control-via-PWM
Board: STM32F407G-DISC1                                                             
  IDE: STMCubeIDE                                                                              
Each 1-second, duty cycle is  increased by 10%.After reaching 100%, it starts up from zero again                                             
Timer3 interrupt routine is used to provide the time lapse of changes in the LED state and increase the duty cycle dynamically.  
We use 1kHz frequency to deceive human eyes' perception.                                             
If we use less frequency, we can observe LED's state change in one period.                                   
However, we want to set it as if it never goes low.                 
