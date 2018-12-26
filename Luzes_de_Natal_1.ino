/*Luzes de natal
 * 
 * Uma mini arvore com 15 leds, que piscam independentes, esse sketch controla os leds, fazendo-os piscar seguindo sequências.
 * 
 * Data de criação: 22/12/2018
 * Ultima atualização: 23/12/2018 - 22h00
 * 
 * Multifunções: Não, ou seja, usa a função delay.
 * 
 * Atualizações:
 *  22/12/2018
 * -desenvolvimento da matriz "vet"
 * -função a() Sequência Acende todos, apaga todos
 *  23/12/2018
 * -função a() Sequência acende um por vez
 * -função b()
 * -função c()
 * -função d()
 * -debug
 */

// ==============================================
// =          Matriz com as sequências          =
// ============================================== 

byte vet[30][15]= {
  {2, 7, 11, 14, 16, 15, 12, 8, 3, 4, 9, 13, 10, 5, 6},
  {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16},
  {2, 3, 4, 5, 6, 10, 9, 8, 7, 11, 12, 13, 15, 14, 16},
  {2, 3, 4, 5, 6, 10, 13, 15, 16, 14, 11, 7, 8, 9, 12},
  {2, 3, 7, 11, 8, 4, 5, 9, 12, 14, 16, 15, 13, 10, 6},
  {2, 3, 7, 4, 8, 11, 5, 9, 12, 14, 6, 10, 13, 15, 16},
  {2, 7, 3, 4, 8, 11, 14, 12, 9, 5, 6, 10, 13, 15, 16},
  {2, 7, 3, 11, 8, 4, 14, 12, 9, 5, 16, 15, 13, 10, 6},
  {2, 7, 11, 14, 16, 15, 13, 10, 6, 5, 4, 3, 8, 12, 9},
  {6, 5, 4, 3, 2, 10, 9, 8, 7, 13, 12, 11, 15, 14, 16},
  {6, 5, 4, 3, 2, 7, 8, 9, 10, 13, 12, 11, 14, 15, 16},
  {6, 10, 5, 13, 9, 4, 15, 12, 8, 3, 16, 14, 11, 7, 2},
  {6, 5, 10, 13, 9, 4, 3, 8, 12, 15, 16, 14, 11, 7, 2},
  {6, 10, 5, 4, 9, 13, 15, 12, 8, 3, 2, 7, 11, 14, 16},
  {6, 5, 4, 3, 2, 7, 11, 14, 16, 15, 13, 10, 9, 8, 12},
  {6, 10, 13, 15, 16, 14, 11, 7, 2, 3, 4, 5, 9, 12, 8},
  {16, 15, 13, 10, 6, 5, 4, 3, 2, 7, 11, 14, 12, 9, 8},
  {16, 14, 11, 7, 2, 3, 4, 5, 6, 10, 13, 15, 12, 8, 9},
  {2, 7, 11, 14, 16, 15, 13, 10, 6, 5, 9, 12, 8, 3, 4},
  {2, 7, 11, 14, 16, 15, 13, 10, 6, 5, 9, 12, 8, 4, 3},
  {2, 3, 4, 5, 6, 10, 13, 15, 16, 14, 12, 9, 8, 7, 11},
  {2, 3, 4, 5, 6, 10, 13, 15, 16, 14, 12, 9, 8, 11, 7},
  {6, 5, 4, 3, 2, 7, 11, 14, 16, 15, 12, 8, 9, 10, 13},
  {6, 5, 4, 3, 2, 7, 11, 14, 16, 15, 12, 8, 9, 13, 10},
  {6, 10, 13, 15, 16, 14, 11, 7, 2, 3, 8, 12, 9, 5, 4},
  {6, 10, 13, 15, 16, 14, 11, 7, 2, 3, 8, 12, 9, 4, 5},
  {16, 15, 13, 10, 6, 5, 4, 3, 2, 7, 8, 9, 12, 11, 14},
  {16, 15, 13, 10, 6, 5, 4, 3, 2, 7, 8, 9, 12, 14, 11},
  {16, 14, 11, 7, 2, 3, 4, 5, 6, 10, 9, 8, 12, 15, 13},
  {16, 14, 11, 7, 2, 3, 4, 5, 6, 10, 9, 8, 12, 13, 15},
};
//Na matriz estão os pinos do Arduino, na sequência que desejamos que acenda [ao menos na função a()]

// =========================================
// =          Variaveis e Defines          =
// =========================================

int i; //seleciona a coluna da matriz
int j; //seleciona a linha da matriz
bool tipoInverte; // 

#define tempo 100

// ===========================
// =          SETUP          =
// ===========================

void setup() {
  for (i = 2; i <= 16; i++){
    pinMode (i, OUTPUT);
  }
  randomSeed(analogRead(A5));
}

// ==========================
// =          LOOP          =
// ==========================

void loop() {
    switch (random(0, 8)){
    case 4:
      b();
      break;
    case 5:
      c();
      break;
    case 6:
      d();
      break;
    case 7:
      d();
      break;
    default:
      a();
      break;
  }
}

// ====================================
// =          FUNÇÃO INVERTE          =
// ====================================

void  inverte(){ // função para inverter estado do led
  if (tipoInverte){
    digitalWrite(vet[j][i], HIGH);
    delay (2*tempo);
    digitalWrite(vet[j][i], LOW);
  }
  
  else{
    digitalWrite(vet[j][i], !digitalRead(vet[j][i])); //Lê o estado do led e inverte [Se está ligado, desliga, e vice versa]
    delay (tempo); 
  }
}

// ==============================
// =          FUNÇÃO A          =
// ==============================

void a(){
  bool aux = random (0, 2); // Essa variável "auxiliar" pede para ler a sequência de trás para frente, dessa forma dobramos o número de sequência da matriz.
  tipoInverte = random (0, 2); //Sorteia a forma de inverter o estado do led, se acenderão todos para depois apagar, ou se acenderá um por vez
        
  j = random(0, 31); // Sorteia uma sequência na matriz
  
  for (byte k = tipoInverte; k<=1; k++){
        
    if (aux){
      for (i = 0; i <= 14; i++){
        inverte();
      }
      aux = !aux; 
    }
    else {
      for (i = 14; i >= 0; i--){
        inverte();
      }
      aux = !aux;
    }
  delay(2*tempo);
  }  
}

// ==============================
// =          FUNÇÃO B          =
// ==============================

void b(){ // Essa função faz os leds acenderem circulando a arvore (com dois leds acessos)
  byte aux = random(0, 6);

  switch (aux){
    case 0:
      j=3;
      break;
    case 1:
      j=8;
      break;
    case 2:
      j=14;
      break;
    case 3:
      j=15;
      break;
    case 4:
      j=16;
      break;
    case 5:
      j=17;
      break;
  }
  
  byte k= random(0,2);

  if(k ==0){
  
    for (i=0; i<=11; i++){
      digitalWrite(vet[j][i%12], !digitalRead(vet[j][i%12]));
      digitalWrite(vet[j][(i+6)%12], !digitalRead(vet[j][(i+6)%12]));
      delay(2*tempo);
      digitalWrite(vet[j][i%12], !digitalRead(vet[j][i%12]));
      digitalWrite(vet[j][(i+6)%12], !digitalRead(vet[j][(i+6)%12]));
    }
  }
  else{
    for (i=11; i>=0; i--){
      digitalWrite(vet[j][i%12], !digitalRead(vet[j][i%12]));
      digitalWrite(vet[j][(i+6)%12], !digitalRead(vet[j][(i+6)%12]));
      delay(2*tempo);
      digitalWrite(vet[j][i%12], !digitalRead(vet[j][i%12]));
      digitalWrite(vet[j][(i+6)%12], !digitalRead(vet[j][(i+6)%12]));
    }
  }
}

// ==============================
// =          FUNÇÃO C          =
// ==============================

void c(){// Faz a arvore "crescer", acendendo 1 led, um triangulo médio e a arvore toda. 
  j = 18;
  for (byte k=0; k<=3; k++){
    for (i = 14; i >= 0; i--){    
      digitalWrite(vet[j][i], !digitalRead(vet[j][i]));;
      if(i==14 || i==9 || i ==0){
        delay(4*tempo);
      }
    }
  }
}
// Lembrete: Desenvolver mais essa função, para que ela cresça e diminua

// ==============================
// =          FUNÇÃO D          =
// ==============================

void d(){
  j=3;
  byte aux = 2;
  bool sorteio = random (0, 2);
  for (byte k=0; k<=8; k++){
    aux = (aux+1) % 3;
    for(i=0; i<=11 + sorteio*3; i++){
      if (i % 3 == aux){
        digitalWrite(vet[j][i],HIGH);
      }
      else{
        digitalWrite(vet[j][i],LOW);
      }
    }
    delay((4+2*sorteio)*tempo);
  }
  for (i=0; i<=14; i++){
    digitalWrite(vet[j][i], LOW);
  }
}
