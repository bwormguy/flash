//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_POINT_H
#define FLASH_POINT_H

namespace Components {

    /**
     * @brief The structure is used to represent a point on the coordinate plane.
     * @namespace Components
     *
     * This struct is the base component.
    */
    struct Point {
        /**
         * @brief Inits "x" and "y".
         * @param x coordinate.
         * @param y coordinate.
         */
        Point(float x, float y);

        /**
         * @brief Inits "x" and "y" by zero.
         */
        Point() : x(), y() {}

        float x;
        float y;
    };

    /**
     * @brief Method overloads operator "+".
     * @param left Left operand.
     * @param right Right operand.
     */
    Point operator+(const Point &left, const Point &right) noexcept;

    /**
     * @brief Method overloads operator "-".
     * @param left Left operand.
     * @param right Right operand.
     */
    Point operator-(const Point &left, const Point &right) noexcept;

    /**
     * @brief Method overloads operator "+=".
     * @param left Left operand.
     * @param right Right operand.
     */
    Point &operator+=(Point &left, const Point &right) noexcept;

    /**
     * @brief Method overloads operator "-=".
     * @param left Left operand.
     * @param right Right operand.
     */
    Point &operator-=(Point &left, const Point &right) noexcept;

    /**
     * @brief Method overloads comparison operator.
     * @param left Left operand.
     * @param right Compared object.
     */
    bool operator==(const Point &left, const Point &right) noexcept;

    /**
     * @brief Method overloads comparison operator.
     * @param left Left operand.
     * @param right Compared object.
     */
    bool operator!=(const Point &left, const Point &right) noexcept;
}

#endif //FLASH_POINT_H
