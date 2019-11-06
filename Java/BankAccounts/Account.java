import java.util.Date;

/**
 * Creates a parent class account to hold bank information.
 * @author Kothrade, Cal
 *
 */
public class Account {

	private int accountId;
	private double balance;
	private double annualInterestRate;
	private Date dateCreated = new Date();
	
	/**
	 * Default constructor.
	 */
	public Account(){
		accountId = 0;
		balance = 0;
		annualInterestRate = 0;
	}
	
	/**
	 * Constructor.
	 * @param id sets AccountId
	 * @param bal sets Account Balance
	 * @param ann sets Account Annual Interest Rate
	 */
	public Account(int id, double bal, double ann){
		accountId = id;
		balance = bal;
		annualInterestRate = ann;
	}
	
	/**
	 * Setter method.
	 * @param id sets AccountId
	 */
	public void setAccountId(int id){
		accountId = id;
	}
	
	/**
	 * Setter method.
	 * @param bal sets Account Balance
	 */
	public void setBalance(double bal){
		balance = bal;
	}
	
	/**
	 * Setter method.
	 * @param ann sets Account Annual Interest Rate
	 */
	public void setAnnualInterestRate(double ann){
		annualInterestRate = ann;
	}
	
	/**
	 * Getter method.
	 * @return AccountId
	 */
	public int getAccountId(){
		return accountId;
	}
	
	/**
	 * Getter method.
	 * @return Account Balance
	 */
	public double getBalance(){
		return balance;
	}
	
	/**
	 * Getter method.
	 * @return Account Annual Interest Rate
	 */
	public double getAnnualInterestRate(){
		return annualInterestRate;
	}
	
	/**
	 * Getter method.
	 * @return Date of Account
	 */
	public Date getDateCreated(){
		return dateCreated;
	}
	
	/**
	 * Calculates the monthly interest rate using the Annual
	 * rate associated with the account.
	 * @return Monthly Accrued Interest
	 */
	public double getMonthlyInterest(){
		
		double num = annualInterestRate / 12;    //Rate for one month
		num = num / 100;    //Converts rate to percentage
		double temp = num * getBalance();  //Calculates monthly interest
		
		return temp;
	}
	
	/**
	 * Withdraws value from Account Balance.
	 * @param val value to be withdrawn
	 */
	public void withdraw(double val){
		balance -= val;
	}
	
	/**
	 * Deposits value to the Account Balance.
	 * @param dep Value to be deposited(integer)
	 */
	public void deposit(int dep){
		balance += dep;	
	}
	
	/**
	 * Deposits value to the Account Balance.
	 * @param dep Value to be deposited(double)
	 */
	public void deposit(double dep){
		balance += dep;
	}
	
	/**
	 * Displays Account information.
	 * @return display
	 */
	public String toString(){
		return "Account ID: " + getAccountId() + "   "
		+ "***Date Originated:  " + getDateCreated()  + " ***"
		+ "\n Annual Interest Rate: " + getAnnualInterestRate()
		+ "\n Current Balance: " + getBalance()
		+ "\n Monthly Interest: " + getMonthlyInterest();
	}
}
