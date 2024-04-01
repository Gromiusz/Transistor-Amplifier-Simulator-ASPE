#include "../header_lib/electronics_elements.hpp"


//############ RESISTOR ############
Resistor::Resistor(double resistance)
{
    if(resistance>0)
    {
        conductivity = 1/resistance;
    }

   // throw notPositiveConductivityException;
}

double Resistor::getConductivity()
{
    return conductivity;
}

void Resistor::insert(MatrixXd& _left_matrix, MatrixXd& _variable_matrix, MatrixXd& _right_matrix, Node _first, Node _last)
{
    _left_matrix(_first, _first) = conductivity;
    _left_matrix(_first, _last) = -conductivity;
    _left_matrix(_last, _first) = -conductivity;
    _left_matrix(_last, _last) = conductivity;
}


// ############### CURRENTSOURCE ####################
CurrentSource::CurrentSource(double _sourceCurrentValue): sourceCurrentValue(_sourceCurrentValue) {}

double CurrentSource::getSourceCurrentValue()
{
    return sourceCurrentValue;
}

void CurrentSource::insert(MatrixXd& _left_matrix, MatrixXd& _variable_matrix, MatrixXd& _right_matrix, Node _first, Node _last)
{
    _right_matrix(_first) = -sourceCurrentValue;
    _right_matrix(_last) = sourceCurrentValue;
}



// ################ CAPACITOR ####################
Capacitor::Capacitor(double _resistance, double _sourceCurrentValue): resistor(_resistance), csource(_sourceCurrentValue) {}

double Capacitor::getResistorConductivity()
{
    return resistor.getConductivity();
}

double Capacitor::getSourceCurrentValue()
{
    return csource.getSourceCurrentValue();
}

void Capacitor::insert(MatrixXd& _left_matrix, MatrixXd& _variable_matrix, MatrixXd& _right_matrix, Node _first, Node _last)
{
    _right_matrix(_first) = -csource.getSourceCurrentValue();
    _right_matrix(_last) = csource.getSourceCurrentValue();
}

void Capacitor::compute_eq_current(MatrixXd& _left_matrix, MatrixXd& _variable_matrix, MatrixXd& _right_matrix)
{
    currentSource.current = capcity/h * (first.voltage - last.voltage)
    _right_matrix(_first) = - currentSource.current;
    _right_matrix(_last) = currentSource.current;
}


// ################# TRANSISTOR_PART #############

void TransistorPart::insert(MatrixXd& _left_matrix, MatrixXd& _variable_matrix, MatrixXd& _right_matrix, Node _first, Node _last)
{
    capacitor.insert(_left_matrix, _variable_matrix, _right_matrix, _first, _last);

}

void TransistorPart::compute_eq_current(MatrixXd& _left_matrix, MatrixXd& _variable_matrix, MatrixXd& _right_matrix)
{
    capacitor.setSourceCurrent() = dCurrent - gmConductancy * (gVoltage - last.voltage) - gdConductancy * (first.voltage - last.voltage);
}
