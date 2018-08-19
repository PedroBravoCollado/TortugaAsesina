char nameA[10] = "Sherman"; //Nombre del Modulo
char passA[10] = "1234"; //Nueva Password
char baud = '4'; //4 = 9600 baud

//Ruedas
int pinLx = 8;  // Conectado a IN4 de Puente H
int pinLy = 9;  // Conectado a IN3 de Puente H
int pinRx = 10; // Conectado a IN2 de Puente H
int pinRy = 11; // Conectado a IN1 de Puente H

//Sierra
int pinSx = 6; // Conectado a IN1 de Puente H
int pinSy = 7; // Conectado a IN2 de Puente H

//Led
int pinLed = 12; 

void setup() {
  Serial.begin(9600); //Iniciar Serial
  pinMode(13, OUTPUT); //Pin de Salida

  digitalWrite(pinLed, HIGH); //Indica que esta encendido :)
}

void loop() {
  if (Serial.available() >= 1) {
    char entry = Serial.read(); // Leer caracter
    Serial.println(entry);

    //W -> Avanzar
    //A -> Izquierda
    //S -> Retroceder
    //D -> Derecha
    //P -> Detenerse
    
    //C -> Cortar
    //N -> No cortar(?)
    
    switch(entry){
      
      case 'W':
        digitalWrite(pinLx, LOW);
        digitalWrite(pinLy, HIGH);
        digitalWrite(pinRx, LOW);
        digitalWrite(pinRy, HIGH);
        Serial.println("(W) Avanza");
      break;

      case 'S':
        digitalWrite(pinLx, HIGH);
        digitalWrite(pinLy, LOW);
        digitalWrite(pinRx, HIGH);
        digitalWrite(pinRy, LOW);
        Serial.println("(S) Retrocede");
      break;

      case 'A':
        digitalWrite(pinLx, LOW);
        digitalWrite(pinLy, HIGH);
        digitalWrite(pinRx, HIGH);
        digitalWrite(pinRy, LOW);
        Serial.println("(A) Izquierda");
      break;

      case 'D':
        digitalWrite(pinLx, HIGH);
        digitalWrite(pinLy, LOW);
        digitalWrite(pinRx, LOW);
        digitalWrite(pinRy, HIGH);
        Serial.println("(D) Derecha");
      break;

      case 'P':
        digitalWrite(pinLx, LOW);
        digitalWrite(pinLy, LOW);
        digitalWrite(pinRx, LOW);
        digitalWrite(pinRy, LOW);
        Serial.println("(P) Para");
      break;

      case 'C':
        digitalWrite(pinSx, LOW);
        digitalWrite(pinSy, HIGH);
        Serial.println("(C) Cortar - ¡Al ataque!");
      break;

      case 'N':
        digitalWrite(pinSx, LOW);
        digitalWrite(pinSy, LOW);
        Serial.println("(N) No Cortar - Modo Pasivo");
      break;
      
    }
    
    //LED TESTING
    
    if (entry == 'H') { //Si es H prender LED
      digitalWrite(13, HIGH);
      Serial.println("LED ON");
    } else if (entry == 'L') { //Si es 'L' apagar LED
      digitalWrite(13, LOW);
      Serial.println("LED OFF");
    }
    
    delay(500);
  }
}
