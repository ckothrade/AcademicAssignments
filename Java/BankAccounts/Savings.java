/**
 * Extends the Account class to better suit a Savings Account.
 * @author Kothrade, Cal
 *
 */
public class Savings extends Account {

	/**
	 * Default Constructor for Savings Class, calls super.
	 */
	public Savings() {
		super();
	}
	
	/**
	 * Constructor for Savings, takes 3 parameters, calls super.
	 * @param id sets AccountId
	 * @param bal sets Account Balance
	 * @param ann sets Account Annual Interest Rate
	 */
	public Savings(int id, double bal, double ann){
		super(id, bal, ann);
	}
	
	/**
	 * Makes a withdrawal from Savings. Overrides Account method.
	 * @param val value requested to be withdrawn
	 */
	@Override
	public void withdraw(double val){
		double temp = 0;
		
		// If the value to be withdrawn is greater than the current balance
		//an error message is displayed and the withdrawal is canceled.
		if(val > getBalance())
			System.out.println("Error: Insufficient Funds!");
		else{
			temp = getBalance() - val;
			setBalance(temp);  //sets new balance after withdrawal
		}	
	}
	
	/**
	 * Returns a string displaying account information. 
	 * Overrides Account method.
	 */
	@Override
	public String toString(){
		return "ACCOUNT TYPE: _Savings"
		+ "\nAccount ID: " + getAccountId() + "   "
		+ "***Date Originated:  " + getDateCreated()  + " ***"
		+ "\n Annual Interest Rate: " + getAnnualInterestRate()
		+ "\n Current Balance: " + getBalance()
		+ "\n Monthly Interest: " + getMonthlyInterest();
	}

}
