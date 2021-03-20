int pins[6] = {10, 11, 12, 2, 3, 4};
int pinsAmount = sizeof(pins) / sizeof(pins[0]);

void switchOffAllPins() {
  for (int i = 0; i < pinsAmount; i++) {
    digitalWrite(pins[i], LOW);
  }
}
/*
   Run diods sequentially
*/
void runSequentially() {
  delay(500);

  for (int i = 0; i < pinsAmount; i++) {
    digitalWrite(pins[i], HIGH);
    delay(500);
  }
  switchOffAllPins();
}

/*
 * Run by color pairs.
 */
void runPairsByColor() {
  delay(500);
  int i = 0;
  while (i < pinsAmount / 2) {
    digitalWrite(pins[i], HIGH);
    int pairFromCenter = i + floor((pinsAmount) / 2);
    digitalWrite(pins[pairFromCenter], HIGH);
    delay(500);
    i++;
  }
  switchOffAllPins();
}

void getOddPins(int* odd, int length) {
  int index = 0;
  for (int i = 0; i < pinsAmount; i++) {
    if (((i + 10) % 2) == 0) {
      odd[index] = pins[i];
      index++;
    }
  }
}

void getEvenPins(int* even, int length) {
  int index = 0;
  for (int i = 0; i < pinsAmount; i++) {
    if (((i + 10) % 2) == 1) {
      even[index] = pins[i];
      index++;
    }
  }
}


/**
 * Thid animation pattern.
 */
void runOddEvenFigure() {
  int odd[3];
  int even[3];
  getOddPins(odd, 3);
  getEvenPins(even, 3);

  for (int i = 0; i < pinsAmount; i++) {
    for (int j = 0; j < 3; j++) {
      digitalWrite(odd[j], HIGH);
    }
    delay(500);
    switchOffAllPins();

    for (int k = 0; k < 3; k++) {
      digitalWrite(even[k], HIGH);
    }
    delay(500);
    switchOffAllPins();
  }
}

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < pinsAmount; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  runPairsByColor();
  delay(1000);
  runOddEvenFigure();
  delay(1000);
}
