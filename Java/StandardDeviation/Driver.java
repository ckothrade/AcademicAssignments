
import java.io.*;
import java.util.Scanner;

public class Driver {

	/**
	 * Main method for the average and standard deviation program.
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		
		Scanner scan = new Scanner(System.in);
		
		DataGroup d1 = new DataGroup();
		
		boolean select = false;
		String choice = "";
		
		//Asks if input will come from user or a file
		System.out.println("Please type \"user\" if you would like to enter data,\n"
				+ "or \"file\" if you would like the data to be read from a file.");
		choice = scan.nextLine();
		
		//Approves selection
		if(choice.equals("user") || choice.equals("file"))
			select = true;
		
		//Input validation
		while (!select){
			
			System.out.println("Invalid selection!!! Please make sure you type"
					+ " your \nselection as \"user\" or \"file\". ");
			choice = scan.nextLine();
			
			if(choice.equals("user") || choice.equals("file"))
				select = true;
		}
		
		if(choice.equals("user")){
			
			System.out.println("You have selected to enter the data yourself.");
			
			//Calls method to have user fill the array
			fillArray(d1);
		
			d1.calAvg();
			d1.calStdDev();
			System.out.println(d1);
			
		}else{
			
			System.out.println("This have selected to use an external file.");
			
			//Calls method to have user select a file
			readFile(d1);
			
			d1.calAvg();
			d1.calStdDev();
			System.out.println(d1);
			
		}
		
	}
	
	/**
	 * Fills the array with user input.
	 * @param group
	 */
	public static void fillArray(DataGroup group){
		
		Scanner scan = new Scanner(System.in);
		double temp;
		boolean more = false;
		String cont  = "";
		
		System.out.println();
		
		for (int i = 0; !more ; i++){
			
			System.out.println("Please enter a value: ");
			temp = scan.nextDouble();
			group.setArray(i, temp);
			System.out.println("**Would you like to enter another value? (y/n)**");
			cont = scan.next();
			if(cont.equals("n") || cont.equals("no"))
				more = true;
		}
		
		
	}
	
	/**
	 * Fills the array by reading a designated file.
	 * @param group
	 * @throws FileNotFoundException 
	 */
	public static void readFile(DataGroup group) throws FileNotFoundException{
		
		String file = "";
		Scanner scan = new Scanner(System.in);
		
		System.out.println("\nPlease enter the name of the file you would like to use.");
		file = scan.nextLine();
		
		Scanner input = new Scanner(new File(file));
		
		for(int i = 0; input.hasNextDouble(); i++)
			group.setArray(i, input.nextDouble());
		
	}

	
}
