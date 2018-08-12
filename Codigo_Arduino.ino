char nameA[10] = "Arduino"; //Nombre del Modulo
char passA[10] = "1234"; //Nueva Password
char baud = '4'; //4 = 9600 baud

//Ruedas
int pinLx = 4; // Conectado a IN4 de Puente H
int pinLy = 5; // Conectado a IN3 de Puente H
int pinRx = 6; // Conectado a IN2 de Puente H
int pinRy = 7; // Conectado a IN1 de Puente H

void setup() {
  Serial.begin(9600); //Iniciar Serial
  pinMode(13, OUTPUT); //Pin de Salida
}

void loop() {
  if (Serial.available() >= 1) {
    char entry = Serial.read(); // Leer caracter
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
      Serial.println("Avanza");
    }
    //RETROCEDER
    if (entry == 'S') { //Retroceder
      digitalWrite(pinLx, HIGH);
      digitalWrite(pinLy, LOW);
      digitalWrite(pinRx, HIGH);
      digitalWrite(pinRy, LOW);
      Serial.println("Retrocede");
    }
    //RIGHT
    if (entry == 'D') { //Right
      digitalWrite(pinLx, HIGH);
      digitalWrite(pinLy, LOW);
      digitalWrite(pinRx, LOW);
      digitalWrite(pinRy, HIGH);
      Serial.println("Derecha");
    }
    //LEFT
    if (entry == 'A') { //Left
      digitalWrite(pinLx, LOW);
      digitalWrite(pinLy, HIGH);
      digitalWrite(pinRx, HIGH);
      digitalWrite(pinRy, LOW);
      Serial.println("Izquierda");
    }
    //STOP
    if (entry == 's') { //Stop
      digitalWrite(pinLx, LOW);
      digitalWrite(pinLy, LOW);
      digitalWrite(pinRx, LOW);
      digitalWrite(pinRy, LOW);
      Serial.println("Stop");
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
