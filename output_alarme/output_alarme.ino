
#define pin_alarme 13 
char data ; 

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_alarme , OUTPUT) ; 
  digitalWrite(pin_alarme ,LOW); // alarme initialement eteinte 
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    data=Serial.read(); 

    if (data == '1' ) // si le caractere envoyer = 1 
    {
      digitalWrite(pin_alarme,HIGH); // activer l alarme 
      Serial.write('1'); // envoyer l etat de l alarme   
    }
    else if (data == '0' ) // si on envoie 0 
    {
      digitalWrite(pin_alarme,LOW); // desactiver l alarme 
      Serial.write('0'); // envoyer l etat de l alarme   
    }
      
  }

}
