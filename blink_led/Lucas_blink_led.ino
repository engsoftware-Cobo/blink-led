// Versão Lucas

#define LED 2

unsigned long start_time;
unsigned long current_time;
short call_stack = 0;

bool led_state = false;

void blink_led();
bool my_timer(unsigned long time_in_milliseconds);

void setup() {
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    Serial.println("Blinking...");
    
    if (my_timer(2000)) {
        blink_led();
    }
}

void blink_led() {
    led_state = !led_state;
    
    digitalWrite(LED, led_state ? HIGH : LOW);
}

bool my_timer(unsigned long time_in_milliseconds) {
    if (call_stack == 0) {
        call_stack++;
        
        start_time = millis();
        
        return false;
    }

    if (call_stack > 0) {
        current_time = millis();
        
        if (start_time + time_in_milliseconds <= current_time) { 
            call_stack = 0;
            
            return true;
        }
    }

    return false;
}
