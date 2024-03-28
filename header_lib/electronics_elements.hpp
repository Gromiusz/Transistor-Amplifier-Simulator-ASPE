#pragma once
#include <Eigen/Dense>

using Eigen::MatrixXd;
using node = uint8_t;

class ElectronicsElement {
public:
    node first;
    node last;
    virtual void insert(MatrixXd& _board, node _first, node _last) = 0;
};

class Resistor: public ElectronicsElement {
    double conductivity;
public:
    Resistor(double resistance);
    double getConductivity();
    void insert(MatrixXd& _board, node _first, node _last) override;
};

class CurrentSource: public ElectronicsElement  {
    double sourceCurrentValue;
public:
    CurrentSource(double _sourceCurrentValue);
    double getSourceCurrentValue();
    void insert(MatrixXd& _board, node _first, node _last) override;
};

class Capacitor: public ElectronicsElement  {
    Resistor resistor;
    CurrentSource csource;
public:
    Capacitor(double _resistance, double _sourceCurrentValue);
    double getResistorConductivity();
    double getSourceCurrentValue();
    //void insert(MatrixXd& _board, node _first, node _last) override;

};