#ifndef ACTIVE_GALAXY_H_
#define ACTIVE_GALAXY_H_

#include "galaxy.h"
#include <concepts>

namespace galaxy {

/// Classification of galaxies based on activity of galaxy

/// Defining concept IsStillGalaxy that derived class must have a Galaxy base
/// class
template <typename T> concept IsStillGalaxy = std::is_base_of<Galaxy, T>::value;

/**
 * ActiveGalaxy class, that is derived from Galaxy base class and that
 * classifies galaxies based on activity.
 */
template <IsStillGalaxy T> class ActiveGalaxy : public T {
private:
  /// luminosity of galaxy that is usually measured in radio frequency
  /// (luminosity*10^44 erg s^-1)
  float luminosity{0.0};

public:
  /**
   * Constructor of ActiveGalaxy
   *
   * @param luminosity of galaxy
   * @param args parameters forwarded to base class
   */
  template <typename... Args>
  explicit ActiveGalaxy(const float luminosity, Args... args)
      : T(std::forward<Args>(args)...), luminosity{luminosity} {}

  /// Default destructor
  ~ActiveGalaxy() = default;

  /**
   * Implementation of info active galaxy function.
   *
   * @return info about galaxy type
   */
  std::string info() const override {
    std::ostringstream oss;
    oss << T::info() << " with luminosity " << luminosity << "*10^44 erg s^-1";
    return oss.str();
  }
};

} // namespace galaxy

#endif /* ACTIVE_GALAXY_H_ */
