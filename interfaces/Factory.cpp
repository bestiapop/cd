/* 
 * File:   Factory.cpp
 * Author: leo
 * 
 * Created on September 13, 2014, 1:37 AM
 */

#include "Factory.hpp"

Factory::Factory() {
}

Factory::Factory(const Factory& orig) {
}

Factory::~Factory() {
}

IAlgorithms *Factory::getAlgorithms() {
    return new algorithmController();
}

