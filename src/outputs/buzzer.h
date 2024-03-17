// buzzer.h
#ifndef BUZZER_H
#define BUZZER_H

class Buzzer
{
public:
    Buzzer();
    void begin();
    void buzzOnce();
    void setBuzzState(bool buzzState);

private:
    bool buzzed = false;
};

#endif // BUZZER_H
