public class all1349 {
    static class Solution1 {
        private int max=0;
        private int[][] dir={{0,-1},{0,1},{-1,-1},{-1,1}};
        public int maxStudents(char[][] seats) {
            int m= seats.length,n=seats[0].length;
            backtrace(seats,m,n,m-1,0,0);
            return max;
        }
        void backtrace(char[][] seats,int m,int n,int pos1,int pos2,int cur){
            if(pos2>=n){
                pos1--;
                pos2=0;
            }
            while(pos1>=0){
                if(seats[pos1][pos2]=='.')
                    break;
                pos2++;
                if(pos2==n){
                    pos1--;
                    pos2=0;
                }
            }
            if(pos1<0||pos2>=n){
                max=Math.max(max,cur);
                return;
            }
            // nobody sits here
            seats[pos1][pos2]=(char)('0'+pos2+1);
            backtrace(seats,m,n,pos1,pos2+1,cur);
            seats[pos1][pos2]='.';
            // somebody sits here
            seats[pos1][pos2]='0';
            for(int i=0;i<4;i++){
                int x=pos1+dir[i][0],y=pos2+dir[i][1];
                if(x<0||y<0||y>=n)
                    continue;
                if(seats[x][y]=='.')
                    seats[x][y]=(char)('0'+n+pos2+1);
            }
            backtrace(seats,m,n,pos1,pos2+1,cur+1);
            seats[pos1][pos2]='.';
            for(int i=0;i<4;i++){
                int x=pos1+dir[i][0],y=pos2+dir[i][1];
                if(x<0||y<0||y>=n)
                    continue;
                if(seats[x][y]==(char)('0'+n+pos2+1))
                    seats[x][y]='.';
            }
        }
    }

    static class Solution {
        private int[][] dir={{0,-1},{0,1},{-1,-1},{-1,1}};
        public int maxStudents(char[][] seats) {
            int m= seats.length,n=seats[0].length;
            int[][] dp=new int[m][n];
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){

                }
            }
            return 0;
        }
    }

    public static void main(String[] args) {
        System.out.println("Hello world!");
        all1349.Solution sol = new all1349.Solution();
        char[][] c={{'#','.','.','.','#'},
                {'.','#','.','#','.'},
                {'.','.','#','.','.'},
                {'.','#','.','#','.'},
                {'#','.','.','.','#'}};
        char[][] a={{'.','#','#','.'},
                {'.','.','.','#'},
                {'.','.','.','.'},
                {'#','.','#','#'}};
        char[][] b={{'.','.','.','.','#','.','.','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','#','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','#','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','#','.','.','#','.'}};
        int result = sol.maxStudents(a);
        System.out.println(result);
    }
}