#include "alert.h"

std::string Alert::alerts;

Alert::Alert(){
    alerts = " ";
}

void Alert::addMessage(std::string newMessage){
    alerts += newMessage + "\n";
}


std::string Alert::getAlerts(){
    return alerts;
}



