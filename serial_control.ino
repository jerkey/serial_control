#define PRECHARGE       5
#define CONTACTOR       6
#define PRECHARGE_TIME  3000
void setup() {
  pinMode(PRECHARGE, OUTPUT); // precharge
  pinMode(CONTACTOR, OUTPUT); // contactors
  Serial.begin(9600);
  Serial.println("control pins 5 and 6");
}

void loop() {
  char a = 0;
  if (Serial.available()) {
    a = Serial.read();
    Serial.println(a);

    if(a == '0') {
      Serial.println("PRECHARGE and CONTACTOR OFF");
      digitalWrite(PRECHARGE, LOW);
      digitalWrite(CONTACTOR, LOW);
    } else if(a == '1') {
      digitalWrite(PRECHARGE, HIGH);
      Serial.print("PRECHARGE ON ... "+String(PRECHARGE_TIME));
      delay(PRECHARGE_TIME);
      digitalWrite(CONTACTOR, HIGH);
      Serial.println("CONTACTOR ON");
    }
  }
}
