#include <Arduino.h>
double getTempRTD(int pin)
{

  const double r1 = 1000;
  const double r2 = 1000;
  const double r3 = 1000;
  const double rg = 1000;

  const double rc = 200;
  const double ra = 100;
  const double rb = 100;

  double k = (rc / (rc + ra)) - (((double)analogRead(pin)) * r2 * rg / (1023 * r3 * (rg + 2 * r1)));

  double r = ((double)rb) / ((1.0 / k) - 1.0);

  return (((r / 100.0) - 1.0) / 0.0038459);
}

void setup()
{
  Serial.begin(9600); // INICIALIZA A SERIAL
  delay(1000);        // INTERVALO DE 1 SEGUNDO
}
void loop()
{
  double temperature = getTempRTD(A5); // VARIÁVEL DO TIPO INTEIRO QUE RECEBE O VALOR DE TEMPERATURA CALCULADO PELA BIBLIOTECA
  Serial.print("Temperatura: ");       // IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.print(temperature, 2);        // IMPRIME NO MONITOR SERIAL A TEMPERATURA MEDIDA
  Serial.println("*C");                // IMPRIME O TEXTO NO MONITOR SERIAL
  delay(1000);                         // INTERVALO DE 1 SEGUNDO
}
