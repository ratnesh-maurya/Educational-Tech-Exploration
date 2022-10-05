public class BestTimeBuySell {
    public int maxProfit(int[] prices) {
     
        int buy = prices[0], max_profit = 0;
        for (int i = 1; i < prices.length; i++) {
     
        if (buy > prices[i])
            buy = prices[i];
     
          
          else if (prices[i] - buy > max_profit)
            max_profit = prices[i] - buy;
        }
        return max_profit;
    

    }

}
