/*
 * Project LAB12Slave
 * Description:
 * Author:
 * Date:
 */
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
bool CS = false;
char rx[1];
char tx[1];
void takeAction(uint8_t state)
{
  if (state)
  {
    CS = true; // watch for this variable in loop and set it back to false once you detect it.
  }
}
// setup() runs once, when the device is first turned on.
void setup()
{
  pinMode(D7, OUTPUT);
  pinMode(D5, INPUT);
  SPI1.setBitOrder(MSBFIRST);
  SPI1.setDataMode(SPI_MODE0);
  SPI1.onSelect(takeAction);
  SPI1.begin(SPI_MODE_SLAVE, D6);
}
//Slave// loop() runs over and over again, as quickly as it can execute.
void loop()
{
  if (CS == true)
  {
    CS = false;
    SPI1.transfer(tx, rx, 1, NULL);
    if (rx[0] == '0')
    {
      digitalWrite(D7, LOW);
    }
    else if (rx[0] == '1')
    {
      digitalWrite(D7, HIGH);
    }
    else if (rx[0] == '?')
    {
      tx[0] = digitalRead(D7);
      SPI1.transfer(tx, rx, 1, NULL);
    }
  }
}