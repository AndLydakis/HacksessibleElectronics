#include "LED.h"
void LED::dot() {
    digitalWrite(_pin, HIGH);
    delay(250);
    digitalWrite(_pin, LOW);
    delay(250);
}

void LED::dash() {
    digitalWrite(_pin, HIGH);
    delay(1000);
    digitalWrite(_pin, LOW);
    delay(250);
}

void LED::blink(int duration) {
    if (duration < 0) {
        return;
    }
    digitalWrite(_pin, HIGH);
    delay(duration);
    digitalWrite(_pin, LOW);
}

void LED::set_pin(int pin) {
    if (pin < 0) {
        return;
    }
    _pin = pin;
}

int LED::get_pin() {
    return _pin;
}