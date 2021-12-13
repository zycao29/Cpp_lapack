//
//  my_matrix.h
//  hw7
//
//  Created by Zhaoyang Cao on 12/11/21.
//

#ifndef MY_MATRIX_H
#define MY_MATRIX_H

#include <iostream>
#include "lapack_prototypes.h"
#include <string>

template <typename T>
class my_matrix{
private:
  int num_rows;
  int num_columns;
  T **ptr;
  std::string name;
  
  public:

  // default constructor
  my_matrix();

  // user constructor
  my_matrix(int Nrows, int Ncols, std::string mat_name);
  
  // copy constructor
  my_matrix(const my_matrix<T>& mat);

  // for printing out elements
  void display();
  
  // destructor
  ~my_matrix();

  // some operators
  my_matrix<T>& operator=(const my_matrix<T>& mat);
  T& operator()(int row, int col);
  my_matrix<T> operator+(const my_matrix<T>& mat);
  my_matrix<T> operator|(const my_matrix<T>& B);
  
};

// default constructor
template <typename T>
my_matrix<T>::my_matrix(){
  num_rows = 2;
  num_columns = 2;
  name = "default";
  // initialize with column major format
  ptr = new T*[num_columns];
  ptr[0] = new T[num_columns * num_rows];
  for (int jj = 1; jj < num_columns; jj++){
    ptr[jj] = ptr[0] + num_rows * jj;
  }
}

// user constructor
template <typename T>
my_matrix<T>::my_matrix(int Nrows, int Ncols, std::string mat_name){
  try{
    if (Nrows < 1 || Ncols < 1){
      throw "matrix dimensions do not make sense.";
    }
    else {
        //continue here
        this->num_rows = Nrows;
        this->num_columns = Ncols;
        
        ptr = new T*[Ncols];  // warning
        
        for (int jj = 0; jj < Ncols; jj++){
                ptr[jj] = new T[Nrows];
        }
    }
  }
  catch (const char* problem){
    std::cout << "exception encountered: " << problem << std::endl;
    ptr = new T*[1];
    ptr[0] = new T[1];
  }
}

// copy constructor
template <typename T>
my_matrix<T>::my_matrix(const my_matrix<T>& mat){
  num_rows = mat.num_rows;
  num_columns = mat.num_columns;
  name = mat.name;
  // initialize with column major format
  // continue here
  //
  // copy elements
  for (int jj = 0; jj < num_columns; jj++){
    for (int ii = 0; ii < num_rows; ii++){
      ptr[jj][ii] = mat.ptr[jj][ii];
    }
  }
}

// destructor
template <typename T>
my_matrix<T>::~my_matrix(){
  delete[] ptr[0];
  delete[] ptr;
}

// for printing out elements
template <typename T>
void my_matrix<T>::display(){
  std::cout << this->name << " = \n";
  for (int ii = 0; ii < this->num_rows; ii++){
    for (int jj = 0; jj < this->num_columns; jj++){
      //std::cout << this->ptr[jj][ii] << " ";
      std::cout << (*this)(ii,jj) << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

// implementation of operators
template <typename T>
my_matrix<T>& my_matrix<T>::operator=(const my_matrix<T>& mat){
  if (this != &mat){
    // deallocate memory
    for (int jj = 0; jj < num_columns; jj++){
      delete[] ptr[jj];
    }
    delete[] ptr;

    // reallocate memory
    this->num_rows = mat.num_rows;
    this->num_columns = mat.num_columns;
    // initialize with column major format
    // continue here
    //
    //
    //

    // copy elements
    // continue here
    //
    //
    //
  }
  
  return *this;
}

/* overload operator()(int row, int col) here */
// continue here
//
//

template <typename T>
my_matrix<T> my_matrix<T>::operator+(const my_matrix<T>& mat){
  my_matrix<T> sum(this->num_rows, this->num_columns, "sum");
  // continue here
  //
  //
  //
  
  return sum;
}

template<>
my_matrix<double> my_matrix<double>::operator|(const my_matrix<double>& B){

  int N = this->num_rows;
  int NRHS = B.num_columns;
  my_matrix<double> A_copy(*this);
  my_matrix<double> B_copy(B);
  int LDA = this->num_rows;
  int* IPIV = new int[N];
  int LDB = B.num_rows;
  int INFO = 0;

  dgesv_(&N, &NRHS, A_copy.ptr[0], &LDA, IPIV, B_copy.ptr[0], &LDB, &INFO);
  
  std::cout << "INFO = " << INFO << std::endl;
  
  delete[] IPIV;
  return B_copy;
}

template<>
my_matrix<float> my_matrix<float>::operator|(const my_matrix<float>& B){

  //continue here for sgesv_
  //
  //
  //
}

#endif
