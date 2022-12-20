/**
 * Only the following includes are allowed in this file.
 * 
 * Other includes may be used during development, but are expected to be
 * removed (not commented out) when the file is turned in to CodeGrade.
 */ 
#include "PerishableProduct.hpp"

/**
 * A virtual function that all sub classes of 'Product' overrides. This
 * function will return a formated string containing all information
 * prodided by this level in the product-class-hierarchy, plus the
 * information provided by the class's direct base class by calling this
 * function from the direct base class.
 * 
 * PerishableProduct knows the expiration date of the product object, and
 * has 'Product' as a direct base class, so the GetDescription() of this
 * level should create a formated string of the expiration date + the
 * string retrieved from Product::GetDescription(). 
 * 
 * @returns A string containing the product information stored in this
 *          hierarchy level (expiration date) plus the information from
 *          all levels above in the hierachy.
 * 
 *           New information from this level
 *           |
 *           v------------------v
 * Example: "expires 24-12-2022, 150.0000 kr"
 *                               ^---------^
 *                               |
 *                               Information from Product::GetDescription()
 */
std::string PerishableProduct::GetDescription() const
{
    return std::string();
}

/**
 * Constructs a new PerishableProduct object with a given price and
 * expiration date.
 * 
 * Calls the constructor of the direct base class.      
 */
PerishableProduct::PerishableProduct(float price, const Date& expirationDate)
    : Product(float())
{

}

/**
 * Getter for expirationDate.
 * 
 * @returns A const reference of the product's expiration date member.
 */
const Date& PerishableProduct::GetExpirationDate() const
{
    return this->expirationDate; // This one is for free. :)
}
