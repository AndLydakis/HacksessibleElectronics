//
// Created by andreas on 08/09/2019.
//
#include "MoistureSensor.h"
MoistureSensor::MoistureSensor(int pin, int pow_pin, int thres, int led, int debug) {
    analog_pin = pin;
    power_pin = pow_pin;
    dry_threshold = thres;
    if (led > 0) {
        pinMode(led, OUTPUT);
    }
    pinMode(power_pin, OUTPUT);
    debug = debug;
}

void MoistureSensor::set_led_pin(int no) {
    led_pin = no;
}

void MoistureSensor::set_dry_thres(int thres) {
    dry_threshold = thres;
}

void MoistureSensor::set_analog_pin(int pin) {
    analog_pin = pin;
}

void MoistureSensor::set_pow_pin(int pin) {
    power_pin = pin;
    pinMode(power_pin, OUTPUT);
}

int MoistureSensor::get_dry_thres() {
    return dry_threshold;
}

int MoistureSensor::get_led_pin() {
    return led_pin;
}

int MoistureSensor::get_analog_pin() {
    return analog_pin;
}

int MoistureSensor::get_pow_pin() {
    return power_pin;
}

void MoistureSensor::toggle_power(int mode) {
    if (mode == 1) {
        digitalWrite(power_pin, HIGH);
        delay(100);
        return;
    }
    digitalWrite(power_pin, LOW);
    delay(100);
    return;
}

void MoistureSensor::info() {
    Serial.println("------- Moisture Sensor -------");
    Serial.print("Analog Output Pin: ");
    Serial.println(analog_pin);
    Serial.print("Digital Power Pin: ");
    Serial.println(power_pin);
    Serial.print("Led Pin: ");
    Serial.println(led_pin);
    Serial.print("Dry Threshold: ");
    Serial.println(dry_threshold);
}

int MoistureSensor::get_measurement() {
    toggle_power(1);
    int val = analogRead(analog_pin);
    if (debug == 1) {
        Serial.print("Sensor in pin: ");
        Serial.print(analog_pin);
        Serial.print(", Value: ");
        Serial.println(val);
    }
    if (led_pin == -1) {
        return val;
    }
    if (val < dry_threshold) {
        digitalWrite(led_pin, HIGH);
    } else {
        digitalWrite(led_pin, LOW);
    }
    toggle_power(0);
    return val;
}

