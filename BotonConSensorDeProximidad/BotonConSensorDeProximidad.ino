#define BOTON 3
#define TRIGGER 8
#define ECHO 9
#define ANTIREBOTE 200

int EstadoBoton = 0;
unsigned long tiempoEspera = 0;

typedef enum
{
  NoHaceNada,
  Mostrando
}enciende;

  enciende estado = NoHaceNada;

void setup() 
{
  Serial.begin(9600);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BOTON, INPUT_PULLUP);
  digitalWrite(TRIGGER, LOW);
  attachInterrupt(digitalPinToInterrupt(BOTON), GestionarEstadoBoton, FALLING);
}

void loop() 
{
  long t;
  long d;
  switch(estado)
  {
    case NoHaceNada:

    break;

    case Mostrando:
    unsigned long tiempoMostrando = 0;
      digitalWrite(TRIGGER, HIGH);
      delayMicroseconds(10);
      digitalWrite(TRIGGER, LOW);

      t = pulseIn(ECHO, HIGH);
      d = t / 59;

      Serial.print("Distancia: ");
      Serial.print(d);
      Serial.print(" cm");
      Serial.println();
      delay(100);
      tiempoMostrando = millis();
      if (tiempoMostrando - tiempoEspera >= 5000)
      {
        tiempoEspera = millis();
        estado = NoHaceNada;
      }
    break;
  }
}

void GestionarEstadoBoton() 
{
  if (millis() - tiempoEspera > ANTIREBOTE) 
  {
    estado = Mostrando;
    tiempoEspera=millis();
  }
}
