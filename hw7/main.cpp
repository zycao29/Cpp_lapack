//  main.cpp
//  hw7
//
//  Created by Zhaoyang Cao on 12/11/21.

#include "my_matrix.h"
#include "lapack_prototypes.h"
#include <iostream>
#include <string>

int main(void){

  // my_matrix<double> testA(2, 2, "A");
  // my_matrix<double> testB(2, 1, "B");
  // my_matrix<double> testsum = testA + testB;

  // my_matrix<float> C(3, 0, "C");
  
  // my_matrix<double> A(2, 2, "A");
  // my_matrix<double> B(2, 1, "B");
  // A(0,0) = 1;
  // A(0,1) = 0;
  // A(1,0) = 0;
  // A(1,1) = 1;
  // B(0,0) = 1;
  // B(1,0) = 2;
  // A.display();
  // B.display();
  // my_matrix<double> sol(2, 1, "sol");
  // sol = A|B;
  // sol.display();

  // my_matrix<double> A2(3, 3, "A2");
  // my_matrix<double> B2(3, 1, "B2");
  // ....


  // create matrix A1 and vector B. 
  my_matrix<float> A1(2, 2, "");
  my_matrix<float> B(3, 1, "B");  
  A1(0,0) = 1;
  A1(0,1) = 2;
  A1(1,0) = 3;
  A1(1,1) = 4;
  B(0,0) = 21;
  B(1,0) = 21;
  B(2,0) = 10;
  std::cout<<"A1"<<std::endl;
  A1.display();

  my_matrix<float> A2(A1);
  std::cout<<"A2"<<std::endl;
  A2.display();

  
  my_matrix<float> A3=A1+A2;
  std::cout<<"A3"<<std::endl;
  A3.display();
 
  my_matrix<float> A4(3,3,"A4");
  A4(0,0)=1;
  A4(0,1)=3;
  A4(0,2)=4;
  A4(1,0)=-1;
  A4(1,1)=5;
  A4(1,2)=1;
  A4(2,0)=0;
  A4(2,1)=2;
  A4(2,2)=1;
  std::cout<<"A4 is:"<<std::endl;
  A4.display();

  std::cout<<"Vector B is:"<<std::endl;
  B.display();
  //declare solution vector
  my_matrix<float> x(3,1,"x");

  x=A4|B;
  std::cout<<"The solution x is:"<<std::endl;
  x.display();
  return 0;
    
    
  
    
    
  
    
  
  return 0;
}
