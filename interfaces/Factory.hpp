/* 
 * File:   Factory.hpp
 * Author: leo
 *
 * Created on September 13, 2014, 1:37 AM
 */

#ifndef FACTORY_HPP
#define	FACTORY_HPP

#include "IAlgorithms.hpp"
#include "../controllers/algorithmController.hpp"
#include "ISettings.hpp"
#include "../controllers/Utils.hpp"
class Factory {
public:
    Factory();
    Factory(const Factory& orig);
    IAlgorithms *getAlgorithms();
    ISettings *getSettings();
    virtual ~Factory();
private:

};

#endif	/* FACTORY_HPP */

