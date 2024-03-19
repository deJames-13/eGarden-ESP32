// buzzer.h
#ifndef BUZZER_H
#define BUZZER_H

class Buzzer
{
public:
    Buzzer();
    void begin(int pin);
    void buzzOnce();
    void setBuzzState(bool buzzState);

private:
    bool buzzed = false;
    int pin;
};

#endif // BUZZER_H
