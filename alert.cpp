#include "alert.h"

//std::string Alert::alertMessages;

Alert::Alert(){
    alertMessages = "";
}

void Alert::addMessage(std::string newMessage){
    alertMessages += newMessage + "\n";
}

/*
std::string Alert::getAlerts(){
    return alertMessages;
}*/

void Alert::showMess(){
    std::cout << alertMessages << std::endl;
}


