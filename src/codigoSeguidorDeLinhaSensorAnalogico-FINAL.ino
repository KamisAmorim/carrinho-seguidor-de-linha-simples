#define sensorDireito A3
#define sensorEsquerdo A2

#define motorDireitoFrente 2
#define motorDireitoTras 3
#define motorEsquerdoFrente 4
#define motorEsquerdoTras 5

int leituraD = 0;
int leituraE = 0;
int limite = 100;

void moverFrente() {
  digitalWrite(motorEsquerdoFrente, HIGH);
  digitalWrite(motorEsquerdoTras, LOW);
  digitalWrite(motorDireitoFrente, HIGH);
  digitalWrite(motorDireitoTras, LOW);
}

void virarEsquerda() {
  digitalWrite(motorEsquerdoFrente, LOW);
  digitalWrite(motorEsquerdoTras, HIGH);
  digitalWrite(motorDireitoFrente, HIGH);
  digitalWrite(motorDireitoTras, LOW);
}

void virarDireita() {
  digitalWrite(motorEsquerdoFrente, HIGH);
  digitalWrite(motorEsquerdoTras, LOW);
  digitalWrite(motorDireitoFrente, LOW);
  digitalWrite(motorDireitoTras, HIGH);
}

void parar() {
  digitalWrite(motorEsquerdoFrente, LOW);
  digitalWrite(motorEsquerdoTras, LOW);
  digitalWrite(motorDireitoFrente, LOW);
  digitalWrite(motorDireitoTras, LOW);
}


void setup() {
  //configurando sensor
  pinMode(sensorDireito, INPUT);
  pinMode(sensorEsquerdo, INPUT);
  Serial.begin(9600);

  // Configurando os pinos dos motores como saída
  pinMode(motorEsquerdoFrente, OUTPUT);
  pinMode(motorEsquerdoTras, OUTPUT);
  pinMode(motorDireitoFrente, OUTPUT);
  pinMode(motorDireitoTras, OUTPUT);
}

void loop() {
  leituraD = analogRead(sensorDireito);
  leituraE = analogRead(sensorEsquerdo);
  
  Serial.print("Leitura do sensor direito: ");
  Serial.println(leituraD);
  Serial.print("Leitura do sensor esquerdo: ");
  Serial.println(leituraE);

  if(leituraD <= limite && leituraE <= limite){
      Serial.println("Entrei no pra frente");
      moverFrente();
      delay(50);
      parar();
      delay(10);
  }
  else if(leituraD > leituraE){
    Serial.println("virando pra direita");
    virarDireita();
    delay(60);
    parar();
    delay(10);
  }
  else if(leituraD < leituraE){
    Serial.println("virando pra esquerda");
    virarEsquerda();
    delay(60);
    parar();
    delay(10);
  }
}
