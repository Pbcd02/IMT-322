#define ROJO 4
#define AMARILLO 3
#define VERDE 2

#define TR 1500
#define TA 500
#define TV 1500

int CAMBIO = 0;
unsigned long tiempoInicio;

typedef enum
{
  Rojo,
  Amarillo,
  Verde
}semaforo;

  semaforo estado = Rojo;

void setup() 
{
  pinMode(ROJO, OUTPUT);
  pinMode(AMARILLO, OUTPUT);
  pinMode(VERDE, OUTPUT);
}

void loop() 
{
  switch (estado) 
  {
    case Rojo:
      digitalWrite(ROJO, HIGH);
      digitalWrite(AMARILLO, LOW);
      digitalWrite(VERDE, LOW);
      if (millis() - tiempoInicio >= TR) 
      {
        tiempoInicio = millis();
        estado = Verde;
      }
      break;

    case Verde:
      digitalWrite(ROJO, LOW);
      digitalWrite(AMARILLO, LOW);
      digitalWrite(VERDE, HIGH);
      if (millis() - tiempoInicio >= TV) 
      {
        tiempoInicio = millis();
        estado = Amarillo;
      }
      break;

    case Amarillo:
      digitalWrite(ROJO, LOW);
      digitalWrite(AMARILLO, HIGH);
      digitalWrite(VERDE, LOW);
      if (millis() - tiempoInicio >= TA) 
      {
        tiempoInicio = millis();
        estado = Rojo;
      }
      break;
  }
}

