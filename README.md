# Dynamic-torque-and-stepper-motor


This is a small project that I have been working on in order to activate a stepper motor that connects with a dynamic torque sensor to make different stress studies. The code is something simple and can get you out of the trouble for a home job.

For this case I used the differential example of the adafruit 1x15 library to read the differential output of the sensor.

Also, the stepper motor has no delay's just LOW-HIGH step pin to make the step so when the sensor start to reading is going to read when the motor is working and then when the step pin is low there will be no read.
