/**
 * Helper class for operating a mini 5V pump
 */
class Pump {
private:
    // The input pin the pump is connected to
    int pump_pin;
public:
    /**
     * Constructor
     * @param pin The input pin the pump is connected to
     */
    Pump(int pin) {
        pump_pin = pin;
        pinMode(pump_pin, OUTPUT);
    }

    /**
     * Turn the pump on for the given amount of milliseconds, then power it down
     * @param duration time in milliseconds for the pump to operate
     */
    void cycle_pump(int duration) {
        digitalWrite(pump_pin, HIGH);
        delay(duration);
        digitalWrite(pump_pin, LOW);
        delay(duration);
    }

    /**
     * Set the digital pin the pump is connected to
     * @param the digital pin the pump is connected to
     */
    void set_pin(int pin) { pump_pin = pin; }

    /**
     * Return the digital pin the pump is connected to
     * @return the digital pin the pump is connected to
     */
    int get_pin() { return pump_pin; }
};