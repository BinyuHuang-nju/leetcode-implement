import java.util.*;
public class all1356 {
    class Solution {
        public int[] sortByBits(int[] arr) {
            Integer[] nums = new Integer[arr.length];
            for (int i = 0; i < arr.length; i++) {
                nums[i] = arr[i];
            }
            Arrays.sort(nums, (o1, o2) -> {
                int bitCountA = Integer.bitCount(o1);
                int bitCountB = Integer.bitCount(o2);
                return bitCountA == bitCountB ? o1 - o2 : bitCountA - bitCountB;
            });
            for (int i = 0; i < arr.length; i++) {
                arr[i] = nums[i];
            }
            return arr;
        }
    }
}
