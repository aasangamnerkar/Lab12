/*
 * Project LAB12
 * Description:
 * Author:
 * Date:
 */
char rx[1];
char tx[1];
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
// setup() runs once, when the device is first turned on.
void setup()
{
  pinMode(D5, OUTPUT);
  Serial.begin(9600);
  SPI.setClockSpeed(1, MHZ);
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  SPI.begin(SPI_MODE_MASTER, D5);
}
// loop() runs over and over again, as quickly as it can execute.
void loop()
{
  char value = Serial.read();
  tx[0] = value;
  if (value == '0') {
    digitalWrite(D5, LOW);
    SPI.transfer(tx, rx, 1, NULL);
    digitalWrite(D5, HIGH);
  }
  if (value == '1')
  {
    digitalWrite(D5, LOW);
    SPI.transfer(tx, rx, 1, NULL);
    digitalWrite(D5, HIGH);
  }
  else if (value == '?')
  {
    digitalWrite(D5, LOW);
    SPI.transfer(tx, rx, 1, NULL);
    digitalWrite(D5, HIGH);
    Serial.println("Current state of button: " + String(rx[0]));
  }
}