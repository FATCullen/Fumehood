const int photopin = 3;
const int irpin = 14;
const int hallpin = 4;
const int alarmpin = 2;

const int sensor = 0;

int threshhold = 511;
int samplerate = 50;
int alarmtime = 2000;
int cooldown = 2000;
int val = 0;

void setup() {
    Serial.begin(9600);
    pinMode(alarmpin, OUTPUT);
    digitalWrite(alarmpin, LOW);
    pinMode(photopin, INPUT_PULLUP);
    pinMode(irpin, INPUT);
    pinMode(hallpin, INPUT);

}

void loop() {
    if(sensor == 0) {
        Serial.println(digitalRead(photopin));
        if(digitalRead(photopin) == HIGH) {
            digitalWrite(alarmpin, HIGH);
            delay(alarmtime);
            digitalWrite(alarmpin, LOW);
            delay(cooldown);
        }
    }
    if(sensor == 1) {
        val = analogRead(irpin);
        Serial.println(val);
        if(val > threshhold) {
            digitalWrite(alarmpin, HIGH);
            delay(alarmtime);
            digitalWrite(alarmpin, LOW);
            delay(cooldown);
        }
    }
    if(sensor == 2) {
        Serial.println(digitalRead(hallpin));
        if(digitalRead(hallpin) == LOW) {
            digitalWrite(alarmpin, HIGH);
            delay(alarmtime);
            digitalWrite(alarmpin, LOW);
            delay(cooldown);
        }
    }
    delay(samplerate);
}