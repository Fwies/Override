#include "main.h"
liftPID::liftPID(double cp, double ci, double cd, double ciRange) {
        p = cp;
        i = ci;
        d = cd;
        iRange = ciRange;
        
    }
    double liftPID::update(double error) {
        
        integral = integral + error; // add the integral
        if (error == 0 ) {
            integral = 0; // no integral if at target
        }
        if ( abs(error) > iRange) {
            integral = 0; // no integral if out of range
        }
        derivative = error - prevError; // calculate the derivative
        prevError = error; // save the previous error
        if(p*error + i*integral + d*derivative<0){ // if it is commanding negative power divide by a constant as gravity is working with it
            return (p*error + i*integral + d*derivative)/2.7;
        }
        return p*error + i*integral + d*derivative; // return the final output
    }
    void liftPID::reset() {
        prevError = 0;
        integral = 0;
    }
