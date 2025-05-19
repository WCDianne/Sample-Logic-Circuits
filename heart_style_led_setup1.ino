int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3};
// Indexes:
// 0  = LED16 (pin 2)
// 1  = LED1  (pin 3)
// 2  = LED2  (pin 4)
// 3  = LED3  (pin 5)
// 4  = LED4  (pin 6)
// 5  = LED5  (pin 7)
// 6  = LED6  (pin 8)
// 7  = LED7  (pin 9)
// 8  = LED8  (pin 10)
// 9  = LED9  (pin 11)
// 10 = LED10 (pin 12)
// 11 = LED11 (pin 13)
// 12 = LED12 (pin A0)
// 13 = LED13 (pin A1)
// 14 = LED14 (pin A2)
// 15 = LED15 (pin A3)

unsigned long lastSwitchTime = 0;
bool isPhaseOne = true;

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud
  for (int i = 0; i < 16; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}


void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastSwitchTime >= 3000) {
    isPhaseOne = !isPhaseOne;
    lastSwitchTime = currentTime;
  }

  if (isPhaseOne) {
    // 🔷 Phase 1: Sequence from LED16 to LED15
    for (int i = 0; i < 16; i++) {
      digitalWrite(ledPins[i], HIGH);
      delay(50);
      digitalWrite(ledPins[i], LOW);
    }
    } else {
    // Phase 2: Heart Pattern

    for (int i = 0; i < 16; i++) {
      digitalWrite(ledPins[i], LOW); // Clear all
    }

    // Step 1: LED16 alone
    digitalWrite(ledPins[0], HIGH);
    delay(300);
    digitalWrite(ledPins[0], LOW);

   

    // Step 3: Pairing (excluding LED8)
    int left[]  = {1, 2, 3, 4, 5, 6, 7,};      // LED1–7
    int right[] = {15, 14, 13, 12, 11, 10, 9}; // LED15–9 (not 8!)
 
    for (int i = 0; i < 7; i++) {
      digitalWrite(ledPins[left[i]], HIGH);
      digitalWrite(ledPins[right[i]], HIGH);
      delay(300);
      digitalWrite(ledPins[left[i]], LOW);
      digitalWrite(ledPins[right[i]], LOW);
    }

    // Final: LED8 alone
    digitalWrite(ledPins[8], HIGH); // LED8 (pin 10)
    delay(300);
    digitalWrite(ledPins[8], LOW);
  }
}