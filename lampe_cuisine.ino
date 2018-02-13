

//*************************************************************
//programme : lampe_cuisine
//*************************************************************
//écrit le : 14/01/2018
//auteur : Alain Renon
// modifié le : 
//************************************************************
//description :
// interrupteur tactile capacitif sur pin D2
// utilisant un TTP223 sur pin 2
//et 3 relais 5V 10A sur pin 4,5,6
//pos 0 = éteint
// pos 1 = 2 ampoules allumées
// pos 2 = 3 ampoules allumées
// pos 3 = 5 ampoules allumées
byte pinTouche=2;
byte pinPos1=4;
byte pinPos2=5;
byte pinPos3=6;
byte pos=0;
byte posPrecedent=0;
boolean nouveau=false;
boolean touche=false;

void setup() 
{
   pinMode (pinPos1,OUTPUT);
   pinMode (pinPos2,OUTPUT);
   pinMode (pinPos3,OUTPUT);
// quand on met le courant à l'interrupteur mural, on éclaire en position 1
   digitalWrite (pinPos1,HIGH);
   digitalWrite (pinPos2,LOW);
   digitalWrite (pinPos3,LOW);
   pos=1;
   posPrecedent=0;
   nouveau=true;
   touche=false;
}//end setup

void loop() 
{
  if (digitalRead(pinTouche))// on détecte un contact
  {
     if (nouveau)
     {
        pos++;
        if (pos>3) pos=0;// end if
        nouveau=false;
        gerePos(pos);
     }// end if
  }
  else
  {
     if (!nouveau) nouveau=true;
  }//end if 
  delay(20);
}//end loop

//******************** fonction gerePos   ***************************
void gerePos(byte pos)
{
   if (pos==0)
   {
      digitalWrite(pinPos1,LOW);
      digitalWrite(pinPos2,LOW);
      digitalWrite(pinPos3,LOW);
   }
   else if (pos==1)
   {
      digitalWrite(pinPos1,HIGH);
      digitalWrite(pinPos2,LOW);
      digitalWrite(pinPos3,LOW);
   }
   else if (pos==2)
   {
      digitalWrite(pinPos1,HIGH);
      digitalWrite(pinPos2,HIGH);
      digitalWrite(pinPos3,LOW);
   }
   else if (pos==3)
   {
      digitalWrite(pinPos1,HIGH);
      digitalWrite(pinPos2,HIGH);
      digitalWrite(pinPos3,HIGH);
   }//end if
}// end fonction

