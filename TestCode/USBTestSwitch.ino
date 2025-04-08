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