/**
 * Extends the Account class and defines it as a
 * Checking Account.
 * @author Kothrade, Cal
 *
 */
public class Checking extends Account{

	/**
	 * Default constructor for Checking Class, calls super.
	 */
	public Checking() {
		super();
	}

	/**
	 * Constructor for Checking Class, takes 3 parameters, calls super.
	 * @param id sets AccountId
	 * @param bal sets Account Balance
	 * @param ann sets Account Annual Interest Rate
	 */
	public Checking(int id, double bal, double ann){
		super(id, bal, ann);
	}
	
	/**
	 * Makes a withdrawal from Checking. Overrides Account method.
	 * @param val value to be withdrawn
	 */
	@Override
	public void withdraw(double val){
		double temp = 0;
		int cap = -5000;
		
		//Allows users to overdraw up to $5,000
		if ((getBalance() - val) < cap)
			System.out.println("Error: Overdraft Limit Reached!");
		else{
			temp = getBalance() - val;
			setBalance(temp);  //Sets new balance
		}	
	}
	
	/**
	 * Returns a string displaying account information.
	 * Overrides Account method.
	 */
	@Override
	public String toString(){
		return "ACCOUNT TYPE: _Checking"
		+ "\nAccount ID: " + getAccountId() + "   "
		+ "***Date Originated:  " + getDateCreated()  + " ***"
		+ "\n Annual Interest Rate: " + getAnnualInterestRate()
		+ "\n Current Balance: " + getBalance()
		+ "\n Monthly Interest: " + getMonthlyInterest();
	}
}
