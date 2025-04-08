# Arduino USB Smart Socket

This USB controlled outlet controls UK mains power with use of a relay and Arduino internally. This device needs to recieve power and serial control signals over the USB connection and can opporate with up to 250 V AC power at 10 A.

## Smart Socket use guide

To use the smart socket plug the USB connecter in and connect to the microcontroller over serial at 9600 baud. Sending ``on`` will enable the outlet and sending ``off`` will disable the outlet.

## Final Code
```
const  int relayPin = 13;
String inputString = "";
  
void  setup() {
	pinMode(relayPin, OUTPUT);
	digitalWrite(relayPin, LOW); // Start with relay off
  
	Serial.begin(9600);
	Serial.println("Ready. Type 'on' or 'off' to control the relay.");
}
  
void  loop() {
	if (Serial.available()) {
		char incomingChar = Serial.read();
  
		if (incomingChar == '\n' || incomingChar == '\r') {
			inputString.trim(); // Clean up input
  
			if (inputString.equalsIgnoreCase("on")) {
				digitalWrite(relayPin, HIGH);
				Serial.println("Relay turned ON.");
			}
			else  if (inputString.equalsIgnoreCase("off")) {
				digitalWrite(relayPin, LOW);
				Serial.println("Relay turned OFF.");
			}
			else {
				Serial.println("Unknown command. Use 'on' or 'off'.");
			}
  
			inputString = ""; // Reset buffer
		}
		else {
			inputString += incomingChar;
		}
	}
}
```

## Hardware Specification

<p>                            | <p>
-------------------------------|-----------------------------
**Input**                      | USB A Connection to the microcontroller
**Input**                      | IEC C14 Mains Power input
**Output**                     | UK Mains Output Type G
**Microcontroller**            | Arduino Pro Mini clone
**Relay**                      | 250VAC 10A Arduino Relay module
**5V 2A USB power supply**     | Samsung USB 5V 2A GB4943-2001
**Relay signal pin**           | Arduino pin 13

## Test Code

```
int pin = 13;

void  setup() {
	Serial.begin(9600); // Start the serial communication at 9600 baud
	Serial.println("Hello, world!");

	pinMode(pin, OUTPUT);
} 

void  loop() {
	digitalWrite(pin, HIGH);
	Serial.println("Relay ON");
	delay(1000);
	digitalWrite(pin, LOW);
	Serial.println("Relay OFF");
	delay(1000); // say hello every second like a needy robot
}
```
