#include <LiquidCrystal.h>

char array1[]=" Voltimetro:       ";  
char array2[]=" Tensao: 0.00V      ";  

//Muda o numero mostrado no lcd de acordo com a mudança do potenciometro

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
int resistorPin = 0; 
int valor=0;
int tempo = 50;              

void setup()
{
  lcd.begin(16, 2);  
  lcd.clear();        
  lcd.setCursor(0,0);  
  for (int posicao1 = 0; posicao1 < 16; posicao1++)
  {
      lcd.print(array1[posicao1]);
      delay(tempo);     
  }
}

void loop() 
{
   valor = analogRead(resistorPin)*(5.0 / 1023.0)*100;
   array2[10]  = valor/100%10+0x30;
   array2[12] = valor/10%10+0x30;  
   array2[13] = valor%10+0x30;     
   lcd.setCursor(0,1);       
   for (int posicao3 = 0; posicao3 < 26; posicao3++)
   {
     lcd.print(array2[posicao3]); 
     delay(tempo);                 
   }
}
