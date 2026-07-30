#ifndef PIDS_H
#define PIDS_H
struct liftPID {
    double p;
    double i;
    double d;
    double iRange;
    
    double prevError;
    double integral;
    double derivative;
    liftPID(double cp, double ci, double cd, double ciRange);
    double update(double error);
    void reset();
};
#endif