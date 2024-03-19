#define PULSADOR1 2
#define PULSADOR2 3
#define LED 4
#define ANTIREBOTE 200
#define TIEMPOPULSACION 3000

int TD = 200;
int Contador = 0;
bool reinicioPulsado = false;
unsigned long tiempoEspera = 0;
unsigned long tiempoPulsado = 0;
unsigned long tiempoUltimaPulsacion = 0;

void setup() 
{
  pinMode(PULSADOR1, INPUT_PULLUP);
  pinMode(PULSADOR2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PULSADOR1), incremento, FALLING);
  attachInterrupt(digitalPinToInterrupt(PULSADOR2), cambioDelay, FALLING);
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}
void loop() 
{
  //Encendido y apagado del LED
  Serial.println(Contador);
  digitalWrite(LED, HIGH);
  delay(TD);
  digitalWrite(LED, LOW);
  delay(TD);

  //Reiniciar contador con pulsación larga
  if (reinicioPulsado) 
  {
    Contador = 0;
    reinicioPulsado = false;
  }
}
void incremento()
{
  if (millis() - tiempoEspera > ANTIREBOTE)
  {
    unsigned long tiempoActual = millis();
    //Verificar si ha pasado el tiempo de pulsación
    if (tiempoActual - tiempoUltimaPulsacion >= TIEMPOPULSACION) 
    {
      Contador = 0;
      Serial.println("Reiniciando contador");
    } 
    else 
    {
      Contador++;
    }
    tiempoUltimaPulsacion = tiempoActual; // Actualizar el tiempo de la última pulsación
  }
}
void cambioDelay()
{
  static unsigned long tiempoPulsacion2 = 0; //para almacenar el tiempo de inicio de la pulsación de PULSADOR2
  unsigned long tiempoActual = millis();

  if (digitalRead(PULSADOR2) == LOW) 
  {
    if (tiempoActual - tiempoPulsacion2 >= TIEMPOPULSACION) 
    {
      if (TD == 200) 
      {
        TD = 800;
      } 
      else if (TD == 800) 
      {
        TD = 1500;
      } 
      else 
      {
        TD = 200;
      }
      tiempoPulsacion2 = tiempoActual; // Actualizar el tiempo de inicio de la pulsación
    } 
    else 
    {
      Contador--;
    }
  } 
  else 
  {
    tiempoPulsacion2 = 0; 
    //Se reinicia el tiempo de inicio de la pulsación de PULSADOR2 si el pulsador se suelta
  }
}

