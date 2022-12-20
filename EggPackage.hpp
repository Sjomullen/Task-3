#ifndef EGG_PACKAGE_HPP
#define EGG_PACKAGE_HPP

#include "PerishableProduct.hpp"

/**
 * Eggs is a perishable product, stored a package, that are defined by three
 * values:
 *     - A price
 *     - An expiration date
 *     - The number of eggs in the package.
 * 
 * The required storage volume of an egg package product can be calculated
 * using the following formula:
 * 
 *     0.000125f * eggQuantity
 * 
 * This class definition can't be changed as it will not submitted with the
 * rest of the files in the assignment. A copy of this file exists in
 * CodeGrade.
 */
class EggPackage : public PerishableProduct
{
    int eggQuantity;

protected:

    std::string GetDescription() const override;

public:

    EggPackage(float price, const Date& expirationDate, int eggQuantity);
    ~EggPackage() override = default; // No need to define this manually.

    int GetEggQuantity() const;
    float GetStorageVolume() const override;

    Product* Clone() const override;
};

#endif
