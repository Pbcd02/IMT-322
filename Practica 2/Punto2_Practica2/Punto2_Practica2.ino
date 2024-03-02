#define Pulsador 2
#define Salida 3
#define ledCont 7
int contador = 0;

void setup() 
{
  pinMode(Pulsador, INPUT_PULLUP);
  pinMode(Salida, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(Pulsador), incremento, FALLING);
  Serial.begin(9600);
}
void loop() 
{
  ledsito();
  Serial.println(contador);
  if (contador % 2 == 1) 
  {
    digitalWrite(ledCont, HIGH);
  } 
  else 
  {
    digitalWrite(ledCont, LOW);
  }
}
void incremento()
{
  contador++;
}
void ledsito() 
{
  digitalWrite(Salida, HIGH);
  delay(300);
  digitalWrite(Salida, LOW);
  delay(300);
}