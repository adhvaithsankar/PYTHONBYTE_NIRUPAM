int count = 0;
char c;
String id;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  Serial.println("SCANNING NEARBY RFID TAGS");
 
}

void loop() {
  while(Serial.available()>0)
  {
    c = Serial.read();
   count++;
   id += c;
   if(count == 12)  
    {
      Serial.print(id);
      //break;
     
      if(id=="RFID12345678")
      {
        Serial.println("Valid TAG, TURN LIGHTS GREEN");
        digitalWrite(13, HIGH);
      }
      else
      {
      digitalWrite(13, LOW);
      Serial.println("Invalid TAG, CONTINUE AS USUAL");
      }
    }
  }
  count = 0;
  id="";
  delay(500);

}
