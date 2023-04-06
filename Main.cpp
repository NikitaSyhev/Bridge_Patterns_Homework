
#include <iostream>

class IStock {
public:
	virtual const void treateCargo() = 0;
	virtual ~IStock() {};
};

class Stock : public IStock {
public:
	const void treateCargo() override {
		std::cout << "For Stock we used a ";
	};
};

class ShipPort : public IStock {
public:
	const void treateCargo() override {
		std::cout << "For ShipPort we used a ";
	};
};


class IUnloadingGoods {
public:
	IUnloadingGoods(IStock * stock) : _stock(stock){}
	void setStock(IStock* stock) {
		_stock = stock;
	}

	virtual void unload() = 0;
	virtual ~IUnloadingGoods() {};
protected:
	IStock* _stock;

};

class ShipUnloading : public IUnloadingGoods {
public:
	ShipUnloading(IStock * stock) : IUnloadingGoods(stock) {}
	void unload() override {
		_stock->treateCargo();
		std::cout << "Ship." << std::endl;
	}
};


class VehicleUnloading : public IUnloadingGoods {
public:
	VehicleUnloading(IStock* stock) : IUnloadingGoods(stock) {}
	void unload() override {
		_stock->treateCargo();
		std::cout << "Vehicle." << std::endl;
	}
};






int main() {
	setlocale(LC_ALL, "Russian");
	
	IUnloadingGoods* unloading = new ShipUnloading(new ShipPort());

	unloading->unload();
	//unloading->setStock(new ShipPort);

	//unloading->unload();
	//unloading = new ShipUnloading(new ShipPort);
	//unloading->unload();


















	return 0;
}