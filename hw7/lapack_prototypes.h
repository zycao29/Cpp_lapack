//  lapack_prototypes.h
//  hw7
//
//  Created by Zhaoyang Cao on 12/12/21.

#ifndef LAPACK_PROTOTYPES_H
#define LAPACK_PROTOTYPES_H

// Here prototype dgesv_ and sgesv_,  don't forget extern "C" keyword
// code

extern "C" void sgesv_(int*, int*, float*,
                       int*, int*, float*, int*, int*);

extern "C" void dgesv_(int*, int*, double*,
                       int*, int*, double*, int*, int*);

#endif
