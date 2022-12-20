#ifndef PERISHABLE_PRODUCT_HPP
#define PERISHABLE_PRODUCT_HPP

#include "Product.hpp"
#include "Date.hpp"

/**
 * An abstract class for products with an experation date, e.g. milk and eggs.
 * 
 * This class definition can't be changed as it will not submitted with the
 * rest of the files in the assignment. A copy of this file exists in
 * CodeGrade.
 */
class PerishableProduct : public Product
{
    Date expirationDate;

protected:

    std::string GetDescription() const override;

public:

    PerishableProduct(float price, const Date& expirationDate);
    ~PerishableProduct() override = default; // No need to define this manually.

    const Date& GetExpirationDate() const;
};

#endif