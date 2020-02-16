#include "simpletools.h"
#include "servo.h"
#include "ping.h"

#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
#define melodyPin 1
//Mario main theme melody
int melody[] = {
NOTE_E7, NOTE_E7, 0, NOTE_E7,
0, NOTE_C7, NOTE_E7, 0,
NOTE_G7, 0, 0, 0,
NOTE_G6, 0, 0, 0,
NOTE_C7, 0, 0, NOTE_G6,
0, 0, NOTE_E6, 0,
0, NOTE_A6, 0, NOTE_B6,
0, NOTE_AS6, NOTE_A6, 0,
NOTE_G6, NOTE_E7, NOTE_G7,
NOTE_A7, 0, NOTE_F7, NOTE_G7,
0, NOTE_E7, 0, NOTE_C7,
NOTE_D7, NOTE_B6, 0, 0,
NOTE_C7, 0, 0, NOTE_G6,
0, 0, NOTE_E6, 0,
0, NOTE_A6, 0, NOTE_B6,
0, NOTE_AS6, NOTE_A6, 0,
NOTE_G6, NOTE_E7, NOTE_G7,
NOTE_A7, 0, NOTE_F7, NOTE_G7,
0, NOTE_E7, 0, NOTE_C7,
NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int tempo[] = {
12, 12, 12, 12,
12, 12, 12, 12,
12, 12, 12, 12,
12, 12, 12, 12,
12, 12, 12, 12,
12, 12, 12, 12,
12, 12, 12, 12,
12, 12, 12, 12,
9, 9, 9,
12, 12, 12, 12,
12, 12, 12, 12,
12, 12, 12, 12,
12, 12, 12, 12,
12, 12, 12, 12,
12, 12, 12, 12,
12, 12, 12, 12,
9, 9, 9,
12, 12, 12, 12,
12, 12, 12, 12,
12, 12, 12, 12,
};

//Underworld melody
int sad_melody[] = {
NOTE_AS7, NOTE_B7, NOTE_C8,
0, 0, 0
};

int sad_tempo[] = {
1, 2, 3, 1,
1, 1
};

int angry_melody[] = {
NOTE_B3, NOTE_B3, NOTE_B3,
NOTE_B3, NOTE_B3, NOTE_B3
};

int angry_tempo[] = {
1, 1, 1, 1,
1, 1
};

//Underworld tempo
int underworld_tempo[] = {
12, 12, 12, 12,
12, 12, 6,
3,
12, 12, 12, 12,
12, 12, 6,
3,
12, 12, 12, 12,
12, 12, 6,
3,
12, 12, 12, 12,
12, 12, 6,
6, 18, 18, 18,
6, 6,
6, 6,
6, 6,
18, 18, 18, 18, 18, 18,
10, 10, 10,
10, 10, 10,
3, 3, 3
};


// Pin assignmennt
int speakerPin = 1;
int left = 13;
int right = 12;
int US;
int redPin2 = 11;
int greenPin2 = 14;
int bluePin2 = 15;
int trigPin = 9;
int echoPin = 8;
int switchPin = 4;


pinMode(redPin2, OUTPUT);
pinMode(greenPin2, OUTPUT);
pinMode(bluePin2, OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(switchPin, INPUT);

int song =0;
int emotion = 0;
int reading;

int main(){
	int x = 0;
	/* while(1){
		// IR Sensor
		// reset();
		/* freqout(trigPin, 1, 38000);
		US = input(echoPin);
		print("\n US = %d\n", US);
		//switchEmotions();
		print("emotion is %d", emotion);
		reading = input(switchPin);
		default_state(x);
		if(reading == 1){
		runEmotion(emotion);
		Emotionsplusplus();
		turnRight(200,1000);
	} */
	angry();
// }
	return 0;

}


/// Setting the colour to the LEDs
void setColor(int red, int green, int blue){
	freqout(redPin2, 50, red);
	freqout(greenPin2, 50, green);
	freqout(bluePin2, 50, blue);
}

void moveForward(int speed, int time){
	servo_speed(left, speed);
	servo_speed(right, -speed);
	pause(time);
}

void moveBack(int speed, int time){
	servo_speed(left, -speed);
	servo_speed(right, speed);
	pause(time);
}

void turnRight(int speed, int time, int turnFactor) {
	servo_speed(right, -speed/turnFactor);
	servo_speed(left, speed);
	pause(time);
}

void turnLeft(int speed, int time, int turnFactor) {
	servo_speed(left, speed/turnFactor);
	servo_speed(right, -speed);
	pause(time);
}

void turn180() {
	pivot();
	pause(1000);
	stop(1);
}

void pivot(){
	servo_speed(left, 200);
	servo_speed(right, 200);
}

void pivot_o(){
	servo_speed(left, -200);
	servo_speed(right, -200);
}

void stop(int time){
	servo_speed(left, 0);
	servo_speed(right, 0);
	pause(time);
}


void flash(){
	//Lights Flashing
	setColor(255, 0, 0); // red
	pause(10);
	setColor(0, 255, 0); // green
	pause(10);
	setColor(0, 0, 255); // blue
	pause(10);
	setColor(255, 255, 0); // yellow
	pause(10);
	setColor(80, 0, 80); // purple
	pause(10);
	setColor(0, 255, 255); // aqua
	pause(10);
}

void default_state(int x){
	if(x<50){
		servo_speed(left, 200);
		servo_speed(right, -200);
		print("\n x = %d\n", x);
	}
	if(x>50 && x<51){
		turnRight(200,1000,10);
	}
	x++;
	if(x==60)
		x = 0;
}

void scared(){
	while(1){
		// Default state
		freqout(trigPin, 1, 38000);
		US = input(echoPin);
		if(US != 0)
			moveForward(100, 1000);
		else{
			printf("\nInside scared");
			stop(500);
			cog_run(scream, 128); // screaming
			//Shivering
			int y = 0;
			int t = 0;
			while(y<50){
				int e = 0;
				while(e<7){
				pivot();
				print("e = %d", e);
				e++;
			}
			int a = 0;
			while(a<7){
				pivot_o();
				a++;
			}
			y++;
		}
		cog_run(scream, 128); // screaming
		}
	}
}

void scream(){
	freqout(speakerPin, 1000, 2000);
}

void happy(){
	while(1){
		// Default state
		freqout(trigPin, 1, 38000);
		US = input(echoPin);
		if(US != 0)
			moveForward(100, 1000);

		// The actions are to first stop and then to turn around flashing different coloured lights
		// while making beeps that sound excited
		else{
			stop(500);
			int x = 0;
			while(x<3){
				pivot();
				flash();
				//sing(3);
				x++;
				print("x = %d", x);
			}
			break;
		}
	}
}

void sad() {
	// Default state
	while(1){
		freqout(trigPin, 1, 38000);
		US = input(echoPin);
		if(US != 0)
			moveForward(50, 1000);
		// Emotion
		else{
			stop(500);
			int time = 0;
			high(bluePin2);
			//low-pitched sound
			do {
				moveForward(50,100);
				//sing(2);
				time += 100;
				print("time = %d and US = %d", time, US);
			}while (time <= 5000); // replace "ir" with proper code

			turnRight(25, 2000, 10);
			turnLeft(25, 4000, 10);
			pivot();
			while (US == 1) // replace "ir" with proper code
				stop(10);
			low(bluePin2);
			break;
		}
	}
}

void angry() {
	// Default state
	for (int i = 0; i < 3; i++) {
		while(1){
			freqout(trigPin, 1, 38000);
			US = input(echoPin);
			if(US != 0)
				turnRight(200, 500, 5);
			else{
				stop(100);
				// flashing red lights
				// long beep sound
				//buzz(speakerPin, 200, 10);
				//freqout(speakerPin, 1000, 2000);
				//sing(2);
				for(int i = 0; i < 3; i++)
					angryLoop();
				turn180();
				break;
			}
		}
	}
	stop(1);
}

void angryLoop() {
	high(redPin2);
	moveBack(500,500);
	low(redPin2);
	moveForward(500,750);
}

void lethargic() {
	stop(500);
	// some dark depressing colour
	// deep slow sound, low frequency
	moveForward(100,1000);
	// more stuff
}

void reset(){
	// Reseting all the pins
	low(redPin2);
	low(bluePin2);
	low(greenPin2);
}

void sing(int s) {
	// iterate over the notes of the melody:
	song = s;
	if (song == 1) {
		//Serial.println(" 'Sad Theme'");
		int size = sizeof(sad_melody) / sizeof(int);
		for (int thisNote = 0; thisNote < 2; thisNote++) {
			// to calculate the note duration, take one second
			// divided by the note type.
			//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
			int noteDuration = 100 / sad_tempo[thisNote];
			buzz(melodyPin, sad_melody[thisNote], noteDuration);
			// to distinguish the notes, set a minimum time between them.
			// the note's duration + 30% seems to work well:
			int pauseBetweenNotes = noteDuration * 1.30;
			pause(pauseBetweenNotes/1000);
			// stop the tone playing:
			buzz(melodyPin, 0, noteDuration);
		}
	} else if (song == 2) {
		//Serial.println(" 'Angry Theme'");
		int size = sizeof(angry_melody) / sizeof(int);
		for (int thisNote = 0; thisNote < 2; thisNote++) {
			int noteDuration = 100 / angry_tempo[thisNote];
			print("\nduration = %d", noteDuration);
			buzz(melodyPin, angry_melody[thisNote], noteDuration);
			int pauseBetweenNotes = noteDuration * 1.30;
			pause(pauseBetweenNotes/1000);
			buzz(melodyPin, 0, noteDuration);
		}
	} else {
		//Mario theme song
		int size = sizeof(melody) / sizeof(int);
		for (int thisNote = 0; thisNote < 2; thisNote++) {
			int noteDuration = 100 / tempo[thisNote];
			print("\nduration = %d", noteDuration);
			buzz(melodyPin, melody[thisNote], noteDuration);
			int pauseBetweenNotes = noteDuration * 1.30;
			print("Inside sing");
			pause(pauseBetweenNotes/1000);
			buzz(melodyPin, 0, noteDuration);
		}
	}
}

void buzz(int targetPin, long frequency, long length) {
	long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
	//// 1 second's worth of microseconds, divided by the frequency, then split in half since
	//// there are two phases to each cycle
	long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
	// print("numCycles is %d
	//// multiply frequency, which is really cycles per second, by the number of seconds to
	//// get the total number of cycles to produce
	print("Inside buzz");
	for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
		freqout(speakerPin, length, frequency);
		pause(delayValue); // wait again or the calculated delay value
	}

}

void Emotionsplusplus(){
	emotion++;
	if(emotion == 5)
		emotion = 0;
}

void runEmotion(int emotion) {
	switch (emotion) {
	case 0:
		happy();
		print("case 0");
		break;
	case 1:
		sad();
		print("case 1");
		break;
	case 2:
		angry();
		print("case 2");
		break;
	case 3:
		scared();
		print("case 3");
		break;
	case 4:
		lethargic();
		print("case 4");
		break;
	}
}


