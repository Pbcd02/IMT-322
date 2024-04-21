#define BOTON 3
#define TRIGGER 8
#define ECHO 9
#define ANTIREBOTE 200

int EstadoBoton = 0;
int Contador = 0;
unsigned long tiempoEspera = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BOTON, INPUT);
  digitalWrite(TRIGGER, LOW);
  attachInterrupt(digitalPinToInterrupt(BOTON), GestionarEstadoBoton, FALLING);
}

void loop() {
  if (digitalRead(BOTON) == LOW) {
    long t;
    long d;

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
  }
}

void GestionarEstadoBoton() { // Cambiado el nombre de la función
  if (millis() - tiempoEspera > ANTIREBOTE) 
  {
    tiempoEspera = millis();
  }
}
