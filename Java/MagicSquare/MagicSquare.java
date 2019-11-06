import java.util.Scanner;

/**
 * Program excepts input from the user in standard format. It will run a series of
 * 3 tests on the inputs to check to see if it is not only a perfect square matrix, 
 * but if the matrix is a Magic Square as well. 
 * 
 * @author Kothrade, Cal
 * @version 1.0, SER_216, 03-19-2017
 *
 */
public class MagicSquare {
	
	/**
	 * Private data field Integer array to represent the user entered matrix.
	 */
	private int[] matrix;
		
		
		
	/**
	 * Default constructor which sets the size of the matrix to 0.
	 */
	public MagicSquare(){
		matrix = new int[0];
	}
		
	/**
	 * Constructor which converts the passed String array to an Integer
	 * array which will represent the perfect square matrix.
	 * 
	 * @param string. The String array containing the values.
	 */
	public MagicSquare(String[] string){
			
		// Sets size of the matrix to the number of values entered.
		matrix = new int[string.length];
			
		// Fills the array with the corresponding values after parsing them.
		for(int i=0; i<string.length; i++){
			// Uses a try/catch method in the event that other data values were entered.
			try{
				matrix[i] = Integer.parseInt(string[i]);
			}
			catch(NumberFormatException exception){
				System.out.println("\nImproper data values entered.");
				System.out.println(" EXITING PROGRAM...");
				System.exit(1);
			}
		}
	}
		
	/**
	 * Setter method for individual index values of the matrix.
	 * 
	 * @param index. Index position where the value is to be inserted.
	 * @param value. The value to be inserted into the matrix.
	 */
	public void setMatrix(int index, int value){
			
		matrix[index] = value;
	}
		
	/**
	 * Getter method for the Integer array representation of the matrix.
	 * 
	 * @return matrix. Array representation of the matrix.
	 */
	public int[] getMatrix(){
			
		return matrix;
	}
		
	/**
	 * The 2nd test which ensures that every value from 1 to the number of
	 * values entered appear in the matrix, and no more than one time.
	 * 
	 * @return True if all of the values in the matrix occur only and at least once.
	 */
	public boolean testOccurence(){            
			
		// Initializes account variable to 0.
		int count = 0;
			
		//---------------------------------------------------------------------
		// Nested loop which compares every index of the array to the expected
		// values of the matrix. If the value is a match, the counter is 
		// incremented. Only a counter equal to the number of values provided
		// will have every number appear at least and no more than once.
		//---------------------------------------------------------------------
		for(int i=0; i<matrix.length; i++){
			for(int j=1; j<=matrix.length; j++){
				if(matrix[i]==j)
					count += 1;
			}
		}
			
		// If the counter is equal to the number of values, return true.
		if(count==matrix.length)
			return true;
		else 
			return false;
	}
		
	/**
	 * Calculates the sum of the first column of the matrix and uses this
	 * sum as the standard to be achieved in the addition processes for rows,
	 * columns and diagonals. (Benchmark Value).
	 * 
	 * @return sum. The sum of the first column.
	 */
	public int calcSum(){
			
		// Initializes variables to 0.
		int j=0, sum = 0;
			
		// Adds the values in the first column.
		for(int i=0; i<Math.sqrt(matrix.length); i++){
			sum += matrix[j];
			j += Math.sqrt(matrix.length);
		}
			
		// Returns the sum of the first column.
		return sum;
	}
		
	/**
	 * The 1st part of the 3rd test, which calculates the sums of each row
	 * in the matrix and determines if they are equal to the benchmark value.
	 * 
	 * @return True if all of the rows in the matrix are equal to the benchmark value.
	 */
	public boolean testRows(){
			
		// Assigns a benchmark value to the variable
		int mark = calcSum();
			
		// Initializes variables to 0.
		int k = 0, count = 0, sum;
			
		// A loop which will cycle through each row
		for(int i=0; i<Math.sqrt(matrix.length); i++){
				
			// Resets the sum to 0 for each row.
			sum = 0;
				
			// A loop which cycles through each value in the row.
			for(int j=0; j<Math.sqrt(matrix.length); j++){
					
				// Adds each value in the row to the rows sum.
				sum += matrix[k];
				// Increments the variable to ensure the correct placeholder of the value.
				k++;
			}
				
			// Increases a counter if the sum is equal to the bench mark.
			if(sum == mark)
				count++;
		}
			
		// If the counter is equal to the number of rows, then all of the sums match.
		if(count == Math.sqrt(matrix.length))
			return true;
		else
			return false;
	}
		
	/**
	 * Part 2 of the 3rd test. Calculates the sums of the Columns in the matrix
	 * and determines if they are all equal to the benchmark value.
	 * 
	 * @return True if all columns in the matrix are equal to the benchmark value.
	 */
	public boolean testColumns(){
			
		// Assigns a benchmark value to the variable
		int mark = calcSum();
				
		// Initializes variables to 0.
		int k, sum, count = 0;
			
		// Cycles through the columns of the matrix.
		for(int i=0; i<Math.sqrt(matrix.length); i++){
				
			// Resets the sum for each column to 0.
			sum = 0;
			// Sets the place holder for the top value in each column.
			k = i;
				
			// Cycles through each value in the column.
			for(int j=0; j<Math.sqrt(matrix.length); j++){
					
				// Adds each value to the column sum.
				sum += matrix[k];
				// Increases placeholder to the appropriate value in each column.
				k += Math.sqrt(matrix.length);
			}
				
			// Increases a counter if the sum is equal to the bench mark.
			if(sum == mark)
				count++;
				
		}
			
		// If the counter is equal to the number of rows, then all of the sums match.
		if(count == Math.sqrt(matrix.length))
			return true;
		else
			return false;	
	}
		
	/** 
	 * Part 3 of the 3rd test. Calculates the sum of the Diagonal paths 
	 * and determines if they are equal to the benchmark.
	 * 
	 * @return True if both Diagonal paths are equal to the benchmark.
	 */
	public boolean testDiagonals(){
			
		// Assigns a benchmark value to the variable
		int mark = calcSum();
					
		// Initializes sums for each Diagonal to 0.
		int sum1 = 0, sum2 = 0;
			
		// Placeholder for the values in the 1st (Top-Left to Bottom-Right) Diagonal.
		int k = 0;
		// Cycles through the values in the 1st diagonal.
		for(int i=0; i<Math.sqrt(matrix.length); i++){
				
			// Adds the value to the 1st Diagonals sum.
			sum1 += matrix[k];
			// Increases the placeholder of the values accordingly.
			k += Math.sqrt(matrix.length) + 1;
		}
			
		// Placeholder for the values in the 2nd (Top-Right to Bottom-Left) Diagonal.
		int j = (int) Math.sqrt(matrix.length) - 1;
		// Cycles through the values in the 2nd diagonal.
		for(int i=0; i<Math.sqrt(matrix.length); i++){
						
			// Adds the value to the 1st Diagonals sum.
			sum2 += matrix[j];
			// Increases the placeholder of the values accordingly.
			j += Math.sqrt(matrix.length) - 1;
		}
			
		// If both diagonals equal the benchmark, then the method returns true.
		if(sum1 == mark && sum2 == mark)
			return true;
		else
			return false;
			
	}
		
	/**
	 * A method which returns a string designed to display the contents of the matrix.
	 * 
	 * @return disp. A string containing the contents of the matrix.
	 */
	public String toString(){
			
		// Instantiates an empty string.
		String disp="";                    
			
		// Placeholder for the matrix values.
		int k = 0;
			
		// A loop to display each row.
		for(int i=0; i<Math.sqrt(matrix.length); i++){
			disp += "\n\n   ";
			// A loop to display each value in the row.
			for(int j=0;j<Math.sqrt(matrix.length); j++){
				disp += matrix[k] + "   ";
				k++;
			}
		}
		disp += "\n\n";
			
		// Returns the display.
		return disp;
	}
	
	/**
	 * The main method for the driver of the program. Calls all of the functions
	 * and methods to determine if a matrix is a Magic Square.
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		
		// Instruction set for the program.
		System.out.println("This program will except inputs from you and create a " +
		"corresponding matrix from those inputs,\ngiven that the number of inputs you provide " +
		"is a perfect square.\n\nThis happens to be the first test in determining if your " +
		"perfect square matrix is MAGIC SQUARE.\nSubsequent tests that will be conducted " +
		"include making sure that every number between 1 and the number of values\nyou enter " + 
		"are present in the matrix, and that they occur no more than once. Also, every " +
		"row, column and diagonal\npath will have their sums calculated to ensure that " +
		"they all share the same value.\n\n Please be sure to enter your values altogether " +
		"on the same line with a space succeeding each value.\n\nFor example:\n Please enter the " +
		"values of your matrix: 1 2 3 4 5 6 7 8 9\n\n");
		
		
		//----------------------------------------------------------------------
		// Calls the function "initiate" which requests input from the users
		// and returns a String array determined from a standard form of input.
		//----------------------------------------------------------------------
		String[] string = initiate();
		
		//----------------------------------------------------------------------
		// Passes the String array of values to the function in hopes of 
		// determining if the number of values entered create a perfect square.
		// This calls the function of the first test.
		//----------------------------------------------------------------------
		boolean square = perfectSquare(string);
		
		//----------------------------------------------------------------------
		// Uses the returned boolean value from the first test to inform the
		// user if their entered values pass or fail the test.
		//----------------------------------------------------------------------
		if(square == true){
			// Informs the user if their values have passed test 1.
			System.out.println("\nCongratulations! You have entered a correct number inputs " +
			"to complete a perfect square matrix, thus passing the first test.\nLets continue" + 
			" with further tests to determine if you have correctly created a Magic Square.");
		}
		else{
			// Informs the user that they have failed test 1 and then exits the program.
			System.out.println("\nSorry, the number of inputs you provided is not a perfect" +
		    " square, thus failing the first test requirement.\nPlease try again!" +
			"\n\n EXITING PROGRAM...");
			System.exit(1);
		}
		
		// Instantiates a MagicSquare object using the String array. 
		MagicSquare magic1 = new MagicSquare(string);
		
		// Displays the corresponding matrix back to the user.
		System.out.println("\n According to the order in which you have entered you inputs, " +
		"your respective matix looks like this:");
		System.out.print(magic1.toString());
		
		//----------------------------------------------------------------------
		// Calls the method from the MagicSquare class which corresponds to
		// test 2 on the user entered matrix to determine if each number occurs
		// at least and only once.
		//----------------------------------------------------------------------
		boolean nums = magic1.testOccurence();
		
		//----------------------------------------------------------------------
		// Uses the returned boolean value from the second test to inform the
		// user if their entered values pass or fail the test.
		//----------------------------------------------------------------------
		if(nums == true){
			// Informs the user if their values have passed test 2.
			System.out.println("\nCongratulations! All of the values from 1 to the number of " +
		    "values you entered appear only and at least once in your matrix.\nThus passing" +
			" test 2. We are one step closer to determining if your entered values depict" + 
		    " a Magic Square. ");
		}
		else{
			// Informs the user that they have failed test 2 and then exits the program.
			System.out.println("\nSorry, your matrix does not contain at least every number " +
		    "from 1 to the number of values you entered, thus failing test 2.\nPlease try" + 
			" again!.\n\n EXITING PROGRAM...");
			System.exit(1);
		}
		
		//------------------------------------------------------------------------
		// Calls a method to calculate the sum of the first column of the matrix,
	        // which will be used as the benchmark for comparing the rest of the sums 
		// from the rows, columns & diagonals.
		//------------------------------------------------------------------------
		int sum = magic1.calcSum();
		System.out.println("\n\nHere is the sum of the first column :  " + sum +
		"\nThis value will be used as the benchmark for comparing the values of " +
		"Row, Column and Diagonal sums.\n");
		
		//---------------------------------------------------------------------
		// Calls the method which will compare the sums of all of the rows 
		// in the matrix to the designated standard value.
		//---------------------------------------------------------------------
		boolean rows = magic1.testRows();
		
		//---------------------------------------------------------------------
		// Uses the returned boolean value to determine if the provided matrix 
		// passes the first part of the 3rd test.
		//---------------------------------------------------------------------
		if(rows == true){
			// Informs the user that all of the rows sum up to the same value.
			System.out.println("\nCongratulations! All " + (int)Math.sqrt(string.length) +
			" rows in your matrix result in the sum of " + magic1.calcSum()	+ "\nWe are " +
			"one step closer to determining if your matrix is a Magic Square.");
		}
		else{
			// Informs the user that they have failed test 3 and then exits the program.
			System.out.println("\nSorry, all of the rows in your matrix must contain the " +
			"same sum.\nPlease try again.\n\n EXITING PROGRAM...");
			System.exit(1);
		}
		
		//---------------------------------------------------------------------
		// Calls the method which will determine if all of the columns are
		// equal to the bench mark value.
		//---------------------------------------------------------------------
		boolean cols = magic1.testColumns();
		
		//---------------------------------------------------------------------
		// Uses the returned boolean value to determine if the provided matrix 
		// passes the second part of the 3rd test.
		//---------------------------------------------------------------------
		if(cols == true){
			// Informs the user that all of the rows sum up to the same value.
			System.out.println("\nCongratulations! All " + (int)Math.sqrt(string.length) +
			" columns in your matrix result in the sum of " + magic1.calcSum()	+ "\nWe are " +
			"one step closer to determining if your matrix is a Magic Square.");
		}
		else{
			// Informs the user that they have failed test 3 and then exits the program.
			System.out.println("\nSorry, all of the columns in your matrix must contain the " +
			"same sum.\nPlease try again.\n\n EXITING PROGRAM...");
			System.exit(1);
		}
		
		//--------------------------------------------------------------------
		// Calls the method which compares the Diagonal sums to the benchmark
		// value.
		//--------------------------------------------------------------------
		boolean diags = magic1.testDiagonals();
		
		//---------------------------------------------------------------------
		// Uses the returned boolean value to determine if the provided matrix 
		// passes the third part of the 3rd test.
		//---------------------------------------------------------------------
		if(diags == true){
			// Informs the user that both Diagonals sum up to the same value.
			System.out.println("\nCongratulations! Both Diagonal paths in your matrix " +
			"sum up to the same benchmark value.\nThis confirms that your provided matrix " +
			"has passed the last part of the final test.");
		}
		else{
			// Informs the user that they have failed test 3 and exits the program.
			System.out.println("\nSorry, both Diagonal paths must contain the same sum." +
			"\nPlease try again.\n\n EXITING PROGRAM...");
		}
		
		//--------------------------------------------------------------------
		// Informs the user that their entered matrix has successfully passed 
		// all three tests and is indeed a Magic Square.
		//--------------------------------------------------------------------
		System.out.println("\n\n The inputs you have provided to create your perfect " +
		"square matrix have successfully passed all three tests!\n Your matrix is a " +
		"MAGIC SQUARE!!!");
		
	}
	
	/**
	 * Begins the process of requesting inputs from the user by using a 
	 * standard method of input. 
	 * 
	 * @return string1. String array containing entered input values.
	 */
	public static String[] initiate(){
		
		// Creates new scanner object.
		Scanner scan = new Scanner(System.in);
						
		// Requests the user to enter the inputs.
		System.out.println("\nPlease enter the values of your matrix: ");
		String inputs = scan.nextLine();
		
		// Close Scanner object.
		scan.close();
						
		// Assigns each separate input to an index in a String array.
		String[] string1 = inputs.split(" ");

		// Returns the string array.
		return string1;
	}
	
	/**
	 * Accepts the String array of input values and determines if the number of 
	 * input values (size of array) is a perfect square, or in other words if it 
	 * passes the first test.
	 * 
	 * @param test. The String array of input values.
	 * @return True if the number of input values is a perfect square.
	 */
	public static boolean perfectSquare(String[] test){
		
		// Calculates the square root of the number of values entered.
		double value = Math.sqrt(test.length);
		
		// Returns true if the number of values entered is a perfect square.
		if(value ==(int)value)
			return true;
		else
			return false;
		
	}

}
