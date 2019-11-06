import java.util.Scanner;

/**
 * Has the user input values for which they wish
 * to have the Greatest Common Denominator calculated.
 * 
 * @author Kothrade
 * 
 *
 */
public class GreatestCommon {

	/**
	 * Driver for the GCD program.
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		
		int max;
		Scanner scan = new Scanner(System.in);
		
		System.out.println(" Please enter the number of calculations\n"
		+ " you would like to make: ");
		
		max = scan.nextInt();
		
		int[] num1 = new int[max];
		int[] num2 = new int[max];
		int[] gcd = new int[max];
		
		for(int i = 0; i < max; i++){
			System.out.println("\nEnter number 1 for calculation "
					+ (i+1) + " : ");
			num1[i] = scan.nextInt();
			
			System.out.println("\nEnter number 2 for calculation "
					+ (i+1) + " : ");
			num2[i] = scan.nextInt();
		}
		
		for(int i = 0; i < max; i++)
			gcd[i] = calGCD(num1[i], num2[i]);
		
		for (int i = 0; i < max; i++){
			System.out.println(" Number " + num1[i]
			+ "  Number " + num2[i] + "  GCD " + gcd[i]);
		}

	}

	/**
	 * Calculates the GCD of two values.
	 * 
	 * @param a value 1
	 * @param b value 2
	 * @return the GCD
	 */
	public static int calGCD(int a, int b){
		
		int c;
		
		while(b != 0){
			c = a % b;
			a = b;
			b = c;
		}
		
		return a;
	}
	
}
