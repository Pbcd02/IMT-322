
#define LED1 4
#define LED2 5
#define LED3 2
#define USER_BOTTON 3
#define TIEMPOAPAGAR 200
int secuencia = 1;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(USER_BOTTON, INPUT_PULLUP);
}

void loop() {
  if(secuencia==1)
  {
  digitalWrite(LED1,HIGH);
  delay(TIEMPOAPAGAR);
  digitalWrite(LED1,LOW);

  digitalWrite(LED2,HIGH);
  delay(TIEMPOAPAGAR);
  digitalWrite(LED2,LOW);

  digitalWrite(LED3,HIGH);
  delay(TIEMPOAPAGAR);
  digitalWrite(LED3,LOW);

  delay(TIEMPOAPAGAR);
  }
  if (secuencia==2)
  {
    digitalWrite(LED1,HIGH);
    delay(TIEMPOAPAGAR);
    digitalWrite(LED1,LOW);

    digitalWrite(LED3,HIGH);
    delay(TIEMPOAPAGAR);
    digitalWrite(LED3,LOW);

    digitalWrite(LED2,HIGH);
    delay(TIEMPOAPAGAR);
    digitalWrite(LED2,LOW);

    delay(TIEMPOAPAGAR);
  }
  if (digitalRead(USER_BOTTON)==LOW)
    {
      secuencia++;
      if (secuencia > 2)
      {
        secuencia = 1;
      }
    }
  Serial.println(secuencia);
}
