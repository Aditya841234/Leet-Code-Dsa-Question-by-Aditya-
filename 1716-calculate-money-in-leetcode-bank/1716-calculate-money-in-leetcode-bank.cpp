class Solution {
public:
    int totalMoney(int n) {
      int complete = n/7;

      int incomplete = n%7;

      int part1 = (28*complete) + ((complete*(complete-1))/2) *7;
      int part2 = (incomplete*(incomplete+1))/2 + (complete)*incomplete;

      return part1 + part2;
    }
};