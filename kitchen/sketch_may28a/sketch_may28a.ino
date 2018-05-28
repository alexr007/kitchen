#define LED_PORT   LED_BUILTIN

bool state;

void switch_state() {
  state = !state;
}

void switch_led() {
  digitalWrite(LED_PORT, state ? HIGH : LOW);
}

void setup() {
  pinMode(LED_PORT, OUTPUT);
}

void loop() {
  switch_led();
  switch_state();
  delay(1000);
}
