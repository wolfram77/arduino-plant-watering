const int relayPin = 4;


// Get milliseconds time.
inline uint64_t msSeconds(int n) { return n*1000; }
inline uint64_t msMinutes(int n) { return 60*msSeconds(n); }
inline uint64_t msHours(int n)   { return 60*msMinutes(n); }
inline uint64_t msDays(int n)    { return 24*msHours(n); }


// Long delay.
void delayLong(uint64_t ms) {
  uint64_t d = 10000;
  for (; ms>=d; ms-=d)
    delay((int)d);
  if (ms>0) delay((int)ms);
}


// Relay control.
void waterOff() {
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(relayPin, HIGH);
}
void waterOn() {
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(relayPin, LOW);
}
void waterTest() {
  waterOn();
  delay(3000);
  waterOff();
  delay(7000);
}


// Main program.
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(relayPin, OUTPUT);
  for (int i=0; i<5; i++)
    waterTest();
  delayLong(msDays(4));
}


void loop() {
  waterOn();
  delayLong(msMinutes(1));
  waterOff();
  delayLong(msDays(1));
}
