#include <iostream>
#include <Eigen/Dense>
#include "header_lib/electronics_elements.hpp"
 
using Eigen::MatrixXd;

constexpr int _size = 2;
MatrixXd board(_size, _size);

void insert(ElectronicsElement& element, node _first, node _last)
{
    element.first = _first;
    element.last = _last;
    element.insert(board, _first, _last);
}
 
int main()
{
  MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << m << std::endl;

  //Capacitor cap(3,5);
  

}