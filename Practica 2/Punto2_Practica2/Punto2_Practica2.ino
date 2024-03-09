//Definiciones de pines (Arduino)
#define PULSADOR 2
#define SALIDA 3
#define LEDCONT 7
//Contador de pulsaciones del boton
int contador = 0;

void setup()
{
  //Configura el pin del pulsador como entrada con resistencia pull-up
  pinMode(PULSADOR, INPUT_PULLUP);
  //Configura el pin de salida, es decir el LED
  pinMode(SALIDA, OUTPUT);
  //Se asigna una interrupción en el flanco de bajada (Cuando el botón esta presionado)
  attachInterrupt(digitalPinToInterrupt(PULSADOR), incremento, FALLING);
  //Inicia la comunicación serial
  Serial.begin(9600);
}
void loop() 
{
  ledsito();
  Serial.println(contador);
  //Tenemos una condicion si el contador es impar encendera el LED
  if (contador % 2 == 1) 
  {
    digitalWrite(LEDCONT, HIGH);
  }
  //Tenemos una condicion si el contador es par apagara el LED
  else 
  {
    digitalWrite(LEDCONT, LOW);
  }
}
void incremento()
{
  contador++;
}
void ledsito() 
{
  digitalWrite(SALIDA, HIGH);
  delay(300);
  digitalWrite(SALIDA, LOW);
  delay(300);
}