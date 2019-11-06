
public class BaseDeque {

    /**
     * Program entry point for deque. 
     * @param args command line arguments
     */    
    public static void main(String[] args) {
        KothradeDeque<Integer> deque = new KothradeDeque<>();

        //standard queue behavior
        deque.enqueueBack(3);
        deque.enqueueBack(7);
        deque.enqueueBack(4);
        deque.dequeueFront();        
        deque.enqueueBack(9);
        deque.enqueueBack(8);
        deque.dequeueFront();
        System.out.println("size: " + deque.size());
        System.out.println("contents:\n" + deque.toString());   

        //deque features
        System.out.println(deque.dequeueFront());        
        deque.enqueueFront(1);
        deque.enqueueFront(11);                         
        deque.enqueueFront(3);                 
        deque.enqueueFront(5);         
        System.out.println(deque.dequeueBack());
        System.out.println(deque.dequeueBack());        
        System.out.println(deque.last());                
        deque.dequeueFront();
        deque.dequeueFront();        
        System.out.println(deque.first());        
        System.out.println("size: " + deque.size());
        System.out.println("contents:\n" + deque.toString());       
        
        //My Tests
        testRun();
    }
    
    /**
     * Tests different methods of the Deque Class.
     */
    public static void testRun(){
    	
    	System.out.println();
    	System.out.println("-----Testing Here-----");
    	
    	//Creates Integer double ended queue
    	KothradeDeque <Integer> dequeTest = new KothradeDeque<>();
    	
    	//Prints 0 (current size of Deque)
    	System.out.println(dequeTest.size());
    	
    	//Prints that the deque is empty
    	if(dequeTest.isEmpty())
    		System.out.println("Deque Is Empty!");
    	
    	//dequeTest.last();   //Throws NoSuchElementException
    	
    	//Places first integer into the back of the deque
    	dequeTest.enqueueBack(9);
    	
    	//Does not print because the deque is not empty
    	if(dequeTest.isEmpty())
    		System.out.println("This Should not print!");
    	
    	//Will print the same element twice, since there is only one element
    	System.out.println(dequeTest.first());
    	System.out.println(dequeTest.last());
    	
    	//Places a new element in the front
    	dequeTest.enqueueFront(5);
    	
    	//Prints the integer 5 first, and then the integer 9
    	System.out.println(dequeTest.first());
    	System.out.println(dequeTest.last());
    	
    	//Creates new string deque
    	KothradeDeque <String> dequeStr = new KothradeDeque<>();
    	
    	//Print 0 because the deque is empty
    	System.out.println(dequeStr.size());
    	
    	//Adds two strings to the deque
    	dequeStr.enqueueFront("Hello");
    	dequeStr.enqueueBack("There");
    	
    	//Prints the deque elements because the deque is not empty
    	if(!dequeStr.isEmpty())
    		System.out.println(dequeStr);
    	
    }
}
