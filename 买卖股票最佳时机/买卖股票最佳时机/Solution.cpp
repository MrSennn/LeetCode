#include<iostream>
#include<vector>
using namespace std;
//股票能够同一天买卖，但必须在再次购买前出售掉之前的股票
class Solution {
public:
	int maxProfit(vector<int>& prices) {//Solution1的简化升级版
		int profit = 0;
		for (int i = 1; i < prices.size(); i++) {//只要第i-1天买入后，在第i天卖出，能赚钱，就卖
			if (prices[i] > prices[i - 1])
				profit += prices[i] - prices[i - 1];
		}
		return profit;
	}
};
class Solution1 {//普通方法，在峰谷买入，在峰顶卖出
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0;
		int i = 0;
		int peak, valley;
		while (i < prices.size()) {//遍历数组
			while (i < prices.size()-1 && prices[i] > prices[i + 1])//向前遍历直到下一个数比该值大
				i++;
			valley = prices[i];//赋值峰谷
			while (i < prices.size()-1 && prices[i] < prices[i + 1])//向前遍历直到下一个数比该值小
				i++;
			peak = prices[i];//赋值峰顶
			profit += peak - valley;
		}
		return profit;
	}
};
int main() {
	vector<int> v = { 7,6,5,4,3,2 };
	cout << Solution().maxProfit(v) << endl;
	cout << Solution1().maxProfit(v) << endl;
}