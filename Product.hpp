#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

/**
 * An abstract base class used as an interface for all derived products.
 * 
 * This class definition can't be changed as it will not submitted with
 * the rest of the files in the assignment. A copy of this file exists
 * in CodeGrade.
 */
class Product
{
    float price;

protected:

    virtual std::string GetDescription() const;

public:

    Product(float price);
    virtual ~Product() = default; // No need to define this manually.

    float GetPrice() const;
    std::string GetProductDescription() const;

    /**
     * Getter for the volume required to store the physical product.
     * 
     * The required storage volume is only known by the derived product itself.
     * For example, the required space to store milk may depend the amount of
     * liquid in liters the product have, and an egg package may depend on the
     * amount of eggs in the package. This function is therefore pure virtual,
     * making a derived class to override it.
     * 
     * @returns The volume required to store the physical product, defined by
     *          the derived class.
     */
    virtual float GetStorageVolume() const = 0;

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
    virtual Product* Clone() const = 0;
};

#endif
