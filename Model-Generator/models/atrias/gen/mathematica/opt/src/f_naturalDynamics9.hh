/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:36:22 GMT-05:00
 */
#include <Eigen/Dense>

#ifdef MATLAB_MEX_FILE
// No need for external definitions
#else // MATLAB_MEX_FILE

namespace symbolic_expression
{
  namespace basic
  {

    void f_naturalDynamics9_raw(double *p_output1, const double *var);

    inline void f_naturalDynamics9(Eigen::MatrixXd &p_output1, const Eigen::VectorXd &var)
    {
      // Check
      // - Inputs
      assert_size_matrix(var, 54, 1);

	
      // - Outputs
      assert_size_matrix(p_output1, 1, 1);


      // set zero the matrix
      p_output1.setZero();


      // Call Subroutine with raw data
      f_naturalDynamics9_raw(p_output1.data(), var.data());
    }
  
  }
}

#endif // MATLAB_MEX_FILE
