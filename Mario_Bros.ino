// Aprende con Ruben's

#define NOTE_RE3  147
#define NOTE_RES3 156
#define NOTE_MI3  165
#define NOTE_FA3  175
#define NOTE_SOL3  196
#define NOTE_SOLS3 208
#define NOTE_LA3  220
#define NOTE_LAS3 233
#define NOTE_SI3  247

#define NOTE_DO4  262
#define NOTE_DOS4 277
#define NOTE_RE4  294
#define NOTE_RES4 311
#define NOTE_FA4  349
#define NOTE_FAS4 370
#define NOTE_SOLS4 415
#define NOTE_LA4  440
#define NOTE_LAS4 466

#define NOTE_DO5  523

#define NOTE_MI6  1319
#define NOTE_SOL6  1568
#define NOTE_LA6  1760
#define NOTE_LAS6 1865
#define NOTE_SI6  1976

#define NOTE_DO7  2093
#define NOTE_RE7  2349
#define NOTE_MI7  2637
#define NOTE_FA7  2794
#define NOTE_SOL7  3136
#define NOTE_LA7  3520

#define melodyPin 8


int melody[] = {
  NOTE_MI7, NOTE_MI7, 0, NOTE_MI7,
  0, NOTE_DO7, NOTE_MI7, 0,
  NOTE_SOL7, 0, 0,  0,
  NOTE_SOL6, 0, 0, 0,

  NOTE_DO7, 0, 0, NOTE_SOL6,
  0, 0, NOTE_MI6, 0,
  0, NOTE_LA6, 0, NOTE_SI6,
  0, NOTE_LAS6, NOTE_LA6, 0,

  NOTE_SOL6, NOTE_MI7, NOTE_SOL7,
  NOTE_LA7, 0, NOTE_FA7, NOTE_SOL7,
  0, NOTE_MI7, 0, NOTE_DO7,
  NOTE_RE7, NOTE_SI6, 0, 0,

  NOTE_DO7, 0, 0, NOTE_SOL6,
  0, 0, NOTE_MI6, 0,
  0, NOTE_LA6, 0, NOTE_SI6,
  0, NOTE_LAS6, NOTE_LA6, 0,

  NOTE_SOL6, NOTE_MI7, NOTE_SOL7,
  NOTE_LA7, 0, NOTE_FA7, NOTE_SOL7,
  0, NOTE_MI7, 0, NOTE_DO7,
  NOTE_RE7, NOTE_SI6, 0, 0
};


int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};


int underworld_melody[] = {
  NOTE_DO4, NOTE_DO5, NOTE_LA3, NOTE_LA4,
  NOTE_LAS3, NOTE_LAS4, 0,
  0,
  NOTE_DO4, NOTE_DO5, NOTE_LA3, NOTE_LA4,
  NOTE_LAS3, NOTE_LAS4, 0,
  0,
  NOTE_FA3, NOTE_FA4, NOTE_RE3, NOTE_RE4,
  NOTE_RES3, NOTE_RES4, 0,
  0,
  NOTE_FA3, NOTE_FA4, NOTE_RE3, NOTE_RE4,
  NOTE_RES3, NOTE_RES4, 0,
  0, NOTE_RES4, NOTE_DOS4, NOTE_RE4,
  NOTE_DOS4, NOTE_RES4,
  NOTE_RES4, NOTE_SOLS3,
  NOTE_SOL3, NOTE_DOS4,
  NOTE_DO4, NOTE_FAS4, NOTE_FA4, NOTE_MI3, NOTE_LAS4, NOTE_LA4,
  NOTE_SOLS4, NOTE_RES4, NOTE_SI3,
  NOTE_LAS3, NOTE_LA3, NOTE_SOLS3,
  0, 0, 0
};


int underworld_tempo[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};


void setup(void){
  pinMode(8, OUTPUT);
}


void loop(){
  sing(1);
  sing(1);
  sing(2);
}
int song = 0;


void sing(int s) {
  song = s;
  
  if (song == 2) {
    int size = sizeof(underworld_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      int noteDuration = 1000 / underworld_tempo[thisNote];

      buzz(melodyPin, underworld_melody[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      buzz(melodyPin, 0, noteDuration);
    }
    
  } else {
    
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      int noteDuration = 1000 / tempo[thisNote];

      buzz(melodyPin, melody[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      buzz(melodyPin, 0, noteDuration);
    }
  }
}


void buzz(int Buzzer, long frequency, long length) {
  long delayValue = 1000000 / frequency / 2; 
  long numCycles = frequency * length / 1000; 
  for (long i = 0; i < numCycles; i++) {
    digitalWrite(Buzzer, HIGH); 
    delayMicroseconds(delayValue); 
    digitalWrite(Buzzer, LOW); 
    delayMicroseconds(delayValue); 
  }
}
