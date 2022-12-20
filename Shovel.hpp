#ifndef SHOVEL_HPP
#define SHOVEL_HPP

#include "Product.hpp"

/**
 * A shovel is a product that are defined by two values:
 *     - A price
 *     - With width of the shovel's blade, described in meters
 * 
 * The required storage volume of a shovel is defined as a block, and can be 
 * calculated using the following formula:
 * 
 *     0.30f * 1.50f * bladeWidth
 * 
 * This class definition can't be changed as it will not submitted with the
 * rest of the files in the assignment. A copy of this file exists in
 * CodeGrade.
 */
class Shovel : public Product
{
    float bladeWidth;

protected:

    std::string GetDescription() const override;

public:

    Shovel(float price, float bladeWidth);
    ~Shovel() override = default; // No need to define this manually.

    float GetBladeWidth() const;
    float GetStorageVolume() const override;

    Product* Clone() const override;
};

#endif
