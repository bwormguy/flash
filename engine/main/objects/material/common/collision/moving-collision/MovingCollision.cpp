//
// Created by roman on 19.09.2020.
//

#include "MovingCollision.h"

Material::MovingCollision::MovingCollision(float analysisStepX, float analysisStepY)
        : ANALYSIS_STEP_X(analysisStepX), ANALYSIS_STEP_Y(analysisStepY) {}

bool Material::MovingCollision::abscissaMoveAble(Material::MaterialObject *object, Material::MaterialObject *processed) const noexcept {
    if (object->getSpeed().xSpeed == 0) return false;
    if (object == processed) return false;

    return movingAbscissaCollision(*object, *processed, ANALYSIS_STEP_Y);
}

bool Material::MovingCollision::ordinateMoveAble(Material::MaterialObject *object, Material::MaterialObject *processed) const noexcept {
    if (object->getSpeed().ySpeed == 0) return false;
    if (object == processed) return false;

    return movingOrdinateCollision(*object, *processed, ANALYSIS_STEP_X);
}

std::pair<float, float> Material::MovingCollision::getAnalysisStep() const noexcept {
    return std::make_pair(ANALYSIS_STEP_X, ANALYSIS_STEP_Y);
}

float Material::MovingCollision::getAnalysisStepX() const noexcept {
    return ANALYSIS_STEP_X;
}

float Material::MovingCollision::getAnalysisStepY() const noexcept {
    return ANALYSIS_STEP_Y;
}
