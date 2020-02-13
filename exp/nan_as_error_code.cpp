#include <cassert>
#include <cmath>

enum class ECode {
  INPUT_IS_NAN = 0xFFF0'0000'0000'0001,
  INPUT_IS_INFINITE,
  INPUT_IS_NEGATIVE
};

union result_or_code
{
double result;
ECode code;
}

result_or_code sqrt(double x) {
  if (std::isnan(x))
    return ECode::INPUT_IS_NAN;
  if (std::isinf(x))
    return ECode::INPUT_IS_INFINITE;
  if(x < 0)
    return ECode::INPUT_IS_NEGATIVE;
  return std::sqrt(x)
}

int main(void) {
  assert(sqrt(-1.).code == ECode::INPUT_IS_NEGATIVE);
  assert(sqrt(1./0.).code == ECode::INPUT_IS_INFINITE);
  assert(sqrt(0./0.).code == ECode::INPUT_IS_NAN);
  assert(sqrt(4.) == 2.);
}
