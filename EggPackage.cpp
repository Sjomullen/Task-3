/**
 * Only the following includes are allowed in this file.
 * 
 * Other includes may be used during development, but are expected to be
 * removed (not commented out) when the file is turned in to CodeGrade.
 */
#include "EggPackage.hpp"

/**
 * A virtual function that all sub classes of 'Product' overrides. This
 * function will return a formated string containing all information
 * prodided by this level in the product-class-hierarchy, plus the
 * information provided by the class's direct base class by calling this
 * function from the direct base class.
 * 
 * EggPackage knows the number of eggs in the product object, and has
 * 'PerishableProduct' as a direct base class, so the GetDescription() of
 * this level should create a formated string including the name of the
 * product, the number of eggs in the package + the string retrieved from
 * PerishableProduct::GetDescription().
 * 
 * @returns A string containing the product information stored in this
 *          hierarchy level (number of eggs) plus the information from all
 *          levels above in the hierachy.
 * 
 *           New information from this level
 *           |
 *           v-------------v
 * Example: "Eggs, 12-pack, expires 24-12-2022, 35.000000 kr"
 *                          ^------------------------------^
 *                          |
 *                     Information from PerishableProduct::GetDescription()
 */
std::string EggPackage::GetDescription() const
{
    return std::string("Eggs" + std::to_string(this->eggQuantity) + "-pack" + PerishableProduct::GetDescription());
}


/**
 * Constructs a new EggPackage object with a given price, expiration date,
 * and number of eggs in the package.
 * 
 * Calls the constructor of the direct base class.      
 */
EggPackage::EggPackage(float price, const Date& expirationDate, int eggQuantity)
    : PerishableProduct(price, expirationDate)
{
    this->eggQuantity = eggQuantity;
}

/**
 * Getter for the member eggQuantity.
 * 
 * @returns The number of eggs in the product object.
 */
int EggPackage::GetEggQuantity() const
{
    return this->eggQuantity;
}

/**
 * Getter for the volume required to store the physical product.
 * 
 * The required storage volume of an egg package product can be calculated
 * using the following formula:
 * 
 *     0.000125f * eggQuantity
 * 
 * @returns The volume required to store the physical egg package product.
 */
float EggPackage::GetStorageVolume() const
{
    return this->eggQuantity * 0.000125f;
}

/**
 * Constructs and returns a pointer to an exact clone of the product object,
 * allocated on the heap.
 * 
 * This pure virtual function has to be overriden by the derived class in
 * order to construct the new object using the derived class's copy
 * constructor.
 * 
 * The product do not have any responsibility of the newly constructed product
 * after this function returns.
 * 
 * @returns A pointer to a dynamically allocated object of the same type as
 *          the product.
 */
Product* EggPackage::Clone() const
{
    return new EggPackage(Product::GetPrice(), PerishableProduct::GetExpirationDate(), EggPackage::GetEggQuantity());
}
