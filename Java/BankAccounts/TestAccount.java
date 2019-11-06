import java.util.InputMismatchException;
import java.util.Scanner;

/**
 * Driver for the Account Class testing.
 * @author Kothrade, Cal
 *
 */
public class TestAccount {
	
	/**
	 * Main method, tests Account Classes.
	 * @param args
	 */
	public static void main(String[] args){
		
		//Creates default accounts
		Checking c1 = new Checking();
		Savings s1 = new Savings();
		
		//Calls methods to gain user input
		dataCollection(c1);
		dataCollection(s1);
		
		//Prints account information
		System.out.println("-----Account Statments-----");
		System.out.println();
		System.out.println(c1);
		System.out.println();
		System.out.println(s1);
		
	}
	
	
	
	/**
	 * Requests user to enter Checking Account data.
	 * @param ch1 Checking
	 */
	public static void dataCollection(Checking ch1){
		int tempId = 0;
		double tempBal = 0;
		double tempAnn = 0;
		double draw = 0;
		double posit = 0;
		
		Scanner scan = new Scanner(System.in);
		
		try{
			System.out.println();
			System.out.println("Please enter the unique Identification number you "
					+ "would \nlike to assign to the Checking Account (integer): ");
			tempId = scan.nextInt();
			ch1.setAccountId(tempId);
			
			System.out.println("Please enter the current balance of the Checking "
					+ "\nAccount (double): ");
			tempBal = scan.nextDouble();
			ch1.setBalance(tempBal);
			
			System.out.println("Please enter the Annual Interest Rate for the "
					+ "\nChecking Account (double): ");
			tempAnn = scan.nextDouble();
			ch1.setAnnualInterestRate(tempAnn);
			
			System.out.println("Please enter an amount that you would like to "
					+ "\nwithdraw from the Checking Account (double): ");
			draw = scan.nextDouble();
			ch1.withdraw(draw);
			
			System.out.println("Please enter an amount that you would like to "
					+ "\ndeposit into the Checking Account (double): ");
			posit = scan.nextDouble();
			ch1.deposit(posit);
			
		}
		catch(InputMismatchException exception){
			System.out.println("Invalid data input!");
			System.out.println("     EXITING PROGRAM...");
			System.exit(1);
		}
	
	}
	
	/**
	 * Requests user to enter Savings Account data.
	 * @param sv1 Savings
	 */
	public static void dataCollection(Savings sv1){
		int tempId = 0;
		double tempBal = 0;
		double tempAnn = 0;
		double draw = 0;
		double posit = 0;
		
		Scanner scan = new Scanner(System.in);
		
		try{
			System.out.println();
			System.out.println("Please enter the unique Identification number you "
					+ "\nwould like to assign to the Savings Account (integer): ");
			tempId = scan.nextInt();
			sv1.setAccountId(tempId);
		
			System.out.println("Please enter the current balance of the Savings "
					+ "\nAccount (double): ");
			tempBal = scan.nextDouble();
			sv1.setBalance(tempBal);
				
			System.out.println("Please enter the Annual Interest Rate for the "
					+ "\nSavings Account (double): ");
			tempAnn = scan.nextDouble();
			sv1.setAnnualInterestRate(tempAnn);
			
			System.out.println("Please enter an amount that you would like to "
					+ "\nwithdraw from the Savings Account (double): ");
			draw = scan.nextDouble();
			sv1.withdraw(draw);
			
			System.out.println("Please enter an amount that you would like to "
					+ "\ndeposit into the Savings Account (double): ");
			posit = scan.nextDouble();
			sv1.deposit(posit);
			
		}
		catch(InputMismatchException exception){
			System.out.println("Invalid data input!");
			System.out.println("     EXITING PROGRAM...");
			System.exit(1);
		}
	}
	
}
