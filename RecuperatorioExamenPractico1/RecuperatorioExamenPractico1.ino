#define PULSADOR1 3
#define PULSADOR2 4
#define LED1 5
#define LED2 6
#define BAUDRATE 9600
#define ANTIREBOTE1 200
#define ANTIREBOTE2 200
#define ESPERA1 20000
#define ESPERA2 20000

int estadoPulsador1 = HIGH;
unsigned long tiempoEspera1 = 0;
unsigned long tiempoEspera2 = 0;
bool PulsoContra = false;
const int tcon = 16;
char contra[tcon+1];
int posicionContra = 0;
bool S = false;
typedef enum {
  Inicio,
  EsperaContra,
  Contra,
  Reinicio,
  BajoConsumo
} Sistema;

Sistema estado = Inicio;
void setup() {
  Serial.begin(BAUDRATE);
  pinMode(PULSADOR1, INPUT_PULLUP);
  pinMode(PULSADOR2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PULSADOR1), iniciando, FALLING);
  attachInterrupt(digitalPinToInterrupt(PULSADOR2), reset, FALLING);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1, HIGH);
}

void loop() 
{
  switch (estado) 
  {
    case Inicio:
    Serial.println("Bievenido al Sistema");
    Serial.println("Ingrese contraseña caracter por caracter");
    estado=EsperaContra;

    break;

    case EsperaContra:
    if(Serial.available()>0)
    {
      char lectura=Serial.read();
      tiempoEspera1=millis();
      if(millis()-tiempoEspera1 < ESPERA1)
      {
        if(posicionContra<tcon)
        {
          contra[posicionContra]=lectura;
          posicionContra++;
          Serial.print(lectura);
        }
        if(posicionContra==tcon)
        {
          contra[posicionContra]='\0';
          Serial.println();
          Serial.println("bien!");
          Serial.println("Se recibio la contraseña: ");
          Serial.print(contra[0]);
          Serial.print(contra[2]);
          Serial.print(contra[4]);
          Serial.print(contra[6]);
          Serial.print(contra[8]);
          Serial.print(contra[10]);
          Serial.print(contra[12]);
          Serial.print(contra[14]);
          Serial.println(contra[16]);
          estado=Contra;
          unsigned long tiempoEspera1 = millis();
          Serial.println(estado);
          
        }
        }
    }
    break;
    case Contra:

    break;

    case Reinicio:

      break;

    case BajoConsumo:

      break;
  }
}
void iniciando() {
  PulsoContra = true;
}
void reset() {
  estado = Inicio;
}