//  main.cpp
//  hw7
//
//  Created by Zhaoyang Cao on 12/11/21.

#include "my_matrix.h"
#include "lapack_prototypes.h"
#include <iostream>
#include <string>

int main(void){

  my_matrix<double> testA(2, 2, "A");
  my_matrix<double> testB(2, 1, "B");
  my_matrix<double> testsum = testA + testB;

  my_matrix<float> C(3, 0, "C");
  
  my_matrix<double> A(2, 2, "A");
  my_matrix<double> B(2, 1, "B");
  A(0,0) = 1;
  A(0,1) = 0;
  A(1,0) = 0;
  A(1,1) = 1;
  B(0,0) = 1;
  B(1,0) = 2;
  A.display();
  B.display();
  my_matrix<double> sol(2, 1, "sol");
  sol = A|B;
  sol.display();

  my_matrix<double> A2(3, 3, "A2");
  my_matrix<double> B2(3, 1, "B2");
  // ....
    
    
    
  
    
    
  
    
  
  return 0;
}
