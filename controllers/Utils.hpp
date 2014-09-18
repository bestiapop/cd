/* 
 * File:   Utils.hpp
 * Author: leo
 *
 * Created on September 17, 2014, 11:45 PM
 */

#ifndef UTILS_HPP
#define	UTILS_HPP
#include "../interfaces/ISettings.hpp"
#include <cstddef>

using namespace std;
class Utils: public ISettings{
public:
    
    static Utils* instance();
    virtual void setDebugMode(bool);
    bool getDebugMode();
private:
    Utils();
    static Utils * _instance;
    bool _debug;
};

#endif	/* UTILS_HPP */

