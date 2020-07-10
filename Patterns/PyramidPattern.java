import java.util.Scanner;

class Main
{
  public static void main(String args[])
  {
    Scanner in = new Scanner(System.in);
    int n= in.nextInt();
    int number = 1;
    
    for(int i=0; i<n; i++){
      
     for(int space=0;space<n-i-1;space++)
        System.out.print(" ");
      
     for(int j=0; j<=i; j++){
     	System.out.print(number + " ");
        number++;
        }
      System.out.println();
    }
  }
}