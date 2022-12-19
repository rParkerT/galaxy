#ifndef TYPE_GALAXY_H_
#define TYPE_GALAXY_H_

#include "galaxy.h"
#include <concepts>

namespace galaxy {

/// Classification of galaxies based on type, early or late type galaxies

/// Defining concept IsGalaxy that derived class must have a Galaxy base
/// class
template <typename T> concept IsGalaxy = std::is_base_of<Galaxy, T>::value;

/**
 * Type class, that is derived from Galaxy base class and that classifies
 * galaxies based on type.
 */
template <IsGalaxy T> class Type : public T {
private:
  /// boolean parameter that defines if galaxy has star formation ongoing
  bool star_forming_ongoing{true};
  /// boolean parameter that defines if galaxy is rich in gas
  bool is_gas_rich{true};

public:
  /**
   * Constructor of Type
   *
   * @param star_forming true if galaxy has star formation ongoing
   * @param gas_rich true if galaxy is rich in gas
   * @param args parameters forwarded to base class
   */
  template <typename... Args>
  explicit Type(const bool star_forming, const bool gas_rich, Args... args)
      : T(std::forward<Args>(args)...), star_forming_ongoing{star_forming},
        is_gas_rich{gas_rich} {}

  /// Default destructor
  ~Type() = default;

  /**
   * Implementation of info galaxy type function. If start formation is ongoing
   * and galaxy is rich in gas, it' a late-type galaxy, if galaxy is not rich in
   * gas, nor there is a star formation ongoing, it's an early-type, else it's
   * not conclusive.
   *
   * @return info about galaxy type
   */
  std::string info() const override {
    std::ostringstream oss;
    if (star_forming_ongoing && is_gas_rich) {
      oss << T::info() << " and is a Late-Type galaxy";
    } else if (!star_forming_ongoing && !is_gas_rich) {
      oss << T::info() << " and is an Early-Type galaxy";
    } else {
      oss << T::info()
          << " can not deduce if it is an Early- or a Late-Type galaxy";
    }
    return oss.str();
  }
};

} // namespace galaxy

#endif /* TYPE_GALAXY_H_ */
