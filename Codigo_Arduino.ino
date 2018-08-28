#include <SoftwareSerial.h>

char nameA[10] = "Arduino"; //Nombre del Modulo
char passA[10] = "1234"; //Nueva Password
//char baud = '4'; //4 = 9600 baud

// bt
SoftwareSerial mySerial(3, 2); // RX, TX

//Ruedas
int pinLx = 8;  // Conectado a IN4 de Puente H
int pinLy = 9;  // Conectado a IN3 de Puente H
int pinRx = 10; // Conectado a IN2 de Puente H
int pinRy = 11; // Conectado a IN1 de Puente H

//Sierra
int pinSx = 6; // Conectado a IN1 de Puente H
int pinSy = 7; // Conectado a IN2 de Puente H

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600); //Iniciar Serial
  pinMode(13, OUTPUT); //Pin de Salida
  pinMode(pinLx, OUTPUT); //Pin de Salida
  pinMode(pinLy, OUTPUT); //Pin de Salida
  pinMode(pinRx, OUTPUT); //Pin de Salida
  pinMode(pinRy, OUTPUT); //Pin de Salida
  digitalWrite(12, HIGH); //LED
}

void loop() {
  if (mySerial.available() >= 1) {
    char entry = mySerial.read(); // Leer caracter
    Serial.println(entry);

    //W -> Avanzar
    //A -> Izquierda
    //S -> Retroceder
    //D -> Derecha
    //s -> Detenerse

    //AVANZAR
    if (entry == 'W') {
      digitalWrite(pinLx, LOW);
      digitalWrite(pinLy, HIGH);
      digitalWrite(pinRx, LOW);
      digitalWrite(pinRy, HIGH);
      Serial.println("Moving Forward");
    }
    //RETROCEDER
    if (entry == 'S') { //Retroceder
      digitalWrite(pinLx, HIGH);
      digitalWrite(pinLy, LOW);
      digitalWrite(pinRx, HIGH);
      digitalWrite(pinRy, LOW);
      Serial.println("Moving Back");
    }
    //RIGHT
    if (entry == 'D') { //Right
      digitalWrite(pinLx, HIGH);
      digitalWrite(pinLy, LOW);
      digitalWrite(pinRx, LOW);
      digitalWrite(pinRy, HIGH);
      Serial.println("Turning Right");
    }
    //LEFT
    if (entry == 'A') { //Left
      digitalWrite(pinLx, LOW);
      digitalWrite(pinLy, HIGH);
      digitalWrite(pinRx, HIGH);
      digitalWrite(pinRy, LOW);
      Serial.println("Turning Left");
    }
    //STOP
    if (entry == 'P') { //Stop
      digitalWrite(pinLx, LOW);
      digitalWrite(pinLy, LOW);
      digitalWrite(pinRx, LOW);
      digitalWrite(pinRy, LOW);
      Serial.println("Stop");
    }
    
    if (entry == 'C') {
       digitalWrite(pinSx, LOW);
       digitalWrite(pinSy, HIGH);
       Serial.println("(C) Cortar - ¡Al ataque!");
    }
     
    if (entry == 'N') {
       digitalWrite(pinSx, LOW);
       digitalWrite(pinSy, LOW);
       Serial.println("(N) No Cortar - Modo Pasivo");
    }
     
    //LED TESTING
  
    if (entry == 'H') { //Si es H prender LED
      digitalWrite(13, HIGH);
      Serial.println("LED ON");
    } else if (entry == 'L') { //Si es 'L' apagar LED
      digitalWrite(13, LOW);
      Serial.println("LED OFF");
    }
    
    delay(100);
  }
}
