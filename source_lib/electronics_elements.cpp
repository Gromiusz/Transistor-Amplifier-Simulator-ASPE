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

void Resistor::insert(MatrixXd& _board, node _first, node _last)
{
    _board(_first, _first) = conductivity;
    _board(_first, _last) = -conductivity;
    _board(_last, _first) = -conductivity;
    _board(_last, _last) = conductivity;
}


// ############### CURRENTSOURCE ####################
CurrentSource::CurrentSource(double _sourceCurrentValue): sourceCurrentValue(_sourceCurrentValue) {}

double CurrentSource::getSourceCurrentValue()
{
    return sourceCurrentValue;
}

void CurrentSource::insert(MatrixXd& _board, node _first, node _last)
{
    _board(_first, _first) = sourceCurrentValue;
    _board(_first, _last) = -sourceCurrentValue;
    _board(_last, _first) = -sourceCurrentValue;
    _board(_last, _last) = sourceCurrentValue;
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
