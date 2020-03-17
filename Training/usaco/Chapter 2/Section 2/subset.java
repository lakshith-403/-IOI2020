/*
ID: lakshit4
LANG: JAVA
TASK: subset
*/

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

/**
 * Created by xen0phile on 9/7/15.
 */
class subset {

    static int total, N;
    static long[] holder = new long[1080];
    static long[] holderTemp;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("subset.in"));
        PrintWriter pw = new PrintWriter("subset.out");
        holder[0] = 1;
        holderTemp = Arrays.copyOf(holder, holder.length);

        N = Integer.parseInt(br.readLine());
        total = N * (N + 1) / 2;

        if(total % 2 != 0) {
            pw.println(0);
        }
        else{

            total /= 2;
            int temp = 0;

            for(int i = 1; i <= N; i++){

                for(int j = 0; j <= temp; j++){

                    holder[j + i] += holderTemp[j];

                }

                holderTemp = Arrays.copyOf(holder, holder.length);
                temp = i * (i + 1) / 2;

            }

            pw.println(holder[total]/2);

        }

        pw.flush();
        pw.close();
        br.close();
        System.exit(0);

    }

}