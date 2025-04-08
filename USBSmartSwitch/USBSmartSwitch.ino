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