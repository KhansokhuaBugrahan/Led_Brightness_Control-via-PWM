# Led_Brightness_Control-via-PWM
Board: STM32F407G-DISC1                                                             
  IDE: STMCubeIDE                                   
  
  main.c                                                                                               
Each 1-second, duty cycle is  increased by 10%.After reaching 100%, it starts up from zero again                                             
Timer3 interrupt routine is used to provide the time lapse of changes in the LED state and increase the duty cycle dynamically.  
We use 1kHz frequency to deceive human eyes' perception.                                             
If we use less frequency, we can observe LED's state change in one period.                                   
However, we want to set it as if it never goes low.                                                

  main1.c                                                        
 In this example, we use potentiometer as a dimmer.                                                             
 We can set sampling cycle to 3. By doing so, we do not need to check the adc value whether it is ready or not.                                    
 Because the conversion will be too fast.                                                                       
 If we use it with a higher sampling cycle, unexpected behavior occurs in case of not checking the status register.                        
 However, in any case, to check the data is safer.

Khansokhua Bugrahan
