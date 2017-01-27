/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:34:05 GMT-05:00
 */
#include <Eigen/Dense>

#ifdef MATLAB_MEX_FILE
// No need for external definitions
#else // MATLAB_MEX_FILE

namespace symbolic_expression
{
  namespace basic
  {

    void pe_com_vec_raw(double *p_output1, double *p_output2, double *p_output3, const double *x);

    inline void pe_com_vec(Eigen::MatrixXd &p_output1, Eigen::MatrixXd &p_output2, Eigen::MatrixXd &p_output3, const Eigen::VectorXd &x)
    {
      // Check
      // - Inputs
      assert_size_matrix(x, 32, 1);

	
      // - Outputs
      assert_size_matrix(p_output1, 1, 1);
assert_size_matrix(p_output2, 1, 1);
assert_size_matrix(p_output3, 1, 1);


      // set zero the matrix
      p_output1.setZero();
p_output2.setZero();
p_output3.setZero();


      // Call Subroutine with raw data
      pe_com_vec_raw(p_output1.data(), p_output2.data(), p_output3.data(), x.data());
    }
  
  }
}

#endif // MATLAB_MEX_FILE
