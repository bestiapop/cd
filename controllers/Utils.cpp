/* 
 * File:   Utils.cpp
 * Author: leo
 * 
 * Created on September 17, 2014, 11:45 PM
 */

#include "Utils.hpp"
Utils::Utils() {
}

bool Utils::getDebugMode() {
    return _debug;
}

void Utils::setDebugMode(bool debug) {
    _debug=debug;
}

Utils* Utils::instance() {
    if(_instance==NULL){
        _instance = new Utils();
    }
    return _instance;
}

Utils * Utils::_instance=NULL;

