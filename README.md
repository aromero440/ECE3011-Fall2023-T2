# ECE3011 Fall 2023 Team 2
### Team members: Antonio Romero, Maxime Antoine Beaulieu, Charles Khamis Lindberg, Wahib Abdul Yonis

#### Code Author: Antonio Romero

The specific numbers and operations for each grade are pulled from the Georgia Standards also seen in this directory. Due to hardware and time constraints, we are unable to implement the desired two digit input for our inductance sensors since that will cause our number of sensors to double; as a result, we limited our target grades from K-3 with single digit responses.

This program is intended to handle the interaction between all components of the robot. The following include descriptions of what each file does:

- **ECE_3011_Junior_Design.ino**: Main file to control all robot functionality
- **genProblem.h/genProblem.cpp**: Generates the problem given a specific grade level
- **hardware.h/hardware.cpp**: Responsible for handling all interactions with hardware. This includes: light, speaker, screen, motor, and sensors
- **test.cpp**: Contains the test framework