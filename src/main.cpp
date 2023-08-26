#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

const int potPin = A0; // Pin analógico para el potenciómetro
const int numBits = 3; // Número de bits para la representación binaria
const int ledPin = 8;
LiquidCrystal_I2C lcd(0x27, 16, 2); // Dirección I2C y dimensiones del LCD

void setup()
{
  pinMode(ledPin, OUTPUT); // Configura el pin del LED como salida
  lcd.init();              // Inicializa el LCD
  lcd.backlight();         // Enciende la retroiluminación del LCD
}

void loop()
{
  int analogValue = analogRead(potPin);                                // Lee el valor analógico del potenciómetro
  int binaryValue = map(analogValue, 0, 1023, 0, pow(2, numBits) - 1); // Mapea el valor analógico a un valor binario de 3 bits

  int bit0 = binaryValue & 0b00000001;        // Obtén el primer bit
  int bit1 = (binaryValue >> 1) & 0b00000001; // Obtén el segundo bit
  int bit2 = (binaryValue >> 2) & 0b00000001; // Obtén el tercer bit

  digitalWrite(ledPin, bit1); //Coloca el valor del bit B o bit 2 en la salida

  lcd.clear(); // Limpia la pantalla LCD
  lcd.setCursor(0, 0);
  lcd.print("Lectura: ");
  lcd.print(analogValue);
  lcd.setCursor(0, 1);
  lcd.print("Binario: ");
  lcd.print(bit2);
  lcd.print(bit1);
  lcd.print(bit0);

  delay(500);
}