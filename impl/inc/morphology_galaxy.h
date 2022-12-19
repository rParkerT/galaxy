#ifndef MORPHOLOGY_GALAXY_H_
#define MORPHOLOGY_GALAXY_H_

#include "galaxy.h"
#include <cmath>

namespace galaxy {

/// Classification of galaxies based on morphology, where galaxies are divided
/// into three different gorups - elliptical, spiral and irregular

/**
 * Elliptical class, that describes elliptical galaxy.
 */
class Elliptical : public Galaxy {
private:
  /// semi major axes of elliptical galaxy
  int semi_major_axes{0};
  /// semi minor axes of elliptical galaxy
  int semi_minor_axes{0};
  /// ellipticity of elliptical galaxy
  int ellipticity{0};

  /**
   * Function that calculates ellipticity of elliptical galaxy, that is equal as
   * one minus ratio of the semi major to the semi minor axes of the galaxy,
   * multiplied by 10 and rounded to the nearest integer. From the known
   * observations, elliptical galaxies have ellipticity from 0 (E0 most
   * spherical) to 7 (E7 most elongated). Ellipticity is set to -1, if semi
   * major axes is 0.
   *
   * @return ellipticity of the galaxy
   */
  int set_ellipticity() {
    if (semi_major_axes != 0) {
      ellipticity = round(
          10 * (1.0 - static_cast<float>(semi_minor_axes) / semi_major_axes));
    } else {
      ellipticity = -1;
    }
    return ellipticity;
  }

public:
  /**
   * Constructor of Elliptical, that sets ellipticity from galaxy  parameters
   *
   * @param a semi major axes
   * @param b semi minor axes
   */
  explicit Elliptical(const int a = 0, const int b = 0)
      : semi_major_axes{a}, semi_minor_axes{b} {
    set_ellipticity();
  }

  /// Default destructor
  ~Elliptical() = default;

  /**
   * Implementation of info elliptical galaxy function.
   *
   * @return info about elliptical galaxy
   */
  std::string info() const override {
    std::ostringstream oss;
    if (ellipticity != -1) {
      oss << "an eliptical galaxy with ellipticity of " << ellipticity;
    } else {
      oss << "an eliptical galaxy with undefined ellipticity";
    }
    return oss.str();
  }
};

/**
 * Spiral class, that describes spiral galaxy.
 */
class Spiral : public Galaxy {
private:
  /// boolean parameter that defines if spiral galaxy has a bar or not
  bool is_barred{false};

public:
  /**
   * Constructor of Spiral
   *
   * @param barred true if spiral galaxy has a bar in it's core
   */
  explicit Spiral(const bool barred) : is_barred{barred} {}

  /// Default destructor
  ~Spiral() = default;

  /**
   * Implementation of info spiral galaxy function.
   *
   * @return info about spiral galaxy
   */
  std::string info() const override {
    std::ostringstream oss;
    if (is_barred) {
      oss << "a barred spiral galaxy";
    } else {
      oss << "an unbarred spiral galaxy";
    }
    return oss.str();
  }
};

/**
 * Irregular class, that describes irregular galaxy.
 */
class Irregular : public Galaxy {
private:
  /// boolean parameter that defines if irregular galaxy has some structure, in
  /// which case the galaxy is defined as type I, els it is defined as type II
  bool has_some_structure{false};

public:
  /**
   * Constructor of Irregular
   *
   * @param structured true if irregular galaxy has some structure
   */
  explicit Irregular(const bool structured) : has_some_structure{structured} {}

  /// Default destructor
  ~Irregular() = default;

  /**
   * Implementation of info irregular galaxy function.
   *
   * @return info about irregular galaxy
   */
  std::string info() const override {
    std::ostringstream oss;
    if (has_some_structure) {
      oss << "an irregular galaxy type I";
    } else {
      oss << "an irregular galaxy type II";
    }
    return oss.str();
  }
};

} // namespace galaxy

#endif /* MORPHOLOGY_GALAXY_H_ */
