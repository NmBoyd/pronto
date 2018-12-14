#pragma once
#include "pronto_estimator_core/definitions.hpp"
#include "pronto_estimator_core/sensing_module.hpp"

namespace MavStateEst {

struct GPSConfig{
    double r_gps_xy;
    double r_gps_z;
};

class GPSModule : public SensingModule<GPSMeasurement> {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
public:
    GPSModule(const GPSConfig& cfg);
    RBISUpdateInterface* processMessage(const GPSMeasurement *msg,
                                        MavStateEstimator *est) override;
    bool processMessageInit(const GPSMeasurement *msg,
                            const std::map<std::string, bool> &sensor_initialized,
                            const RBIS &default_state,
                            const RBIM &default_cov,
                            RBIS &init_state,
                            RBIM &init_cov) override;


protected:
    Eigen::Matrix3d cov_xyz;


};

} // namespace MavStateEst
