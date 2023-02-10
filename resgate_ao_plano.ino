//codigo resgate ao plano
//sensor 1 detector de cor preta no plano
//sensor 2 detectar após "buraco" e segue em frente procurando a linha preta
//sensor 3 ultrassonico para detectar objeto similar a caixa de leite que será revestida na cor preta
//o sensor 3 indica objeto, o robô irá dar a volta pelo obstáculo 
//virar 90, anda um pouco, vira -90, anda um pouco e depois corrige a tragetória para linha reta
// o robo irá encontrar uma lata, a lata estará na cor branca, precisa pegar a lata com uma garra, fechar a garra e transportar a lata branca
//forma geométrica na cor preta, o robô precisa largar a lata
//Define os pinos do Arduino D8 e D9 como porta do ECHO e TRIGGER  
#define Sen1_TRIGGER 3
#define Sen1_ECHO 4
#define LED_MOVIMENTO 7

float distancia1 = 0; 
float tempo1  = 0;
int INFRASENSOR = A0;
int INFRASENSORBOOLEAN = 2;
volatile bool estado = false;
int dist = 0;
int controller = 0;
int corBooleano = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(INFRASENSOR,INPUT);
  pinMode(INFRASENSORBOOLEAN,INPUT);
  pinMode(LED_MOVIMENTO,OUTPUT);
  pinMode(Sen1_TRIGGER, OUTPUT);
  digitalWrite(Sen1_TRIGGER, LOW);
  pinMode(Sen1_ECHO, INPUT);
}

void loop() {
  Serial.begin(9600);
  dist = analogRead(INFRASENSOR);
  digitalWrite(Sen1_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(Sen1_TRIGGER, LOW);
  tempo1=pulseIn(Sen1_ECHO, HIGH);
  tempo1=tempo1/1000000;
  distancia1=(tempo1 * 340)/2;
  corBooleano = digitalRead(INFRASENSORBOOLEAN);
  Serial.print("Distancia: ");
  Serial.println(distancia1);
  Serial.print("Deteccao de Cor analógico: ");
  Serial.println(dist);
  Serial.print("Detecçaõ cor preto e branco: ");
  Serial.println(corBooleano);
  delay(1000);



}
