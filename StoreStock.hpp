/**
 * Only the following includes are allowed in this file.
 * 
 * Other includes may be used during development, but are expected to be
 * removed (not commented out) when the file is turned in to CodeGrade.
 */
#include <vector>
#include "Product.hpp"

/**
 * A container class which offers support of adding, managing and retrieving
 * objects of classes derived from Product.
 * 
 * All private members has to stay private. All public members has to stay
 * public.
 * 
 * It is allowed to add more help functions to this class, but only if they
 * are private.
 */
class StoreStock
{
	std::vector<Product*> products;

public:

	StoreStock();
	StoreStock(const StoreStock& other);
	~StoreStock();
	StoreStock& operator=(const StoreStock& other);

	int GetSize() const;
	float GetTotalCost() const;

	bool AddProduct(Product* product);
	bool ReleaseProduct(Product* product);

	float GetRequiredStorageVolume() const;
	template <typename T> T* GetCheapest() const;
	template <typename T> int GetNumberOf() const;

	/**
	 * begin() and end() allows for 'ranged-based for':
	 * 
	 *     StoreStock stock;
	 *     for (auto product : stock) // <-- ranged-based for
	 * 	       product->GetDescription();
	 * 
	 * Let these two be 'as is'. :)
	 */
	inline std::vector<Product*>::iterator begin() { return products.begin(); }
	inline std::vector<Product*>::iterator end() { return products.end(); }
};

/**
 * Returns a casted pointer to the cheapest product of a requested type.
 * 
 * Iterates all existing products to find the ones that are objects of the
 * requested type, and from these finds the product with the lowest price.
 * 
 * Note: use dynamic_cast.
 * 
 * @returns A casted pointer to the cheapest product of the requested type.
 * 					If there are more than one product with the same, lowest price,
 * 					any product of these may be returned. If no products of the
 * 					requested type exists, this returns nullptr.
 */
template <typename T>
T* StoreStock::GetCheapest() const
{
	return nullptr;
}

/**
 * Note: use dynamic_cast.
 * 
 * @returns The number of existing products of a requested type.
 */
template <typename T>
int StoreStock::GetNumberOf() const
{
	return int();
}
