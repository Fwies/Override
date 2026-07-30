#include "main.h"
liftPID::liftPID(double cp, double ci, double cd, double ciRange) {
        p = cp;
        i = ci;
        d = cd;
        iRange = ciRange;
        
    }
    double liftPID::update(double error) {
        
        integral = integral + error;
        if (error < 100) {
            integral = 0;
        }
        if ( abs(error) > iRange) {
            integral = 0;
        }
        derivative = error - prevError;
        prevError = error;
        if(p*error + i*integral + d*derivative<0){
            return (p*error + i*integral + d*derivative)/2.7;
        }
        return p*error + i*integral + d*derivative;
    }
    void liftPID::reset() {
        prevError = 0;
        integral = 0;
    }
