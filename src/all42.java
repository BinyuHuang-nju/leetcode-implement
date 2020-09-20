import java.util.*;
public class all42 {
    static class Solution {
        public int trap(int[] height) {
            if(height.length<3)
                return 0;
            Stack<Integer> stack=new Stack<>();
            stack.push(0);
            int result = 0;
            for(int i=1;i<height.length;i++){
                while(!stack.empty()&&height[stack.peek()]<height[i]) {
                    int bottom = stack.pop();
                    while(!stack.empty()&&height[stack.peek()]==height[bottom])
                        stack.pop();
                    if (!stack.empty()) {
                        result += (Math.min(height[stack.peek()], height[i]) - height[bottom]) * (i - stack.peek() - 1);
                    }
                }
                stack.push(i);
            }
            return result;
        }
    }
    public static void main(String[] args) {
        System.out.println("Hello world!");
        all42.Solution sol = new all42.Solution();
        int[] a={3,2,1,0,1,0,4};
        int result = sol.trap(a);
        System.out.println(result);
    }
}
/*
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size(), i, j;
        if (len <= 2)
            return 0;
        int* leftmax = new int[len];
        int* rightmax = new int[len];
        leftmax[0] = 0;
        rightmax[len - 1] = 0;
        int curmax = height[0];
        for (i = 1; i < len; i++) {
            curmax = curmax > height[i] ? curmax : height[i];
            leftmax[i] = curmax;
        }
        curmax = height[len - 1];
        for (j = len - 2; j >= 0; j--) {
            curmax = curmax > height[j] ? curmax : height[j];
            rightmax[j] = curmax;
        }
        int sum = 0;
        int maxmin;
        for (i = 1; i < len - 1; i++) {
            maxmin = leftmax[i] > rightmax[i] ? rightmax[i] : leftmax[i];
            if (maxmin > height[i])
                sum += (maxmin - height[i]);
        }
        delete[]leftmax;
        delete[]rightmax;
        return sum;
    }
};
 */