//Definimos los pines a utilizar (Arduino)
#define LED1 4
#define LED2 5
#define LED3 2
#define USER_BOTTON 3
//Encendido de cada LED en milisegundos
#define TIEMPOAPAGAR 200
//con esta variable controlaremos la secuencia de LEDs
int secuencia = 1;

void setup() 
{
  //Inicia la comunicación serial
  Serial.begin(9600);
  //Configuramos a los pines como salidas
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  //Configuramos el pin del botón como entrada con resistencia pull-up
  pinMode(USER_BOTTON, INPUT_PULLUP);
}

void loop() {
  //Se inicializa la primera secuencia LED1, LED2, LED3
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
   //Se inicializa la segunda secuencia LED1, LED3, LED2
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
      //Cambiamos la secuencia cuando se presione el boton
      secuencia++;
      if (secuencia > 2)
      {
        //Reinicia la secuencia al llegar al final
        secuencia = 1;
      }
    }
  Serial.println(secuencia);
}
