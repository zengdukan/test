
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <string>

struct Stock {
    std::string _name;
    Stock(const std::string& name): _name(name) {}

    const std::string& name() {
        return _name;
    }
};

struct StockPool: public std::enable_shared_from_this<StockPool> {
    std::shared_ptr<Stock> get(const std::string& name) {
        std::shared_ptr<Stock> stock;
        std::lock_guard<std::mutex> lock(_mutex);
        auto& wstock = _pool[name];
        stock = wstock.lock();
        if (!stock) {
            stock.reset(new Stock(name), std::bind(&StockPool::deleteStock, std::weak_ptr<StockPool>(shared_from_this()), std::placeholders::_1));
            wstock = stock;
        }
        return stock;
    }

    static void deleteStock(std::weak_ptr<StockPool> wpool, Stock* stock) {
        auto sharePool = wpool.lock();
        if (sharePool) {
            sharePool->_deleteStock(stock);
        }

        delete stock;
    }

    void _deleteStock(Stock* stock) {
        std::lock_guard<std::mutex> lock(_mutex);
        _pool.erase(stock->name());
    }

    std::map<std::string, std::weak_ptr<Stock>> _pool;
    std::mutex _mutex;

    int size() {
        std::lock_guard<std::mutex> lock(_mutex);
        return _pool.size();
    }
};

int main(int argc, char* argv[]) {
    {
        std::shared_ptr<StockPool> stockPool(new StockPool);
        {
            auto stock = stockPool->get("albb");
            std::cout << stock->name() << "\n";
        }
        
        std::cout << "size = " << stockPool->size() << "\n";
    }

    {
        std::shared_ptr<Stock> stock;

        {
            std::shared_ptr<StockPool> stockPool(new StockPool);
            stock = stockPool->get("albb");
        }
    }

}