/** AxeDoor
 * Codigo para teclear una contraseña predefinida en programa
 * Microcontrolador: Arduino
 * Escrito por: Útil Mente Geek
 * PaginaWeb: www.utilmentegeek.com
 * YouTube: https://www.youtube.com/channel/UCBqfcl_tue6Zsk4Hc3BErWg
 * Instagram: https://www.instagram.com/utilmentegeek/
 * 
 * Recuerda que tambien pudes contribuir a la mejora de este codigo en GitHub
 * Y apoyar el desarrollo de estos proyectos así como resolver dudas sobre el codigo
 * en nuestras redes socilaes @Util Mente Geek.
 */
  #include <Keypad.h>        

  const byte FILAS = 2;      
  const byte COLUMNAS = 2;   
  char keys[FILAS][COLUMNAS] = { 
    {'1','2'},
    {'3','4'}
                               };
  
  byte pinesFilas[FILAS] = {13,12}; 
  byte pinesColumnas[COLUMNAS] = {11,10};
  
  Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS); 
  
  char TECLA; 
  char CLAVE[5]; 
  char CLAVE_MAESTRA[5] = "4312"; 
  byte INDICE = 0; 
  int ledC = 9;    
  int ledI = 8;   
  
  
  void setup() {
    Serial.begin(9600); 
    pinMode(ledC, OUTPUT); 
    pinMode(ledI, OUTPUT);  
                }
  
  void loop() {
                     
          TECLA = teclado.getKey(); 
      if (TECLA) {    
        CLAVE[INDICE] = TECLA; 
        INDICE++;    
        Serial.print(TECLA); 
             }
  
      if (INDICE == 4) {    
      if (strcmp(CLAVE, CLAVE_MAESTRA) == 0) { 
        Serial.println(" Correcta"); 
        digitalWrite(ledC, HIGH);   
        digitalWrite(ledI, LOW);    
                              } 
      else {      
      Serial.println(" Incorrecta"); 
      digitalWrite(ledC, LOW);    
      digitalWrite(ledI, HIGH);   
      
            }
       INDICE = 0;  
           }
         }
     
