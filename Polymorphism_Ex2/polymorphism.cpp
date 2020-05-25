#include <assert.h>
#include <cmath>

// TODO: Define PI
//Don't put semicolon after number
#define PI 3.1459

// TODO: Declare abstract class VehicleModel
  // TODO: Declare virtual function Move()

class VehicleModel {
    virtual void Move(double v, double phi) = 0;
};

// TODO: Derive class ParticleModel from VehicleModel
  // TODO: Override the Move() function
  // TODO: Define x, y, and theta

class ParticleModel : public VehicleModel {
    public: 

        void Move(double v, double phi) override {
            theta += phi;
            x += v * cos(theta);
            y += v * cos(theta);
        }
        
        double x = 0;
        double y = 0;
        double theta = 0;
};

// TODO: Derive class BicycleModel from ParticleModel
  // TODO: Override the Move() function
  // TODO: Define L
class BicycleModel : public ParticleModel {

    public:

        void Move(double v, double phi) override {
            theta += v / L * tan(phi);
            x += v * cos(theta);
            y += v * cos(theta);
        }

        double L = 1;
};

// TODO: Pass the tests
int main() {
  // Test function overriding
  ParticleModel particle;
  BicycleModel bicycle;
  particle.Move(10, PI / 9);
  bicycle.Move(10, PI / 9);
  assert(particle.x != bicycle.x);
  assert(particle.y != bicycle.y);
  assert(particle.theta != bicycle.theta);
}
