#include <iostream>
#include <vector>

class Solution {
    void bulb(std::vector<int>& stones) {
        for (int i = 0; i < stones.size(); i++) {
            for (int j = 0; j < stones.size() - 1; j++) {
                if (stones[j] > stones[j + 1]) {
                    int temp = stones[j];
                    stones[j] = stones[j + 1];
                    stones[j + 1] = temp;
                }
            }
        }
    }

   
public:
    int lastStoneWeight(std::vector<int>& stones) {

        while (stones.size() > 1) {
            bulb(stones);
            int n = stones.size();
            int v = stones[n - 1] - stones[n - 2];
            stones.pop_back();
            stones.pop_back();
            if (v || stones.size() == 0) {
                stones.push_back(v);
            }
        }

        return stones[0];





    }
};