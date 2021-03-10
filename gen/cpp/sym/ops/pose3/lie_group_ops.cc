//  ----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include "./lie_group_ops.h"

#include <algorithm>
#include <cmath>

#include <sym/pose3.h>

namespace sym {
namespace pose3 {

template <typename Scalar>
sym::Pose3<Scalar> LieGroupOps<Scalar>::FromTangent(const Eigen::Matrix<Scalar, 6, 1>& vec,
                                                    const Scalar epsilon) {
  // Total ops: 16

  // Input arrays

  // Intermediate terms (3)
  const Scalar _tmp0 = std::sqrt((epsilon * epsilon) + (vec(0, 0) * vec(0, 0)) +
                                 (vec(1, 0) * vec(1, 0)) + (vec(2, 0) * vec(2, 0)));
  const Scalar _tmp1 = (1.0 / 2.0) * _tmp0;
  const Scalar _tmp2 = std::sin(_tmp1) / _tmp0;

  // Output terms (1)
  Eigen::Matrix<Scalar, 7, 1> _res;

  _res[0] = _tmp2 * vec(0, 0);
  _res[1] = _tmp2 * vec(1, 0);
  _res[2] = _tmp2 * vec(2, 0);
  _res[3] = std::cos(_tmp1);
  _res[4] = vec(3, 0);
  _res[5] = vec(4, 0);
  _res[6] = vec(5, 0);

  return sym::Pose3<Scalar>(_res);
}

template <typename Scalar>
Eigen::Matrix<Scalar, 6, 1> LieGroupOps<Scalar>::ToTangent(const sym::Pose3<Scalar>& a,
                                                           const Scalar epsilon) {
  // Total ops: 19

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _a = a.Data();

  // Intermediate terms (2)
  const Scalar _tmp0 = std::min<Scalar>(std::fabs(_a[3]), 1 - epsilon);
  const Scalar _tmp1 = 2 * (2 * std::min<Scalar>(0, (((_a[3]) > 0) - ((_a[3]) < 0))) + 1) *
                       std::acos(_tmp0) / std::sqrt(1 - (_tmp0 * _tmp0));

  // Output terms (1)
  Eigen::Matrix<Scalar, 6, 1> _res;

  _res(0, 0) = _a[0] * _tmp1;
  _res(1, 0) = _a[1] * _tmp1;
  _res(2, 0) = _a[2] * _tmp1;
  _res(3, 0) = _a[4];
  _res(4, 0) = _a[5];
  _res(5, 0) = _a[6];

  return _res;
}

template <typename Scalar>
sym::Pose3<Scalar> LieGroupOps<Scalar>::Retract(const sym::Pose3<Scalar>& a,
                                                const Eigen::Matrix<Scalar, 6, 1>& vec,
                                                const Scalar epsilon) {
  // Total ops: 52

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _a = a.Data();

  // Intermediate terms (8)
  const Scalar _tmp0 = std::sqrt((epsilon * epsilon) + (vec(0, 0) * vec(0, 0)) +
                                 (vec(1, 0) * vec(1, 0)) + (vec(2, 0) * vec(2, 0)));
  const Scalar _tmp1 = (1.0 / 2.0) * _tmp0;
  const Scalar _tmp2 = std::sin(_tmp1) / _tmp0;
  const Scalar _tmp3 = _a[1] * _tmp2;
  const Scalar _tmp4 = _a[2] * _tmp2;
  const Scalar _tmp5 = std::cos(_tmp1);
  const Scalar _tmp6 = _a[3] * _tmp2;
  const Scalar _tmp7 = _a[0] * _tmp2;

  // Output terms (1)
  Eigen::Matrix<Scalar, 7, 1> _res;

  _res[0] = _a[0] * _tmp5 + _tmp3 * vec(2, 0) - _tmp4 * vec(1, 0) + _tmp6 * vec(0, 0);
  _res[1] = _a[1] * _tmp5 + _tmp4 * vec(0, 0) + _tmp6 * vec(1, 0) - _tmp7 * vec(2, 0);
  _res[2] = _a[2] * _tmp5 - _tmp3 * vec(0, 0) + _tmp6 * vec(2, 0) + _tmp7 * vec(1, 0);
  _res[3] = _a[3] * _tmp5 - _tmp3 * vec(1, 0) - _tmp4 * vec(2, 0) - _tmp7 * vec(0, 0);
  _res[4] = _a[4] + vec(3, 0);
  _res[5] = _a[5] + vec(4, 0);
  _res[6] = _a[6] + vec(5, 0);

  return sym::Pose3<Scalar>(_res);
}

template <typename Scalar>
Eigen::Matrix<Scalar, 6, 1> LieGroupOps<Scalar>::LocalCoordinates(const sym::Pose3<Scalar>& a,
                                                                  const sym::Pose3<Scalar>& b,
                                                                  const Scalar epsilon) {
  // Total ops: 63

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _b = b.Data();

  // Intermediate terms (3)
  const Scalar _tmp0 = _a[0] * _b[0] + _a[1] * _b[1] + _a[2] * _b[2] + _a[3] * _b[3];
  const Scalar _tmp1 = std::min<Scalar>(std::fabs(_tmp0), 1 - epsilon);
  const Scalar _tmp2 = 2 * (2 * std::min<Scalar>(0, (((_tmp0) > 0) - ((_tmp0) < 0))) + 1) *
                       std::acos(_tmp1) / std::sqrt(1 - (_tmp1 * _tmp1));

  // Output terms (1)
  Eigen::Matrix<Scalar, 6, 1> _res;

  _res(0, 0) = _tmp2 * (-_a[0] * _b[3] - _a[1] * _b[2] + _a[2] * _b[1] + _a[3] * _b[0]);
  _res(1, 0) = _tmp2 * (_a[0] * _b[2] - _a[1] * _b[3] - _a[2] * _b[0] + _a[3] * _b[1]);
  _res(2, 0) = _tmp2 * (-_a[0] * _b[1] + _a[1] * _b[0] - _a[2] * _b[3] + _a[3] * _b[2]);
  _res(3, 0) = -_a[4] + _b[4];
  _res(4, 0) = -_a[5] + _b[5];
  _res(5, 0) = -_a[6] + _b[6];

  return _res;
}

}  // namespace pose3
}  // namespace sym

// Explicit instantiation
template struct sym::pose3::LieGroupOps<double>;
template struct sym::pose3::LieGroupOps<float>;
