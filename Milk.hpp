#ifndef MILK_HPP
#define MILK_HPP

#include "PerishableProduct.hpp"

/**
 * Milk is a perishable product that are defined by three values:
 *     - A price
 *     - An expiration date
 *     - The amount of liquid, described in liters.
 * 
 * The required storage volume of a milk product is defined by it's volume, and
 * can be calculated using the following formula:
 * 
 *     liters / 1000.f
 * 
 * This class definition can't be changed as it will not submitted with the
 * rest of the files in the assignment. A copy of this file exists in
 * CodeGrade.
 */
class Milk : public PerishableProduct
{
    float liters;

protected:

    std::string GetDescription() const override;

public:

    Milk(float price, const Date& expirationDate, float liters);
    ~Milk() override = default; // No need to define this manually.

    float GetLiters() const;
    float GetStorageVolume() const override;

    Product* Clone() const override;
};

#endif
