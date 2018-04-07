// James Scherer | LCD_CharWrite | January 2, 2018

#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include <string.h>

#include <wiringPi.h>


void pulse();
void init();

void init() {

	wiringPiSetup();
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(21, OUTPUT);
	pinMode(22, OUTPUT);


	// Function Set

	digitalWrite(21, LOW); // RS
	digitalWrite(7, LOW); // DB7
	digitalWrite(6, LOW); // DB6
	digitalWrite(5, HIGH); // DB5
	digitalWrite(4, HIGH); // DB4
	digitalWrite(3, HIGH); // DB3
	digitalWrite(2, LOW); // DB2
	digitalWrite(1, LOW); // DB1
	digitalWrite(0, LOW); // DB0

	pulse();

	// Display ON

	delay(1);

	digitalWrite(21, LOW); // RS
	digitalWrite(7, LOW); // DB7
	digitalWrite(6, LOW); // DB6
	digitalWrite(5, LOW); // DB5
	digitalWrite(4, LOW); // DB4
	digitalWrite(3, HIGH); // DB3
	digitalWrite(2, HIGH); // DB2
	digitalWrite(1, HIGH); // DB1
	digitalWrite(0, LOW); // DB0

	pulse();

	delay(1);

	// Entry Mode Set

	digitalWrite(21, LOW); // RS
	digitalWrite(7, LOW); // DB7
	digitalWrite(6, LOW); // DB6
	digitalWrite(5, LOW); // DB5
	digitalWrite(4, LOW); // DB4
	digitalWrite(3, LOW); // DB3
	digitalWrite(2, HIGH); // DB2
	digitalWrite(1, HIGH); // DB1
	digitalWrite(0, LOW); // DB0

	pulse();

}

void home() {

	delay(1);

	digitalWrite(21, LOW); // RS
	digitalWrite(7, LOW); // DB7
	digitalWrite(6, LOW); // DB6
	digitalWrite(5, LOW); // DB5
	digitalWrite(4, LOW); // DB4
	digitalWrite(3, LOW); // DB3
	digitalWrite(2, LOW); // DB2
	digitalWrite(1, HIGH); // DB1
	digitalWrite(0, LOW); // DB0

	pulse();

}

void clear() {

	delay(10);

	// Entry Mode Set

	digitalWrite(21, LOW); // RS
	digitalWrite(7, LOW); // DB7
	digitalWrite(6, LOW); // DB6
	digitalWrite(5, LOW); // DB5
	digitalWrite(4, LOW); // DB4
	digitalWrite(3, LOW); // DB3
	digitalWrite(2, LOW); // DB2
	digitalWrite(1, LOW); // DB1
	digitalWrite(0, HIGH); // DB0

	pulse();

}

void write(char* s) {

	delay(10);

	digitalWrite(21, HIGH); // RS

	for (int i = 0; (unsigned)i < strlen(s); i++) {

		char c = s[i];

		for (int j = 7; j >= 0; --j) {
			digitalWrite(j, (c & (1 << j)) ? HIGH : LOW);
		}

		pulse();
	}
}

void pulse() {

	// Clock Pulse

	digitalWrite(22, LOW); // E
	delay(1);
	digitalWrite(22, HIGH); // E
	delay(1);
	digitalWrite(22, LOW); // E
	delay(1);

}

int main(int argc, char* argv[]) {
	init();
	
	char s[256];

	clear();

	while (true) {
		printf("> ");
		gets(s);
		clear();
		write(s);

	}

	return 0;
}
