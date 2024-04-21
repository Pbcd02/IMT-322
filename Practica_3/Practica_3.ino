//Definiciones de pines (Arduino)
#define PULSADOR1 2
#define PULSADOR2 3
#define LED 4
//Variables para la ejecucion del codigo
#define ANTIREBOTE 200

int EstadoBoton = 0;
int Contador = 0;
unsigned long tiempoEspera = 0;

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
}
void incremento()
{
  //Se inicia el antirrebote
  if(millis()-tiempoEspera > ANTIREBOTE)
  {
    Contador++;
    tiempoEspera=millis();
  }
}
void cambioDelay()
{
  //Se inicia el antirrebote
  if(millis()-tiempoEspera > ANTIREBOTE)
  {
    //Con cada if se cambia la frecuencia de parpadeo del LED
    if(TD==200)
    {
      TD = 800;
    }
    else if(TD==800)
    {
      TD = 1500;
    }
    else
    {
      TD = 200;
    }
    tiempoEspera=millis();
  }
}

