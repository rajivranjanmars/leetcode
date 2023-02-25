class Solution {
public:
    int recur(vector<int>& prices, int index, int minStockPrice, int maxProfit)
    {
        if(index>=prices.size() || index<0)
        {
            return maxProfit;
        }
        int profit=prices[index]-minStockPrice;
        maxProfit = max(profit, maxProfit);
        
        minStockPrice = min(minStockPrice, prices[index]);
        
        return max(profit, recur(prices, index+1, minStockPrice, maxProfit));
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return recur(prices, 1, prices[0], 0);
    }
};