// -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <Eigen/Dense>
#include <sym/pose3.h>

namespace sym {

/**
 * Composition of two elements in the group.
 *
 * Returns:
 *     Element: a @ b
 *     geo.Matrix: Jacobian for arg 1 (b)
 */
template <typename Scalar>
sym::Pose3<Scalar> ComposePose3_ValueAndJacobian1(
    const sym::Pose3<Scalar>& a, const sym::Pose3<Scalar>& b,
    Eigen::Matrix<Scalar, 6, 6>* const res_D_b = nullptr) {
  // Total ops: 204

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _b = b.Data();

  // Intermediate terms (63)
  const Scalar _tmp0 = _a[0] * _b[3] + _a[1] * _b[2] - _a[2] * _b[1] + _a[3] * _b[0];
  const Scalar _tmp1 = -_a[0] * _b[2] + _a[1] * _b[3] + _a[2] * _b[0] + _a[3] * _b[1];
  const Scalar _tmp2 = _a[0] * _b[1] - _a[1] * _b[0] + _a[2] * _b[3] + _a[3] * _b[2];
  const Scalar _tmp3 = -_a[0] * _b[0] - _a[1] * _b[1] - _a[2] * _b[2] + _a[3] * _b[3];
  const Scalar _tmp4 = 2 * _a[1];
  const Scalar _tmp5 = _a[3] * _tmp4;
  const Scalar _tmp6 = 2 * _a[0];
  const Scalar _tmp7 = _a[2] * _tmp6;
  const Scalar _tmp8 = _tmp5 + _tmp7;
  const Scalar _tmp9 = 2 * _a[2];
  const Scalar _tmp10 = _a[3] * _tmp9;
  const Scalar _tmp11 = _a[1] * _tmp6;
  const Scalar _tmp12 = -_tmp10 + _tmp11;
  const Scalar _tmp13 = -2 * (_a[1] * _a[1]);
  const Scalar _tmp14 = 1 - 2 * (_a[2] * _a[2]);
  const Scalar _tmp15 = _tmp13 + _tmp14;
  const Scalar _tmp16 = _a[3] * _tmp6;
  const Scalar _tmp17 = _a[2] * _tmp4;
  const Scalar _tmp18 = -_tmp16 + _tmp17;
  const Scalar _tmp19 = -2 * (_a[0] * _a[0]);
  const Scalar _tmp20 = _tmp14 + _tmp19;
  const Scalar _tmp21 = _tmp10 + _tmp11;
  const Scalar _tmp22 = _tmp13 + _tmp19 + 1;
  const Scalar _tmp23 = _tmp16 + _tmp17;
  const Scalar _tmp24 = -_tmp5 + _tmp7;
  const Scalar _tmp25 = 2 * _tmp0;
  const Scalar _tmp26 = _a[3] * _tmp25;
  const Scalar _tmp27 = 2 * _tmp1;
  const Scalar _tmp28 = _a[2] * _tmp27;
  const Scalar _tmp29 = _tmp2 * _tmp4;
  const Scalar _tmp30 = _tmp3 * _tmp6;
  const Scalar _tmp31 = -_tmp26 - _tmp28 + _tmp29 + _tmp30;
  const Scalar _tmp32 = (1.0 / 2.0) * _b[0];
  const Scalar _tmp33 = -_tmp31 * _tmp32;
  const Scalar _tmp34 = _a[2] * _tmp25;
  const Scalar _tmp35 = _a[3] * _tmp27;
  const Scalar _tmp36 = _tmp3 * _tmp4;
  const Scalar _tmp37 = _tmp2 * _tmp6;
  const Scalar _tmp38 = _tmp34 - _tmp35 + _tmp36 - _tmp37;
  const Scalar _tmp39 = (1.0 / 2.0) * _b[1];
  const Scalar _tmp40 = -_tmp38 * _tmp39;
  const Scalar _tmp41 = _tmp0 * _tmp4;
  const Scalar _tmp42 = _tmp1 * _tmp6;
  const Scalar _tmp43 = 2 * _tmp2;
  const Scalar _tmp44 = _a[3] * _tmp43;
  const Scalar _tmp45 = _tmp3 * _tmp9;
  const Scalar _tmp46 = _tmp41 - _tmp42 + _tmp44 - _tmp45;
  const Scalar _tmp47 = (1.0 / 2.0) * _b[2];
  const Scalar _tmp48 = _a[2] * _tmp43 + 2 * _a[3] * _tmp3 + _tmp0 * _tmp6 + _tmp1 * _tmp4;
  const Scalar _tmp49 = (1.0 / 2.0) * _b[3];
  const Scalar _tmp50 = _tmp48 * _tmp49;
  const Scalar _tmp51 = (1.0 / 2.0) * _tmp31;
  const Scalar _tmp52 = _tmp32 * _tmp38;
  const Scalar _tmp53 = _tmp47 * _tmp48;
  const Scalar _tmp54 = _tmp31 * _tmp47;
  const Scalar _tmp55 = _tmp39 * _tmp48;
  const Scalar _tmp56 = _tmp26 + _tmp28 - _tmp29 - _tmp30;
  const Scalar _tmp57 = (1.0 / 2.0) * _tmp56;
  const Scalar _tmp58 = -_tmp41 + _tmp42 - _tmp44 + _tmp45;
  const Scalar _tmp59 = -_tmp47 * _tmp58 + _tmp50;
  const Scalar _tmp60 = _tmp32 * _tmp48;
  const Scalar _tmp61 = _tmp39 * _tmp58;
  const Scalar _tmp62 = -_tmp34 + _tmp35 - _tmp36 + _tmp37;

  // Output terms (2)
  Eigen::Matrix<Scalar, 7, 1> _res;

  _res[0] = _tmp0;
  _res[1] = _tmp1;
  _res[2] = _tmp2;
  _res[3] = _tmp3;
  _res[4] = _a[4] + _b[4] * _tmp15 + _b[5] * _tmp12 + _b[6] * _tmp8;
  _res[5] = _a[5] + _b[4] * _tmp21 + _b[5] * _tmp20 + _b[6] * _tmp18;
  _res[6] = _a[6] + _b[4] * _tmp24 + _b[5] * _tmp23 + _b[6] * _tmp22;

  if (res_D_b != nullptr) {
    Eigen::Matrix<Scalar, 6, 6>& _res_D_b = (*res_D_b);

    _res_D_b(0, 0) = _tmp33 + _tmp40 + _tmp46 * _tmp47 + _tmp50;
    _res_D_b(0, 1) = -_b[1] * _tmp51 + _tmp46 * _tmp49 + _tmp52 - _tmp53;
    _res_D_b(0, 2) = -_tmp32 * _tmp46 + _tmp38 * _tmp49 - _tmp54 + _tmp55;
    _res_D_b(0, 3) = 0;
    _res_D_b(0, 4) = 0;
    _res_D_b(0, 5) = 0;
    _res_D_b(1, 0) = -_b[1] * _tmp57 + _tmp49 * _tmp58 - _tmp52 + _tmp53;
    _res_D_b(1, 1) = _tmp32 * _tmp56 + _tmp40 + _tmp59;
    _res_D_b(1, 2) = _b[3] * _tmp57 - _tmp38 * _tmp47 - _tmp60 + _tmp61;
    _res_D_b(1, 3) = 0;
    _res_D_b(1, 4) = 0;
    _res_D_b(1, 5) = 0;
    _res_D_b(2, 0) = -_tmp32 * _tmp58 + _tmp49 * _tmp62 + _tmp54 - _tmp55;
    _res_D_b(2, 1) = _b[3] * _tmp51 - _tmp47 * _tmp62 + _tmp60 - _tmp61;
    _res_D_b(2, 2) = _tmp33 + _tmp39 * _tmp62 + _tmp59;
    _res_D_b(2, 3) = 0;
    _res_D_b(2, 4) = 0;
    _res_D_b(2, 5) = 0;
    _res_D_b(3, 0) = 0;
    _res_D_b(3, 1) = 0;
    _res_D_b(3, 2) = 0;
    _res_D_b(3, 3) = _tmp15;
    _res_D_b(3, 4) = _tmp12;
    _res_D_b(3, 5) = _tmp8;
    _res_D_b(4, 0) = 0;
    _res_D_b(4, 1) = 0;
    _res_D_b(4, 2) = 0;
    _res_D_b(4, 3) = _tmp21;
    _res_D_b(4, 4) = _tmp20;
    _res_D_b(4, 5) = _tmp18;
    _res_D_b(5, 0) = 0;
    _res_D_b(5, 1) = 0;
    _res_D_b(5, 2) = 0;
    _res_D_b(5, 3) = _tmp24;
    _res_D_b(5, 4) = _tmp23;
    _res_D_b(5, 5) = _tmp22;
  }

  return sym::Pose3<Scalar>(_res);
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
