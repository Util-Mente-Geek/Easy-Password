/** AxeDoor
 * Codigo para capturar teclado matricial 2x2
 * Microcontrolador: Arduino uno
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
  char CLAVE_MAESTRA[5]; 
  byte INDICE = 0; 
 
  
  void setup() {
    Serial.begin(9600); 
                }
  
  void loop() {
              
         TECLA = teclado.getKey(); 
      if (TECLA) {    
        CLAVE[INDICE] = TECLA; 
        INDICE++;    
        Serial.print(TECLA); 
             }
      }
  
  
