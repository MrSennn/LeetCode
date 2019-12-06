#include<iostream>
#include<vector>
using namespace std;
//��Ʊ�ܹ�ͬһ�����������������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ
class Solution {
public:
	int maxProfit(vector<int>& prices) {//Solution1�ļ�������
		int profit = 0;
		for (int i = 1; i < prices.size(); i++) {//ֻҪ��i-1��������ڵ�i����������׬Ǯ������
			if (prices[i] > prices[i - 1])
				profit += prices[i] - prices[i - 1];
		}
		return profit;
	}
};
class Solution1 {//��ͨ�������ڷ�����룬�ڷ嶥����
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0;
		int i = 0;
		int peak, valley;
		while (i < prices.size()) {//��������
			while (i < prices.size()-1 && prices[i] > prices[i + 1])//��ǰ����ֱ����һ�����ȸ�ֵ��
				i++;
			valley = prices[i];//��ֵ���
			while (i < prices.size()-1 && prices[i] < prices[i + 1])//��ǰ����ֱ����һ�����ȸ�ֵС
				i++;
			peak = prices[i];//��ֵ�嶥
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