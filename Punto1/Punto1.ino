
#define LED1 4
#define LED2 5
#define LED3 2
#define TIEMPOAPAGAR 200


void setup() 
{
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
}

void loop() {

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
