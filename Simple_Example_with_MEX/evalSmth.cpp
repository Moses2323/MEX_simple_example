#include <mex.h>
#include <iostream>

bool checkingMATLABarguments( int nlhs, mxArray* plhs[], 
                              int nrhs, const mxArray* prhs[] )
{
    if ( nrhs != 3 )
    {
        mexErrMsgTxt( "Number of input arguments should be equal to 3\n" );
        return false;
    }
    if ( nlhs != 2 )
    {
        mexErrMsgTxt( "Number of output arguments should be equal to 2\n" );
        return false;
    }

    return true;
}


/*! \brief Entry point in the code for Matlab.  Equivalent to main().
 *
 *  \param nlhs number of left hand mxArrays to return
 *  \param plhs array of pointers to the output mxArrays
 *  \param nrhs number of input mxArrays
 *  \param prhs array of pointers to the input mxArrays.
 */
void mexFunction( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[] )
{
    mexPrintf( "Starting MEX function\n" );

    // checking input arguments
    bool okInput = checkingMATLABarguments( nlhs, plhs, nrhs, prhs );
    if ( !okInput )
    {
        mexErrMsgTxt( "Something wrong with input arguments\n" );
        return;
    }

    // doing smth
    double a = ( (double*)mxGetData( prhs[0] ) )[0];
    double b = ( (double*)mxGetData( prhs[1] ) )[0];
    double c = ( (double*)mxGetData( prhs[2] ) )[0];

    //    usual C++ output code is working in MATLAB too
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;

    double sum = a + b + c;
    double mult = a * b * c;

    // writing output to the MATLAB format
    plhs[0] = mxCreateDoubleMatrix( 1, 1, mxREAL );
    plhs[1] = mxCreateDoubleMatrix( 1, 1, mxREAL );

    double* pFirstArg = (double*)mxGetDoubles( plhs[0] );
    double* pSecondArg = (double*)mxGetDoubles( plhs[1] );

    memcpy( pFirstArg, &sum, sizeof( double ) );
    memcpy( pSecondArg, &mult, sizeof( double ) );

    mexPrintf( "\nFinishing MEX function\n" );
}
