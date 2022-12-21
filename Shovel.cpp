/**
 * Only the following includes are allowed in this file.
 * 
 * Other includes may be used during development, but are expected to be
 * removed (not commented out) when the file is turned in to CodeGrade.
 */
#include "Shovel.hpp"

/**
 * A virtual function that all sub classes of 'Product' overrides. This
 * function will return a formated string containing all information
 * prodided by this level in the product-class-hierarchy, plus the
 * information provided by the class's direct base class by calling this
 * function from the direct base class.
 * 
 * Shovel knows the blade width of the product object, and has 'Product' as
 * a direct base class, so the GetDescription() of this level should create
 * a formated string of the blade width + the string retrieved from
 * Product::GetDescription(). 
 * 
 * @returns A string containing the product information stored in this
 *          hierarchy level (blade width) plus the information from
 *          all levels above in the hierachy.
 * 
 *           New information from this level
 *           |
 *           v-------------------------------v
 * Example: "Shovel, 30.000000 m blade width, 249.000000 kr"
 *                                            ^-----------^
 *                                            |
 *                               Information from Product::GetDescription()
 */
std::string Shovel::GetDescription() const
{
    return std::string("Shovel" + std::to_string(this->bladeWidth) + "m blade width, " + Product::GetDescription());
}

/**
 * Constructs a new Shovel object with a given price and blade width
 * described in meters.
 * 
 * Calls the constructor of the direct base class.      
 */
Shovel::Shovel(float price, float bladeWidth) : Product(price)
{
    this->bladeWidth = bladeWidth;
}

/**
 * Getter for bladeWidth.
 * 
 * @returns A const reference of the product's blade width member.
 */
float Shovel::GetBladeWidth() const
{
    return this->bladeWidth;
}

/**
 * Getter for the volume required to store the physical product.
 * 
 * The required storage volume of a shovel is defined as a block, and can be 
 * calculated using the following formula:
 * 
 *     0.30f * 1.50f * bladeWidth
 * 
 * @returns The volume required to store the physical shovel.
 * 
 * Note: the shovel is stored in a box. :)
 */
float Shovel::GetStorageVolume() const
{
    return GetBladeWidth() * 0.30f * 1.50f;
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
Product* Shovel::Clone() const
{
    return new Shovel(Product::GetPrice(), Shovel::GetBladeWidth());
}
