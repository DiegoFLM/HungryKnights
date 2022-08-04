


#ifndef ALERT_HH
#define ALERT_HH

#include <iostream>
#include <string>


class Alert{
    private:
        static std::string alerts;

    public:
        Alert();
        void addMessage(std::string newMessage);
        std::string getAlerts();
};

#else
class Alert;
#endif