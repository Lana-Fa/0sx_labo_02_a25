
const int LED_PINS[] = {8, 9, 10, 11}; 
const int BUTTON_PIN = 2;  
const int POT_PIN = A1;   



const int STUDENT_ID = 2412384;


unsigned long currentTime = 0;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 4; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }

  
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.println("Setup completed");
}

void loop() {
  currentTime = millis();  

  
  int potValue = analogRead(POT_PIN);  
  int mappedValue = map(potValue, 0, 1023, 0, 20);

  
  bool buttonState = digitalRead(BUTTON_PIN) == LOW;

  
  if (buttonState) {
    afficherBarreProgression(mappedValue);
  }

  
  controlerLEDs(potValue);
}


void afficherBarreProgression(int progress) {
  char symbole = '#'; 

  Serial.print("[");
  for (int i = 0; i < 20; i++) {
    if (i < progress) Serial.print(symbole);
    else Serial.print(".");
  }
  Serial.print("] ");
  Serial.print(map(progress, 0, 20, 0, 100));
  Serial.println("%");
}


void controlerLEDs(int potValue) {
  int niveau = map(potValue, 0, 1023, 0, 4); 

  
  for (int i = 0; i < 4; i++) {
    digitalWrite(LED_PINS[i], i < niveau ? HIGH : LOW);
  }
}