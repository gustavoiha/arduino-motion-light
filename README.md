# arduino-motion-light
Simple code for turning my kitchen's light on when there is motion 

## Electronics

I am using a Arduino Nano connected to a PIR - HC-SR501 motion sensor.

The Arduino Nano will read a HIGH digital input from the sensor and set an output to HIGH.

The output will trigger a 5 pin relay to turn on and allow current to flow between the LED lights and the 12V power source.
