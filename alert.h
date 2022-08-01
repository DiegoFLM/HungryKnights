
#include <iostream>
#include <string>

#ifndef ALERT_HH
#define ALERT_HH




class Alert{
    private:
        std::string alertMessages;

    public:
        Alert();
        void addMessage(std::string newMessage);
        //std::string getAlerts();
        void showMess();
};

#else
class Alert;
#endif