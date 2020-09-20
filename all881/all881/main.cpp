#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution1 {  //true but exceeds time limitations
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int nums = 0;
        sort(people.begin(), people.end());
        while (!people.empty()) {
            if (people.size() == 1 || people[people.size() - 1] >= limit || (people.size() > 1 && people[people.size() - 1] > limit - people[0])) {
                nums++;
                people.pop_back();
            }
            else
                break;
        }
        int i;
        while (people.size() > 1) {
            i = people.size() - 1;
            while (i > 0) {
                if (people[0] + people[i] <= limit)
                    break;
                i--;
            }
            if (i == 0)
                return nums + people.size();
            nums++;
            //people.erase(people.begin());
            people.erase(people.begin() + i);
            people.erase(people.begin());
         }
        return nums + people.size();
    }
};

class Solution {  
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int nums = 0;
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1;
        while (right >= 0) {
            if (right==0 || people[right] >= limit || (right > 0 && people[right] > limit - people[0])) {
                nums++;
                right--;
            }
            else
                break;
        }

        while (left < right) {
            if (people[left] + people[right] <= limit) {
                nums++;
                left++;
                right--;
            }
            else {
                nums++;
                right--;
            }
        }
        return nums + (right - left + 1);
    }
};