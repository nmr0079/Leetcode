class StockPrice {
public:
    map<int,int> stock;
    map<int,int> prices;
    StockPrice() {}
    
    void update(int timestamp, int price) {
        
        if(stock.find(timestamp) != stock.end()){
            int oldprice = stock[timestamp];
            
            prices[oldprice]--;
            
            if(prices[oldprice] == 0)
                prices.erase(oldprice);
        }
        prices[price]++;
        stock[timestamp] = price;
    }
    
    int current() {
       // unordered_map<int,int>::iterator last_elem;
       // for (unordered_map<int,int>::iterator iter = stock.begin(); iter != stock.end(); iter++)
         //               last_elem = iter;
        
        return stock.rbegin()->second;
    }
    
    int maximum() {
         return prices.rbegin()->first;
    }
    
    int minimum() {
         return prices.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */