# MeArm-v1-upgrade-and-code
MeArm is an open source robotic arm project with origins at hackaday.com. This is code + a small redesign!
This redesign allows you to use the larger Futuba S3003 servos for the rotor axis and the lift axis. This allows for higher torque!

There are two files with code, Analog control and wireless control (using Blynk)

Analog control: Uses two Ps2 joysticks for the 4-axis. This code has a controller witch the joystick modules attach to! See "Controller" in the design folder.

Wireless control: This uses the Blynk library to communicate from an Esp8266 to a smartphone. It uses your phone as the input device and you can control the robot arm from anywhere in the world if you have an internet connection!
Blynk App: http://tinyurl.com/yd6s95ll
