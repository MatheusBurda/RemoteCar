#define motorFRENTE 3
#define motorRE 2

#define direita 8
#define esquerda 9


void setup()
  {
    pinMode (motorFRENTE,OUTPUT);
    pinMode (motorRE,OUTPUT);
    pinMode (direita,OUTPUT);
    pinMode (esquerda,OUTPUT);
    digitalWrite(motorFRENTE, 0);
    digitalWrite(motorRE, 0);
    digitalWrite(direita, 0);
    digitalWrite(esquerda, 0);
    Serial.begin(9600);
  }

void loop()
  {
    int btn;
    btn = Serial.read();

    if(btn=='P')
      {
        freio();
        reto();
      }
    
    if(btn=='C')
      {
         if (digitalRead(motorRE)==1)
           {
              freio();
           }
         else
            {
              digitalWrite(motorFRENTE, 1);
            }
                
        }
    
    
    if(btn=='B')
      {
         if (digitalRead(motorFRENTE)==1)
           {
              freio();
           }
         else
            {
              digitalWrite(motorRE, 1);
            }
                
        }     

    if(btn=='E')
      {
         if (digitalRead(direita)==1)
           {
              reto();
           }
         else
            {
              digitalWrite(esquerda, 1);
            }
                
        }     
    if(btn=='D')
      {
         if (digitalRead(esquerda)==1)
           {
              reto();
           }
         else
            {
              digitalWrite(direita, 1);
            }
                
        }     
}

void freio()
  {
     digitalWrite(motorFRENTE, 0);
     delay(500);
     digitalWrite(motorRE, 0);    
  }

void reto()
{
   digitalWrite(direita, 0);
   delay(500);
   digitalWrite(esquerda, 0);
}















