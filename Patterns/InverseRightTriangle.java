import java.util.Scanner;

class Main
{
  public static void main(String args[])
  {
    //Try out your code here
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int num = n;
    
    for(int i=0; i<n; i++){
    	for(int j=num; j>=1; j--){
         	 System.out.print(j);
        }
      
      num--;
      System.out.println();
    }
    
  }
}