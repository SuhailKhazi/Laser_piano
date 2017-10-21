//input pins (analog) of the LDR
int note_C = A0;
int note_D = A1;
int note_E = A2;
int note_F = A3;

//output pins
int sound = 10;

//the value of light intensity on LDR is recorded on these variables
int buttonstate_C = 0;
int buttonstate_D = 0;
int buttonstate_E = 0;
int buttonstate_F = 0;

//the frequency of voice notes to be used on note C,D,E and F respectively
int tones[] = {150, 1000, 1519, 2000};
int toner = 0;

void setup()
{
  //setting the arduino pins used for LDR as input
  pinMode(note_C, INPUT);
  pinMode(note_D, INPUT);
  pinMode(note_E, INPUT);
  pinMode(note_F, INPUT);

  //setting the arduino pin for buzzer as output
  pinMode(sound, OUTPUT);
  Serial.begin(9600);
}

void loop()
{

/*int  sensorValue = analogRead(note_D); // read the value from the sensor
Serial.println(sensorValue); //prints the values coming from the sensor on the screen
delay(100);*/

  //reading the amount of light intensity on each LDR
  buttonstate_C = analogRead(note_C);
  buttonstate_D = analogRead(note_D);
  buttonstate_E = analogRead(note_E);
  buttonstate_F = analogRead(note_F);

  //conditions for if finger passes through any lazer
  if(buttonstate_C >= 750 && buttonstate_C <= 850){
    toner = tones[0];
    tone(sound,toner,200);//pin num, freq, delay

  }

  if(buttonstate_D >= 780 && buttonstate_D <= 800){
    toner = tones[1];
    tone(sound,toner,200);
 
  }
 
  if(buttonstate_E >= 750 && buttonstate_E <= 850){
    toner = tones[2];
    tone(sound,toner,200);
    
  }

  if(buttonstate_F >= 750 && buttonstate_F <= 840){
    toner = tones[3];
    tone(sound,toner,200);
   
  }


}
