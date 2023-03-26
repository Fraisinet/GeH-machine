// Description: Code pour la machine des Genie en Herbe de l'ETS
// Proprietaire de la machine: Jeux de genie ETS
// CPU: Arduino Every (ne fonctionne pas avec des Arduino Nano)
// Auteur: Yoann Scrosati
// Date: 11/04/2022

// Definitions de pins
#define BTN1A (12)
#define BTN2A (11)
#define BTN3A (10)
#define BTN4A (9)

#define BTN1B (8)
#define BTN2B (7)
#define BTN3B (6)
#define BTN4B (5)

#define LED1A (14)
#define LED2A (15)
#define LED3A (16)
#define LED4A (17)

#define LED1B (18)
#define LED2B (19)
#define LED3B (20)
#define LED4B (21)

#define BTN_TOP (3)
#define BTN_RST (2)
// Initialisation des masks
#define MASK_BTN1A (0x01)
#define MASK_BTN2A (0x02)
#define MASK_BTN3A (0x04)
#define MASK_BTN4A (0x08)

#define MASK_BTN1B (0x10)
#define MASK_BTN2B (0x20)
#define MASK_BTN3B (0x40)
#define MASK_BTN4B (0x80)

#define MASK_EMPTY (0x00)

#define INT_CHANGE (FALLING)
#define INPUT_BTN (INPUT_PULLUP)

volatile uint8_t state = 0;

void setup() {
  // Initialisation des boutons de l'equipe A
  pinMode(BTN1A, INPUT_BTN);
  pinMode(BTN2A, INPUT_BTN);
  pinMode(BTN3A, INPUT_BTN);
  pinMode(BTN4A, INPUT_BTN);
  // Initialisation des boutons de l'equipe B
  pinMode(BTN1B, INPUT_BTN);
  pinMode(BTN2B, INPUT_BTN);
  pinMode(BTN3B, INPUT_BTN);
  pinMode(BTN4B, INPUT_BTN);
  // Initialisation des lumieres de reponse
  pinMode(LED1A, OUTPUT);
  pinMode(LED2A, OUTPUT);
  pinMode(LED3A, OUTPUT);
  pinMode(LED4A, OUTPUT);
  pinMode(LED1B, OUTPUT);
  pinMode(LED2B, OUTPUT);
  pinMode(LED3B, OUTPUT);
  pinMode(LED4B, OUTPUT);
  // Initialisation des boutons de reset
  pinMode(BTN_TOP, INPUT_BTN);
  pinMode(BTN_RST, INPUT_BTN);
  // Initialisation des subroutines d'interruption
  attachInterrupt(digitalPinToInterrupt(BTN1A), ISR_BTN1A, INT_CHANGE);
  attachInterrupt(digitalPinToInterrupt(BTN2A), ISR_BTN2A, INT_CHANGE);
  attachInterrupt(digitalPinToInterrupt(BTN3A), ISR_BTN3A, INT_CHANGE);
  attachInterrupt(digitalPinToInterrupt(BTN4A), ISR_BTN4A, INT_CHANGE);
  attachInterrupt(digitalPinToInterrupt(BTN1B), ISR_BTN1B, INT_CHANGE);
  attachInterrupt(digitalPinToInterrupt(BTN2B), ISR_BTN2B, INT_CHANGE);
  attachInterrupt(digitalPinToInterrupt(BTN3B), ISR_BTN3B, INT_CHANGE);
  attachInterrupt(digitalPinToInterrupt(BTN4B), ISR_BTN4B, INT_CHANGE);
}

void loop() {
  if(state != MASK_EMPTY)
  {
    // Allume la lumiere du premiere bouton activer
    switch(state){
      case MASK_BTN1A:
        digitalWrite(LED1A,HIGH);
        break;
      case MASK_BTN2A:
        digitalWrite(LED2A,HIGH);
        break;
      case MASK_BTN3A:
        digitalWrite(LED3A,HIGH);
        break;
      case MASK_BTN4A:
        digitalWrite(LED4A,HIGH);
        break;

      case MASK_BTN1B:
        digitalWrite(LED1B,HIGH);
        break;
      case MASK_BTN2B:
        digitalWrite(LED2B,HIGH);
        break;
      case MASK_BTN3B:
        digitalWrite(LED3B,HIGH);
        break;
      case MASK_BTN4B:
        digitalWrite(LED4B,HIGH);
        break;

      default:
        // Erreur : probleme avec la detection des boutons
        digitalWrite(BTN1A,HIGH);
        digitalWrite(BTN2A,HIGH);
        digitalWrite(BTN3A,HIGH);
        digitalWrite(BTN4A,HIGH);
        digitalWrite(BTN1B,HIGH);
        digitalWrite(BTN2B,HIGH);
        digitalWrite(BTN3B,HIGH);
        digitalWrite(BTN4B,HIGH);
    }
  }
  if(digitalRead(BTN_TOP) || digitalRead(BTN_RST)){
    state = MASK_EMPTY;
    digitalWrite(LED1A,LOW);
    digitalWrite(LED2A,LOW);
    digitalWrite(LED3A,LOW);
    digitalWrite(LED4A,LOW);
    digitalWrite(LED1B,LOW);
    digitalWrite(LED2B,LOW);
    digitalWrite(LED3B,LOW);
    digitalWrite(LED4B,LOW);
  }
}

void ISR_BTN1A(){
  if(state == MASK_EMPTY){
    state = MASK_BTN1A;
  }
}

void ISR_BTN2A(){
  if(state == MASK_EMPTY){
    state = MASK_BTN2A;
  }
}

void ISR_BTN3A(){
  if(state == MASK_EMPTY){
    state = MASK_BTN3A;
  }
}

void ISR_BTN4A(){
  if(state == MASK_EMPTY){
    state = MASK_BTN4A;
  }
}

void ISR_BTN1B(){
  if(state == MASK_EMPTY){
    state = MASK_BTN1B;
  }
}

void ISR_BTN2B(){
  if(state == MASK_EMPTY){
    state = MASK_BTN2B;
  }
}

void ISR_BTN3B(){
  if(state == MASK_EMPTY){
    state = MASK_BTN3B;
  }
}

void ISR_BTN4B(){
  if(state == MASK_EMPTY){
    state = MASK_BTN4B;
  }
}
