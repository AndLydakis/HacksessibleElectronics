#include <Arduino.h>

/**
 * Helper class for operating a capacitive moisture sensor
 */
class MoistureSensor {
private:
    // Pin operating a LED indicating when a measurement is taken
    int led_pin;
    // Pin for reading measurements off the sensor
    int analog_pin;
    // Power pin (who would have thought)
    int power_pin;
    // Measurements lower than this indicate that watering is necessary
    int dry_threshold;
    // If equal to one, print debugging messages
    int debug;
public:
    /**
     * Constructor
     * @param pin Pin for reading measurements off the sensor
     * @param pow_pin Pin for reading measurements off the sensor
     * @param thres Measurements lower than this indicate that watering is necessary
     * @param led Pin operating a LED indicating when a measurement is taken
     * @param debug If equal to one, print debugging messages
     */
    MoistureSensor(int pin, int pow_pin, int thres, int led, int debug);

    /**
     * Set the LED pin
     * @param no the number of the new LED pin
     */
    void set_led_pin(int no);

    /**
     * Set the dry threshold
     * @param thres the new dry threshold
     */
    void set_dry_thres(int thres);

    /**
     * Set the measurement pin
     * @param pin the new measurement pin
     */
    void set_analog_pin(int pin);

    /**
     * Set the measurement pin
     * @param pin the new measurement pin
     */
    void set_pow_pin(int pin);

    /**
     * Powers or deactivates the sensor
     * @param mode if 1, power the sensor, else deactivate
     */
    void toggle_power(int mode);

    /**
     * Return the LED pin number
     * @return the LED pin number
     */
    int get_led_pin();

    /**
     * Return the dry threshold
     * @return the dry threshold
     */
    int get_dry_thres();

    /**
     * Return the analog pin
     * @return the analog pin
     */
    int get_analog_pin();

    /**
     * Return the power pin
     * @return the power pin
     */
    int get_pow_pin();

    /**
     * Get a measurement form the sensor
     * @return the value measured by the sensor
     */
    int get_measurement();

    /**
     * Prints information about the sensor setup
     */
    void info();
};
