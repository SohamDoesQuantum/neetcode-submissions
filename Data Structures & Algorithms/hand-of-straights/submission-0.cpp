class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        std::map<int, int> d;
        for (int i : hand) {
            d[i]++;
        }
        for (auto const& [i, count] : d) {
            while (d[i] != 0) {
                for (int x = 0; x < groupSize; x++) {
                    int current_card = i + x;
                    
                    
                    if (d.find(current_card) != d.end()) {

                        if (d[current_card] == 0) {
                            
                            return false;
                        }
                        d[current_card]--; 
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};