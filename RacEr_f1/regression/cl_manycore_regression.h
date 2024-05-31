/// Added function
static inline double
RacEr_mc_calculate_double_error (double expected, double result)
{
  if (fabs (expected) < 1e-20)
    return (fabs (expected - result));
  return (fabs ((expected - result) / expected));
}
