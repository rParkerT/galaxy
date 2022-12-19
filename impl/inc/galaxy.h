#ifndef GALAXY_H_
#define GALAXY_H_

#include <iostream>
#include <sstream>
#include <string>

namespace galaxy {

/**
 * Galaxy interface class.
 */
class Galaxy {
public:
  /// Default constructor
  Galaxy() = default;
  /// Default destructor
  virtual ~Galaxy() = default;

  /**
   * Pure virtual info function
   */
  virtual std::string info() const = 0;
};

} // namespace galaxy

#endif /* GALAXY_H_ */
