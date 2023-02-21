# Arduino Based Theremin

The theremin is an electronic musical instrument controlled without any physical contact by the performer.


# The following are the objectives of this project:

• To create an Arduino based musical instrument (theremin) which can be played without any physical contact.

• To be robust enough and space efficient for easy transportability.

• To be independent enough to accommodate different types of sounds for maximum creativity for the musician.


# How does this work

Various notes are predefined with their respective frequencies; which then get mapped to one of the ultrasonic sensors.

The other ultrasonic sensor is mapped to the output signal to the speaker/ buzzer, which handles the volume output of the instrument.

Both the ultrasonic sensors then measure their individual distances in real time which are then used to control the frequencies and the volume using internal mapping functions.

The result is a smooth transition of frequencies which are contolled by the musician's palm to create soothing music.


# Components Required

Arduino UNO - x1

Breadboard

Ultrasonic sensors - x2

Wires (Jumper wires are used) - as needed

Buzzer/ Speaker (for sound output)

A constant 5V/ 9V signal to power the circuit
