#define LED1 3
#define LED2 4
#define LED3 5
#define ESPERA 10
#define DELAYELEVADOR 2000

int LLAMADO = 0;
char dato;

typedef enum
{
  Piso1,
  Piso2,
  Piso3
}elevador;

  elevador estado = Piso1;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
}

void loop() 
{
  if(Serial.available()>0)
  {
    dato=Serial.read();
  }
  switch(estado)
  {
    case Piso1:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      if(dato=='1') 
      {
        Serial.println("Subiendo...");
        delay(DELAYELEVADOR);
        estado = Piso2;
        Serial.println("Haz llegado al piso 2");
      }
      else if(dato=='2')
      {
        Serial.println("Subiendo...");
        delay(DELAYELEVADOR);
        estado = Piso3;
        Serial.println("Haz llegado al piso 3");
      }
    break;

    case Piso2:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      if(dato=='0') 
      {
        Serial.println("Bajando...");
        delay(DELAYELEVADOR);
        estado = Piso1;
        Serial.println("Haz llegado al piso 1");
      }
      else if(dato=='2')
      {
        Serial.println("Subiendo...");
        delay(DELAYELEVADOR);
        estado = Piso3;
        Serial.println("Haz llegado al piso 3");
      }
    break;

    case Piso3:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      if(dato=='0') 
      {
        Serial.println("Bajando...");
        delay(DELAYELEVADOR);
        estado = Piso1;
        Serial.println("Haz llegado al piso 1");
      }
      else if(dato=='1')
      {
        Serial.println("Bajando...");
        delay(DELAYELEVADOR);
        estado = Piso2;
        Serial.println("Haz llegado al piso 2");
      }
    break;
  }
}