char nameA[10] = "Arduino"; //Nombre del Modulo
char passA[10] = "1234"; //Nueva Password
char baud = '4'; //4 = 9600 baud

void setup() {
  Serial.begin(9600); //Iniciar Serial
  pinMode(13,OUTPUT); //Pin de Salida
}

void loop() {
  if(Serial.available()>=1){
    char entry = Serial.read(); // Leer caracter
    
    if(entry =='H'){ //Si es H prender LED
      digitalWrite(13,HIGH);
      Serial.println("LED ON");
    }else if(entry =='L'){ //Si es 'L' apagar LED
      digitalWrite(13,LOW);
      Serial.println("LED OFF");
    }
    
  }
}
