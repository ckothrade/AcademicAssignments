/**
 * Data collection which includes an array of doubles and stores the 
 * average of the data and it's standard deviation.
 * 
 * @author Kothrade
 *
 */
public class DataGroup {
	
	private double avg;
	private double stdDev;
	private double dArray[];
	private int count = 0;
 	private static final int CAP = 10;
	
	
	/**
	 * Constructor.
	 * @param num the size of the array
	 */
	public DataGroup(){
		avg = 0;
		stdDev = 0;
		dArray = new double[CAP];
	}
	
	/**
	 * Creates a new array with twice the capacity.
	 */
	public void expandCapacity(){
		double[] larger = (double[]) (new double [dArray.length * 2]);
		
		for (int i = 0; i< dArray.length; i++)
			larger[i] = dArray[i];
		
		dArray = larger;
		
	}
	
	/**
	 * Setter method for average.
	 * @param num sets average
	 */
	public void setAvg(double num){
		avg = num;
	}
	
	/**
	 * Setter method for standard deviation.
	 * @param num sets standard deviation
	 */
	public void setStdDev(double num){
		stdDev = num;
	}
	
	/**
	 * Setter method for the double array.
	 * @param num sets array index
	 */
	public void setArray(int num, double val){
	
		if(getSize() == dArray.length)
			expandCapacity();
		
		dArray[num] = val;
		count++;
	}
	
	/**
	 * Getter method for average.
	 * @return average
	 */
	public double getAvg(){
		return avg;
	}
	
	/**
	 * Getter method for the standard deviation.
	 * @return standard deviation
	 */
	public double getStdDev(){
		return stdDev;
	}
	
	/**
	 * Returns value at specified index in the array.
	 * @param num index of array
	 * @return array at index num
	 */
	public double getArrayAt(int num){
		return dArray[num];
	}
	
	/**
	 * Returns the size of the data array.
	 * @return size of the double array
	 */
	public int getSize(){
		return count;
	}
	
	/**
	 * Calculates the average of the array and sets
	 * it to the avg data member.
	 */
	public void calAvg(){
		
		double sum = 0;
		double calc = 0;
		
		for(int i = 0; i < count; i++)
			sum += dArray[i];
		
		calc = sum / count;
		setAvg(calc);
	}
	
	/**
	 * Calculates the standard deviation and sets
	 * it to the appropriate data member.
	 */
	public void calStdDev(){
		
		double temp = 0;
		double sum = 0;
		double calc = 0;
		
		for(int i = 0; i < count; i++){
			temp = dArray[i] - getAvg();
			sum += temp * temp;
		}
		
		calc = Math.sqrt(sum / (count - 1));
		
		setStdDev(calc);
	}
	
	/**
	 * Returns a representation of the class data.
	 */
	public String toString(){
		String temp = "";
		
		temp += "\n Average: " + avg + "\n Standard Deviation: "
				+ stdDev + "\nList of Values: \n";
		
		for(int i= 0; i < count; i++)
			temp += "\n" + dArray[i];
		
		return temp;
	}
	
}
