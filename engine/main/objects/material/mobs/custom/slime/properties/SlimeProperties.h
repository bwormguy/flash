//
// Created by roman on 22.11.2020.
//

#ifndef FLASH_SLIMEPROPERTIES_H
#define FLASH_SLIMEPROPERTIES_H

#include "../../../../common/properties/ParamsTypes.h"

namespace Mobs {

    /**
     * @brief Struct contains slime numeric properties.
     */
    struct SlimeProperties {
        SlimeProperties(
                Material::FRAC_PARAM moveSpeed,
                Material::FRAC_PARAM jumpSpeed,
                Material::UINT_PARAM jumpRateCoefficient,
                Material::FRAC_PARAM punchPower,
                Material::FRAC_PARAM punchDamage,
                Material::FRAC_PARAM elasticCoefficient,
                Material::FRAC_PARAM frictionCoefficient,
                Material::UINT_PARAM minSplitSize,
                Material::FRAC_PARAM splittingCoefficient,
                Material::UINT_PARAM splitSlimesNumber,
                const Material::PAIR<Material::FRAC_PARAM> &splitPower
        ) : moveSpeed(moveSpeed),
            jumpSpeed(jumpSpeed),
            jumpRateCoefficient(jumpRateCoefficient),
            punchPower(punchPower),
            punchDamage(punchDamage),
            elasticCoefficient(elasticCoefficient),
            frictionCoefficient(frictionCoefficient),
            minSplitSize(minSplitSize),
            splitCoefficient(splittingCoefficient),
            splitSlimesNumber(splitSlimesNumber),
            splitPower(splitPower) {}

        /**
        * @brief The parameter of speed obtained when moving horizontally by jump.
        */
        Material::FRAC_PARAM moveSpeed;

        /**
         * @brief The parameter of speed obtained horizontally at each jump.
         */
        Material::FRAC_PARAM jumpSpeed;

        /**
         * @brief The value determines the frequency of slime's jumps. The higher the value is, the jumps are less frequent.
         */
        Material::UINT_PARAM jumpRateCoefficient;

        /**
         * @brief Parameter sets slime's punch power.
         */
        Material::FRAC_PARAM punchPower;

        /**
         * @brief Parameter sets slime's punch damage.
         */
        Material::FRAC_PARAM punchDamage;

        /**
         * @brief This coefficient uses in calculations after players jump on slime.
         */
        Material::FRAC_PARAM elasticCoefficient;

        /**
         * @brief This coefficient uses in calculations during players moving on slime.
         */
        Material::FRAC_PARAM frictionCoefficient;

        /**
         * @brief The minimum size to which the slime can be divided. Slime could not have any side less than 10 px.
         */
        Material::UINT_PARAM minSplitSize;

        /**
         * @brief The parameter shows how many times the split slimes will be smaller than the original one.
         */
        Material::FRAC_PARAM splitCoefficient;

        /**
         * @brief The parameter indicates the number of slimes which can be generated by a slime.
         */
        Material::UINT_PARAM splitSlimesNumber;

        /**
         * @brief The parameter sets the value which uses in calculating initial acceleration of split slimes.
         */
        Material::PAIR<Material::FRAC_PARAM> splitPower;
    };
}

#endif //FLASH_SLIMEPROPERTIES_H
