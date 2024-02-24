#define LED 0
int led1 = 0;
int led2 = 1;
int led3 = 2;

void setup() 
{
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop() {
  digitalWrite(led1,HIGH);
  delay(200);
  digitalWrite(led1,LOW);

  digitalWrite(led2,HIGH);
  delay(200);
  digitalWrite(led2,LOW);

  digitalWrite(led3,HIGH);
  delay(200);
  digitalWrite(led3,LOW);

  delay(200);
}
