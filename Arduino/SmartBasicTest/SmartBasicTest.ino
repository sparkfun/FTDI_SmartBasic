void setup()
{
  Serial.begin(115200);
  pinMode(A0, OUTPUT);
  digitalWrite(A0, HIGH);
}

void loop()
{
  static int i = 0;
  digitalWrite(A0, HIGH);
  Serial.print("Hello CoolTerm! ");
  Serial.println(i++);
  Serial.flush();
  digitalWrite(A0, LOW);
  Serial.print("Hello Arduino! ");
  Serial.println(i++);
  Serial.flush();
  delay(1500);
}
