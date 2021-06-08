int echo = 3;
int trigger = 2;
bool echoLevel = 0;
int distance;
int duration1;
int duration2;

void setup() {
  // put your setup code here, to run once:
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(trigger, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger, LOW);
 echoLevel = digitalRead(echo);
 
 while (echoLevel == 0) {
  echoLevel = digitalRead(echo);
 }
 
  duration1 = micros();
  
  while (echoLevel == 1) {
    echoLevel = digitalRead(echo);
  }
  
  duration2 = micros();

  distance = (duration2 - duration1)/58;

  Serial.println(distance);
  
}
