

// we can use min heap or ordered map to always get the smallest available card
// then try to build groups from that smallest card

//TC:O(n^2) in worst case due to nested loops and can go O(n*group Size) in average case
//SC:O(n)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        unordered_map<int,int> mp;
        for (int x : hand) {
            mp[x]++;
        }

        // sort so we always try to start groups from smallest numbers
        sort(hand.begin(), hand.end());

        int group_num = 0;
        int need_groups = hand.size() / groupSize;

        for (int i = 0; i < hand.size(); i++) {
            // if this value is already fully used, skip it
            if (mp[hand[i]] == 0) continue;

            int curr = hand[i];
            int curr_group_size = 1;

            // use this as the start of a new group
            mp[hand[i]]--;

            // try to extend this group to size groupSize
            for (int j = i+1; j < hand.size(); j++) {
                if (curr_group_size == groupSize) break;

                if (mp[hand[j]] > 0 && hand[j] == curr + 1) {
                    mp[hand[j]]--;
                    curr = hand[j];
                    curr_group_size++;
                }
            }

            // if we couldn't complete the group, it's impossible
            if (curr_group_size != groupSize) {
                return false;
            }

            // completed one valid group
            group_num++;
        }

        return group_num == need_groups;
    }
};

// optimal approach