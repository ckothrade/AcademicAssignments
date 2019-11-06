import java.util.Arrays;
import java.util.Scanner;

public class EmployeeWorkHours {

	/**
	 * Allows user to input an employees name
	 * @return name employees name
	 */
	public static String idEmpl(int k){
		String name;
		k = k + 1;
		
		System.out.println("Enter employee " + k + "'s name: ");
		
		Scanner scan = new Scanner(System.in);
		name = scan.nextLine();
		
		return name;
	}
	
	/**
	 * User designates how many days were worked for the week
	 * @return num number of days worked
	 */
	public static int numDays(String nm){
		int num;
		
		System.out.println();
		System.out.println("Enter employee " + nm + "'s number of days worked: ");
		
		Scanner scan = new Scanner(System.in);
		num = scan.nextInt();
		
		return num;
	}
	
	/**
	 * User designates employee hours for the day
	 * @return hrs number hours worked
	 */
	public static int numHours(int d){
		int hrs;
		d = d+1;
		System.out.println("Enter the employee's number of hours worked on day"
				+  d + " : ");
		
		Scanner scan = new Scanner(System.in);
		hrs = scan.nextInt();
		
		return hrs;
	}
	
	/**
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
	
		
		int emp = 0;
		int days = 0;
		int hours = 0;
		String title;
		
		Scanner scan = new Scanner(System.in);
		
		System.out.println("Please enter the number of employees: ");
		emp = scan.nextInt();
		
		//creates an array of objects
		Employee[] employees = new Employee[emp];
		
		//constructs new objects in array
		for(int i = 0; i < emp; i++){
			title = idEmpl(i); //asks for name
			employees[i] = new Employee(title);
			
		}

		//displays array of employees
		for(int i = 0; i < emp; i++)
			System.out.println(employees[i].toString());
		
		//for loop that retries days and hrs for employees
		for(int i = 0; i < emp; i++){
			days = numDays(employees[i].getName());
			for(int j = 0; j < days; j++){
				hours = numHours(j);
				employees[i].setWeek(j, hours);
			}		
		}
		
		System.out.println();
		System.out.println("-----Employee Hr Log-----");
		
		//prints the employees' information
		for(int i = 0; i < emp; i++)
			System.out.println(employees[i].toString());
		
		//Creates integer array to hold total hours
		int[] total = new int[emp];
		
		//Displays employee log
		for(int i = 0; i < emp; i++)
			total[i] = employees[i].getTotalHours();
		
		System.out.println();
		System.out.println("-----Hours Log Descending-----");
		
		//Sorts the hours array
		Arrays.sort(total);
		
		//Displays employee logs descending
		for(int i = emp - 1; i >= 0; i--){
			for(int j = 0; j < emp; j++)
				if(employees[j].getTotalHours() == total[i])
					System.out.println(employees[j].toString());
		}
	}

}

class Employee {
	
	final int MAX = 7;
	String name;
	int []week = new int[MAX];
	
	/**
	 * Default Constructor.
	 */
	Employee(){
		name = "John Doe";
		for(int i = 0; i<MAX; i++)
			week[i] = 0;
	
	}
	
	/**
	 * Constructor.
	 * @param name
	 */
	Employee(String nm){
		name = nm;
		for(int i = 0; i<MAX; i++)
			week[i] = 0;
	}
	
	/**
	 * Sets the name variable.
	 * @param nm
	 */
	void setName(String nm){
		name = nm;
	}
	
	/**
	 * Sets the hours for the days of the week.
	 * @param i, day of the week
	 * @param hrs, hours worked that day
	 */
	void setWeek(int i, int hrs){
		week[i] = hrs;
	}
	
	/**
	 * Retrieves customer name.
	 * @return name
	 */
	String getName(){
		return name;
	}
	
	/**
	 * Returns the hours worked on that day.
	 * @param day of the week
	 * @return weekday hours
	 */
	int getWeek(int i){
		return week[i];
	}
	
	/**
	 * Returns the maximum hours worked for the week
	 * @return hrs total hours for the week
	 */
	int getTotalHours(){
		int hrs = 0;
		for(int i = 0; i < MAX; i++)
			hrs += getWeek(i);
		
		return hrs;
	}

	/**
	 * Displays employee information.
	 */
	public String toString(){
		
		int hrs = 0;
		for(int i = 0; i < MAX; i++)
			hrs += getWeek(i);
		
		return "Employee: " + name 
				+ "  --- Hours: " + hrs;
	}
	
	

}

