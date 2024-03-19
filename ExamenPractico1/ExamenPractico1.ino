// Definición de pines para los pulsadores
#define PULSADOR_PLAY 3
#define PULSADOR_ALEATORIO 4
#define PULSADOR_SUBIR 5
#define PULSADOR_BAJAR 6

//Definimos las variables y constantes
int cancion = 0;
int volumen = 5;
bool aleatorio = false;
bool pausa = false;
unsigned long lastButtonPressTime = 0;
const int LONG_PRESS = 3000;
int CONTADOR = 30;

void setup() 
{
  Serial.begin(9600);
  pinMode(PULSADOR_PLAY, INPUT);
  pinMode(PULSADOR_ALEATORIO, INPUT);
  pinMode(PULSADOR_SUBIR, INPUT);
  pinMode(PULSADOR_BAJAR, INPUT);
}
void loop() 
{
  Serial.print("Temporizador: ");
  Serial.println(CONTADOR);
  delay(1000);
  CONTADOR--;

  if (digitalRead(PULSADOR_SUBIR) == LOW) 
  {
    if (millis() - lastButtonPressTime > LONG_PRESS) 
    {
      lastButtonPressTime = millis();
      Serial.println("Siguiente canción");
    } 
    else 
    {
      volumen = min(volumen + 1, 10);
    }
  }

  if (digitalRead(PULSADOR_BAJAR) == LOW) 
  {
    if (millis() - lastButtonPressTime > LONG_PRESS) 
    {

      lastButtonPressTime = millis();
      Serial.println("Canción anterior");
    } 
    else 
    {
      volumen = max(volumen - 1, 0);
    }
  }
}