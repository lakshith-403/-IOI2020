import java.util.*;
import java.io.*;

public class prob {

     static Scanner i = new Scanner(System.in);

    static boolean is() {
        int l= i.nextInt();
        int x=i.nextInt();
        int y=i.nextInt();
        boolean result=true;
        if(x<y)result=false;
        int g=x-y;
        int x1;int y1;
        for(int j=1;j<l;j++){
            x1=i.nextInt();
            y1=i.nextInt();
            if(g>x1-y1||x1<y1||x1<x||y1<y)result =false;
            g=x1-y1;
            x=x1;y=y1;
        }
        return result;
    }


    static public void main(String[] args) throws IOException {
            int n = i.nextInt();
            for (int k = 0;k < n; k++) {
                if (is()) {
                System.out.println("YES");
                }
            else {
                System.out.println("NO");
            }
        }
    }
}
