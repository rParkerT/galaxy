#include "active_galaxy.h"
#include "galaxy.h"
#include "morphology_galaxy.h"
#include "type_galaxy.h"

int main() {
  // HerculesA is a elliptical, galaxy, that has no star formation on-going   and is not rich in gas
  galaxy::Type<galaxy::Elliptical> HerculesA{false, false, 10, 7};
  std::cout << "HerculesA is a " << HerculesA.info() << std::endl;

  // Pinwheel is a spiral galaxy, that has no bar, has star formation on-going and is rich in gas
  galaxy::Type<galaxy::Spiral> Pinwheel{true, true, false};
  std::cout << "Pinwheel is a " << Pinwheel.info() << std::endl;

  // Small Magellanic Cloud is a irregular galaxy that has some structure, has star formation on-going and is rich in gas
  galaxy::Type<galaxy::Irregular> SmallMagellanicCloud{true, true, true};
  std::cout << "Small Magellanic Cloud is a " << SmallMagellanicCloud.info()
            << std::endl;

  // NGC 3227 is a active galaxy, with luminosity of 0.23*10^44 erg s^-1 , it is a spiral galaxy, that has no bar, has star formation on-going and is rich in gas
  galaxy::ActiveGalaxy<galaxy::Type<galaxy::Spiral>> NGC3227{0.23, true, true, false};
  std::cout << "NGC 3227 is a " << NGC3227.info() << std::endl;

  return 0;
}
