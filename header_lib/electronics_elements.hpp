#pragma once
#include <Eigen/Dense>

using Eigen::MatrixXd;
using node = uint8_t;

class Node {
public:
    double voltage;
    uint8_t number;
};

class ElectronicsElement {
public:
    Node first;
    Node last;
    virtual void insert(MatrixXd& _left_matrix, MatrixXd& _variable_matrix, MatrixXd& _right_matrix, Node _first, Node _last) = 0;
    virtual void compute_eq_current(MatrixXd& _left_matrix, MatrixXd& _variable_matrix, MatrixXd& _right_matrix) = 0;
};

class Resistor: public ElectronicsElement {
    double conductivity;
public:
    Resistor(double resistance);
    double getConductivity();
    void insert(MatrixXd& _left_matrix, MatrixXd& _variable_matrix, MatrixXd& _right_matrix, Node _first, Node _last) override;
};

class CurrentSource: public ElectronicsElement  {
    
public:
    double current;
    CurrentSource(double _sourceCurrentValue);
    double getSourceCurrentValue();
    void insert(MatrixXd& _left_matrix, MatrixXd& _variable_matrix, MatrixXd& _right_matrix, Node _first, Node _last) override;
};

class Capacitor: public ElectronicsElement  {
    Resistor resistor;
    CurrentSource currentSource;
    double capacity;
    double h;

public:
    Capacitor(double _resistance, double _sourceCurrentValue);
    double getResistorConductivity();
    double getSourceCurrentValue();
    void setSourceCurrent();
    void insert(MatrixXd& _left_matrix, MatrixXd& _variable_matrix, MatrixXd& _right_matrix, Node _first, Node _last) override;
    void compute_eq_current(MatrixXd& _left_matrix, MatrixXd& _variable_matrix, MatrixXd& _right_matrix) override;
};

// class CurrentSourceControlwithV: public

class TransistorPart: public ElectronicsElement {
    Capacitor capacitor;
public:
    double gdConductancy;
    double gmConductancy;
    double dCurrent;
    double gVoltage;

    void insert(MatrixXd& _left_matrix, MatrixXd& _variable_matrix, MatrixXd& _right_matrix, Node _first, Node _last) override;
    void compute_eq_current(MatrixXd& _left_matrix, MatrixXd& _variable_matrix, MatrixXd& _right_matrix) override;
}