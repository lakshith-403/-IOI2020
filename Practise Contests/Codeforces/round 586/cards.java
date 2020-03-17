
import java.util.Scanner;

public class cards{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        String s = sc.nextLine();
        
        int nCount = 0;
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='n')
                nCount++;
        }
        for(int i=0;i<nCount;i++){
            System.out.print("1 ");
        }
        int ZCount = (n - (nCount*3))/4;
        for(int i=0;i<ZCount;i++){
            System.out.print("0 ");
        }
        System.out.println();
    }
}
