/*-------------------------------------------------------------------------------------------
------------------ Colocando as Bibliotecas que seram usadas no código  ---------------------
-------------------------------------------------------------------------------------------*/

#include <Servo.h>

/*-------------------------------------------------------------------------------------------
------------------------------ Definindo algumas Variaveis ----------------------------------
-------------------------------------------------------------------------------------------*/

  Servo ServoCB;  // Definicão do Servo Cima/Baixo
  Servo ServoED;  // Definicão do Servo Esquerda/Direita
  
  int PosCB = 90; // Posição inicial do "ServoCB"
  int PosED = 90; // Posição inicial do "ServoED"
  
  int SenC = A0;  // LDR C no pino A0
  int SenB = A1;  // LDR B no pino A1
  int SenE = A2;  // LDR E no pino A2
  int SenD = A3;  // LDR D no pino A3
  
  int Tolerancia = 10; // Diferença aceitavel entre dois LDR's (mudar ao testar na prátoica
 
/*-------------------------------------------------------------------------------------------
--------------------------- Definindo as entradas e saidas  ---------------------------------
-------------------------------------------------------------------------------------------*/

void setup() {

  ServoCB.attach(9);     // "ServoCB" ligado no pino 9 
  ServoED.attach(10);    // "ServoED" ligado no pino 10
  
  pinMode(SenC,INPUT);   // Define "SenC" como entrada
  pinMode(SenB,INPUT);   // Define "SenB" como entrada
  pinMode(SenE,INPUT);   // Define "SenE" como entrada
  pinMode(SenD,INPUT);   // Define "SenD" como entrada
  
  ServoCB.write(PosCB);  // Coloca a posição inicial no "ServoCB"
  ServoED.write(PosED);  // Coloca a posição inicial no "ServoED"
  
  delay(2000); 

}


/*-------------------------------------------------------------------------------------------
--------------------------- Inicio da logica de programação  --------------------------------
-------------------------------------------------------------------------------------------*/


void loop()  {

  SeguidorSolar(); // Função criada para o funcionamento do Seguidor Solar
         
}


/*-------------------------------------------------------------------------------------------
--------------------------------- Função Seguidor Solar  ------------------------------------
-------------------------------------------------------------------------------------------*/


void SeguidorSolar(void) { 

  int AvgC = 0, AvgB = 0;
  int ValorC = analogRead(SenC); // Leitura do sensor SenC
  int ValorB = analogRead(SenB); // Leitura do sensor SenB

  /* TESTE PARA SABER SE O SINAL FICA MELHOR
  for (int i = 0; i < 3; i++) {
      AvgC += ValorC;
      AvgB += ValorB; 
    }
  
  AvgC = AvgC/3;
  AvgB = AvgB/3;
    */
  
  if(abs(AvgC - AvgB) <= Tolerancia)
   {
    
   }
    else
   {
    
    if(ValorC>ValorB)
     {
      PosCB = --PosCB;
     }
     
    if(AvgC < AvgB)
     {
      PosCB = ++PosCB;     
     }
     
    if(PosCB>180)
     {
      PosCB = 180; 
     }
     
    if(PosCB<0)
     {
      PosCB = 0; 
     }

    ServoCB.write(PosCB); // Define a posição do ServoCB
    delay(50); 
  
   }

  int AvgE = 0, AvgD = 0;
  int ValorE = analogRead(SenE); // Leitura do sensor SenE
  int ValorD = analogRead(SenD); // Leitura do sensor SenD

  /* TESTE PARA SABER SE O SINAL FICA MELHOR
   for (int i = 0; i < 3; i++) {
    AvgE += ValorE;
    AvgD += ValorD; 
  }

  AvgE = AvgE/3;
  AvgD = AvgD/3;
  */

  if(abs(AvgE - AvgD) <= Tolerancia)
   {
    
   }
    else
   {
    
    if(AvgE > AvgD)
     {
      PosED = --PosED;
     }
     
    if(AvgE < AvgD)
     {
      PosED = ++PosED;     
     }
     
    if(PosED>180)
     {
      PosED = 180; 
     }
     
    if(PosED<0)
     {
      PosED = 0; 
     }

    ServoED.write(PosED); // Define a posição do ServoED
    delay(50); 
  
   }
  //Verificar a necessidade de colocar uma tolerância para cada par de sensores (E-D e C-B)
}
