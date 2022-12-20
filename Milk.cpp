/**
 * Only the following includes are allowed in this file.
 * 
 * Other includes may be used during development, but are expected to be
 * removed (not commented out) when the file is turned in to CodeGrade.
 */
#include "Milk.hpp"

/**
 * A virtual function that all sub classes of 'Product' overrides. This
 * function will return a formated string containing all information
 * provided by this level in the product-class-hierarchy, plus the
 * information provided by the class's direct base class by calling this
 * function from the direct base class.
 * 
 * Milk knows the amount of liters in the product object, and has
 * 'PerishableProduct' as a direct base class, so the GetDescription() of
 * this level should create a formated string including the name of the
 * product, the amount milk described in liters + the string retrieved from
 * PerishableProduct::GetDescription().
 * 
 * @returns A string containing the product information stored in this
 *          hierarchy level (liters) plus the information from all levels
 *          above in the hierachy.
 * 
 *           New information from this level
 *           |
 *           v-----------------------v
 * Example: "Milk, 500.000000 liters, expires 27-12-2022, 24.000000 kr"
 *                                    ^------------------------------^
 *                                    |
 *                     Information from PerishableProduct::GetDescription()
 */
std::string Milk::GetDescription() const
{
    return std::string();
}


/**
 * Constructs a new Milk object with a given price, expiration date, and
 * amount of milk described in liters.
 * 
 * Calls the constructor of the direct base class.      
 */
Milk::Milk(float price, const Date& expirationDate, float liters)
    : PerishableProduct(price, expirationDate)
{
    this->liters = liters;

    return liters;
}

/**
 * Getter for the member liters.
 * 
 * @returns The amount of milk in the product described in liters.
 */
float Milk::GetLiters() const
{
    return this->liters;
}

/**
 * Getter for the volume required to store the physical product.
 * 
 * The required storage volume of a milk product is defined by it's volume, and
 * can be calculated using the following formula:
 * 
 *     liters / 1000.f
 * 
 * @returns The volume required to store the physical milk product.
 */
float Milk::GetStorageVolume() const
{
    return float();
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
Product* Milk::Clone() const
{
    return new Milk(Product::GetPrice(), PerishableProduct::GetExpirationDate(),;
}
