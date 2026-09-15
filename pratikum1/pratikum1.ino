const byte ldrPin = A0; 

void setup() {  
  Serial.begin(115200);  
}

void loop() {  
  int ldrValue = analogRead(ldrPin);

  int cahayaPersen = map(ldrValue, 0, 1023, 0, 100);   
    
  Serial.print("Intensitas Cahaya (ADC): ");
  Serial.print(cahayaPersen);  
  Serial.println("%");  
    
  delay(1000);   
}