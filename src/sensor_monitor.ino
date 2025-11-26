// Arduino Sensor Monitor
// Author: Mustafa Yildiz

// Pin definitions
const int LDR_PIN   = A0;  // Light sensor
const int TEMP_PIN  = A1;  // Temperature sensor (e.g. LM35)
const int PIR_PIN   = 2;   // Motion sensor (digital)
const int LED_PIN   = 8;   // LED or relay

// Adjust this threshold based on your LDR and environment
const int LDR_DARK_THRESHOLD = 400;

void setup() {
  Serial.begin(9600);

  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  // Start with LED off
  digitalWrite(LED_PIN, LOW);

  Serial.println("Arduino Sensor Monitor starting...");
}

void loop() {
  // Read sensors
  int ldrValue   = analogRead(LDR_PIN);
  int tempValue  = analogRead(TEMP_PIN);
  int motionRaw  = digitalRead(PIR_PIN);

  // Convert temperature sensor reading (approx for LM35)
  float voltage     = (tempValue / 1023.0) * 5.0; // 0–5 V
  float temperature = voltage * 100.0;           // ~10 mV/°C

  bool motionDetected = (motionRaw == HIGH);
  bool isDark         = (ldrValue < LDR_DARK_THRESHOLD);

  // Print values to Serial Monitor
  Serial.print("Light: ");
  Serial.print(ldrValue);
  Serial.print(" | Temp: ");
  Serial.print(temperature);
  Serial.print(" C");
  Serial.print(" | Motion: ");
  Serial.print(motionDetected ? "YES" : "NO");
  Serial.print(" | Dark: ");
  Serial.println(isDark ? "YES" : "NO");

  // Automation logic:
  // If it is dark AND motion is detected → LED ON
  if (isDark && motionDetected) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(500); // small delay for stability
}
