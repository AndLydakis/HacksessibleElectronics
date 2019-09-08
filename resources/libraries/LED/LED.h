#include <Arduino.h>

/**
* @brief Class to interface with a LED
*/
class LED {
public:
    /**
     * @brief Constructor
     * @param pin the number of the digital pin you have connected the LED to
     */
    LED(int pin) {
        pinMode(pin, OUTPUT);
        _pin = pin;
    }

    /**
     * @brief Blink for a short duration
     */
    void dot();

    /**
     * @brief Blink for a longer duration
     */
    void dash();

    /**
     * @brief Blink for a custom duration
     * @param duration: Duration of ON part, in milliseconds
     */
    void blink(int duration);

    /**
     * @brief Return the pin number that the LED was initially connected to
     * @return the pin number that the led was initially connected to
     */
    int get_pin();

    /**
     * @brief Set the number of the pin the LED is connected to
     * @param pin: The number of the pin the LED is connected to
     */
    void set_pin(int pin);

private:
    int _pin;
};
