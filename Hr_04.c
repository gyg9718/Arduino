#define TRIG 7
#define ECHO 6
int green = 8;

void setup() {
 
  
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(green, OUTPUT);


}

void loop()
{
  long duration, distance;

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2); # 
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration *17/1000;

  Serial.println(duration);
  Serial.print("\nDistance:");
  Serial.print(distance);
  Serial.println("CM");
  if(distance >= 10){
    digitalWrite(green, HIGH);
    delay(1000);
    digitalWrite(green, LOW);
  }
  delay(1000);
}
