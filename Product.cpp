/**
 * Only the following includes are allowed in this file.
 * 
 * Other includes may be used during development, but are expected to be
 * removed (not commented out) when the file is turned in to CodeGrade.
 */ 
#include "Product.hpp"

/**
 * A virtual function that all sub classes overrides. This function will
 * return a formated string containing all information prodided by this
 * level in the product-class-hierarchy, plus the information provided
 * by the class's direct base class by calling this function from the
 * direct base class.
 * 
 * As 'Product' is the top base class in this hierarchy,
 * it can't call any other GetDescription() functions and thus only returns
 * the information stored in this level as a formated string.
 * 
 * @returns A string containing the product information stored in this
 *          hierarchy level, containing the price and the currency "kr".
 * 
 * Example: "150.0000 kr"
 */
std::string Product::GetDescription() const
{
    return std::string(std::to_string(this->price) + "kr");
}

/**
 * Constructs a new Product object with a given price.           
 */
Product::Product(float price)
{
    this->price = price;
}

/**
 * Getter for the member price.
 * 
 * @returns The price value of the product.
 */
float Product::GetPrice() const
{

    return this->price;
}

/**
 * Getter for the full pruduct description.
 * 
 * This function is a public interface for retrieving a FULL description of
 * a product object, including information from all levels in the class
 * hierarchy.
 * 
 * The full description is retrieved by internally calling the virtual
 * GetDescription() function, which will call the products own overriden
 * version of GetDescription().
 * 
 * @returns The full description of the product.
 * 
 * Example: "Eggs, 12-pack, expires 24-12-2022, 35.000000 kr"
 *                                              ^
 *                                 The description from the base
 *                                 class 'Product' starts here.
 */
std::string Product::GetProductDescription() const
{
    return std::string(GetDescription());
}
