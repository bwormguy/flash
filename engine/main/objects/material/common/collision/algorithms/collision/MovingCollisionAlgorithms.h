//
// Created by roman on 03.10.2020.
//

#ifndef FLASH_MOVINGCOLLISIONALGORITHMS_H
#define FLASH_MOVINGCOLLISIONALGORITHMS_H

#include "../../../../../auxiliary/components/elementary/point/Point.h"
#include "../../../MaterialObject.h"

namespace Material {

    /**
     * Function contains moving collision algorithm. Algorithm checks main and processed objects collision, in view of main object's current speed.
     * After collision, the main object moves as close as possible to the processed object.
     *
     * @param object Main object.
     * @param processed Processed object.
     * @return Was the collision?
    */
    bool movingAbscissaCollision(Material::MaterialObject &object, const Material::MaterialObject &processed, float step) noexcept;

    /**
     * Function contains moving collision algorithm. Algorithm checks main and processed objects collision, in view of main object's current speed.
     * After collision, the main object moves as close as possible to the processed object.
     *
     * @param object Main object.
     * @param processed Processed object.
     * @return Was the collision?
     */
    bool movingOrdinateCollision(Material::MaterialObject &object, const Material::MaterialObject &processed, float step) noexcept;

    /**
     * Function contains moving collision algorithm. Algorithm checks main and processed objects collision, in view of main object's current speed.
     * After collision, the main object moves as close as possible to the processed object.
     *
     * @param object Main object.
     * @param objectMinCoordinates Object's min coordinates. Uses for time optimization.
     * @param objectMaxCoordinates Object's max coordinates. Uses for time optimization.
     * @param processed Processed object.
     * @return Was the collision?
    */
    bool movingAbscissaCollision(const Components::Point &objectMinCoordinates, const Components::Point &objectMaxCoordinates,
                                 Material::MaterialObject &object, const Material::MaterialObject &processed, float step) noexcept;

    /**
     * Function contains moving collision algorithm. Algorithm checks main and processed objects collision, in view of main object's current speed.
     * After collision, the main object moves as close as possible to the processed object.
     *
     * @param object Main object.
     * @param objectMinCoordinates Object's min coordinates. Uses for time optimization.
     * @param objectMaxCoordinates Object's max coordinates. Uses for time optimization.
     * @param processed Processed object.
     * @return Was the collision?
     */
    bool movingOrdinateCollision(const Components::Point &objectMinCoordinates, const Components::Point &objectMaxCoordinates,
                                 Material::MaterialObject &object, const Material::MaterialObject &processed, float step) noexcept;
}

#endif //FLASH_MOVINGCOLLISIONALGORITHMS_H
