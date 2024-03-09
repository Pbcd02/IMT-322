//Definimos los pines a utilizar (Arduino)
#define LED1 4
#define LED2 5 
#define LED3 2
//Definimos el tiempo para el parpadeo de cada LED
#define TIEMPOAPAGAR 200

void setup() 
{
  //Se configuran los pines como salidas
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
}

void loop() 
{
  //Encendido Primer LED
  digitalWrite(LED1,HIGH);
  delay(TIEMPOAPAGAR);
  digitalWrite(LED1,LOW);

  //Encendido Segundo LED
  digitalWrite(LED2,HIGH);
  delay(TIEMPOAPAGAR);
  digitalWrite(LED2,LOW);

  //Encendido Tercer LED
  digitalWrite(LED3,HIGH);
  delay(TIEMPOAPAGAR);
  digitalWrite(LED3,LOW);

  //Retardo para el reinicio del ciclo
  delay(TIEMPOAPAGAR);
}
