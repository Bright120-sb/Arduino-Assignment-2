// Task 5: Combined Project — Beeping Countdown
// Paste your digits[][] and segmentPins[] from Task 4 at the top.
 
int segmentPins[] = {2, 3, 4, 5, 6, 7, 9};   // Order from Task 4: a, b, c, d, e, f, g
int numSegments = 7;

// The pattern for each digit from Task 4. 1 = segment ON, 0 = segment OFF.
byte digits[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},   // 0
    {0, 1, 1, 0, 0, 0, 0},   // 1
    {1, 1, 0, 1, 1, 0, 1},   // 2
    {1, 1, 1, 1, 0, 0, 1},   // 3
    {0, 1, 1, 0, 0, 1, 1},   // 4
    {1, 0, 1, 1, 0, 1, 1},   // 5
    {1, 0, 1, 1, 1, 1, 1},   // 6
    {1, 1, 1, 0, 0, 0, 0},   // 7
    {1, 1, 1, 1, 1, 1, 1},   // 8
    {1, 1, 1, 1, 0, 1, 1}    // 9
};
 
int buzzerPin = 8;
 
// showDigit function — copied from Task 4
void showDigit(int n) {
    if (n < 0 || n > 9) return; // Safety check
    for (int i = 0; i < numSegments; i++) {
        digitalWrite(segmentPins[i], digits[n][i]);
    }
}
 
void setup() {
    Serial.begin(9600);
 
    pinMode(buzzerPin, OUTPUT);          // FILLED IN: set up the buzzer
 
    for (int i = 0; i < numSegments; i++) {
        pinMode(segmentPins[i], OUTPUT); // FILLED IN: set up each segment pin
    }
 
    Serial.println("=== Beeping Countdown Starting ==="); // FILLED IN
 
    int count = 9;                       // FILLED IN: Start countdown variable at 9
    while (count >= 1) {                 // FILLED IN: Loop while count is 1 or greater
        Serial.print("Counting: ");
        Serial.println(count);
 
        showDigit(count);                // FILLED IN: Send current value to display
 
        tone(buzzerPin, 1000, 200);      // FILLED IN: Short beep (1000 Hz tone for 200 milliseconds)
        delay(1000);                     // FILLED IN: Hold state for 1 second before next cycle
        count = count - 1;
    }
    
    showDigit(0);                        // FILLED IN: Set display to 0 upon loop completion
    tone(buzzerPin, 1500, 1000);         // FILLED IN: Longer completion tone (1500 Hz for 1 full second)
    delay(1000);                         // Wait for the completion tone to finish playing
    
    Serial.println("=== Countdown Complete ==="); // FILLED IN
}

void loop() { 
    // Intentionally kept completely empty because the project logic runs exactly once in setup()
}