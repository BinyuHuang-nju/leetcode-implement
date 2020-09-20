public class all1381 {
    class CustomStack {
        private int[] stack;
        private int maxSize;
        private int curSize;
        public CustomStack(int maxSize) {
            stack=new int[maxSize];
            this.maxSize=maxSize;
            this.curSize=0;
        }

        public void push(int x) {
            if(curSize<maxSize){
                stack[curSize]=x;
                curSize++;
            }
        }

        public int pop() {
            if(curSize>0){
                curSize--;
                return stack[curSize];
            }
            return -1;
        }

        public void increment(int k, int val) {
            for(int i=0;i<k&&i<curSize;i++)
                stack[i]+=val;
        }
    }
}
